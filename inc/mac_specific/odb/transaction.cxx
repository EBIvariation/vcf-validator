// file      : odb/transaction.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/transaction.hxx>
#include <odb/exceptions.hxx>

#include <odb/details/tls.hxx>

using namespace std;

namespace odb
{
  using namespace details;

  //
  // transaction
  //

  static ODB_TLS_POINTER (transaction) current_transaction;

  transaction::
  ~transaction ()
  {
    if (!finalized_)
      try {rollback ();} catch (...) {}
  }

  void transaction::
  reset (transaction_impl* impl, bool make_current)
  {
    details::unique_ptr<transaction_impl> i (impl);

    if (!finalized_)
      rollback ();

    impl_.reset (i.release ());

    if (make_current && tls_get (current_transaction) != 0)
      throw already_in_transaction ();

    impl_->start ();
    finalized_ = false;

    if (make_current)
      tls_set (current_transaction, this);
  }

  bool transaction::
  has_current ()
  {
    return tls_get (current_transaction) != 0;
  }

  transaction& transaction::
  current ()
  {
    transaction* cur (tls_get (current_transaction));

    if (cur == 0)
      throw not_in_transaction ();

    return *cur;
  }

  void transaction::
  current (transaction& t)
  {
    tls_set (current_transaction, &t);
  }

  void transaction::
  reset_current ()
  {
    transaction* t (0);
    tls_set (current_transaction, t);
  }

  struct rollback_guard
  {
    rollback_guard (transaction& t): t_ (&t) {}
    ~rollback_guard ()
    {if (t_ != 0) t_->callback_call (transaction::event_rollback);}
    void release () {t_ = 0;}
  private:
    transaction* t_;
  };

  void transaction::
  commit ()
  {
    if (finalized_)
      throw transaction_already_finalized ();

    finalized_ = true;
    rollback_guard rg (*this);

    impl_->connection ().transaction_tracer_ = 0;

    if (tls_get (current_transaction) == this)
    {
      transaction* t (0);
      tls_set (current_transaction, t);
    }

    impl_->commit ();
    rg.release ();

    if (callback_count_ != 0)
      callback_call (event_commit);
  }

  void transaction::
  rollback ()
  {
    if (finalized_)
      throw transaction_already_finalized ();

    finalized_ = true;
    rollback_guard rg (*this);

    impl_->connection ().transaction_tracer_ = 0;

    if (tls_get (current_transaction) == this)
    {
      transaction* t (0);
      tls_set (current_transaction, t);
    }

    impl_->rollback ();
    rg.release ();

    if (callback_count_ != 0)
      callback_call (event_rollback);
  }

  void transaction::
  callback_call (unsigned short event)
  {
    size_t stack_count (callback_count_ < stack_callback_count
                        ? callback_count_ : stack_callback_count);
    size_t dyn_count (callback_count_ - stack_count);

    // We need to be careful with the situation where a callback
    // throws and we neither call the rest of the callbacks nor
    // reset their states. To make sure this doesn't happen, we
    // do a first pass and reset all the states.
    //
    for (size_t i (0); i < stack_count; ++i)
    {
      callback_data& d (stack_callbacks_[i]);
      if (d.event != 0 && d.state != 0)
        *d.state = 0;
    }

    for (size_t i (0); i < dyn_count; ++i)
    {
      callback_data& d (dyn_callbacks_[i]);
      if (d.event != 0 && d.state != 0)
        *d.state = 0;
    }

    // Now do the actual calls.
    //
    for (size_t i (0); i < stack_count; ++i)
    {
      callback_data& d (stack_callbacks_[i]);
      if (d.event & event)
        d.func (event, d.key, d.data);
    }

    for (size_t i (0); i < dyn_count; ++i)
    {
      callback_data& d (dyn_callbacks_[i]);
      if (d.event & event)
        d.func (event, d.key, d.data);
    }

    // Clean things up in case this instance is going to be reused.
    //
    if (dyn_count != 0)
      dyn_callbacks_.clear ();

    free_callback_ = max_callback_count;
    callback_count_ = 0;
  }

  void transaction::
  callback_register (callback_type func,
                     void* key,
                     unsigned short event,
                     unsigned long long data,
                     transaction** state)
  {
    callback_data* s;

    // If we have a free slot, use it.
    //
    if (free_callback_ != max_callback_count)
    {
      s = (free_callback_ < stack_callback_count)
        ? stack_callbacks_ + free_callback_
        : &dyn_callbacks_[free_callback_ - stack_callback_count];

      free_callback_ = reinterpret_cast<size_t> (s->key);
    }
    // If we have space in the stack, grab that.
    //
    else if (callback_count_ < stack_callback_count)
    {
      s = stack_callbacks_ + callback_count_;
      callback_count_++;
    }
    // Otherwise use the dynamic storage.
    //
    else
    {
      dyn_callbacks_.push_back (callback_data ());
      s = &dyn_callbacks_.back ();
      callback_count_++;
    }

    s->func = func;
    s->key = key;
    s->event = event;
    s->data = data;
    s->state = state;
  }

  size_t transaction::
  callback_find (void* key)
  {
    if (callback_count_ == 0)
      return 0;

    size_t stack_count;

    // See if this is the last slot registered. This will be a fast path if,
    // for example, things are going to be unregistered from destructors.
    //
    if (callback_count_ <= stack_callback_count)
    {
      if (stack_callbacks_[callback_count_ - 1].key == key)
        return callback_count_ - 1;

      stack_count = callback_count_;
    }
    else
    {
      if (dyn_callbacks_.back ().key == key)
        return callback_count_ - 1;

      stack_count = stack_callback_count;
    }

    // Otherwise do a linear search.
    //
    for (size_t i (0); i < stack_count; ++i)
      if (stack_callbacks_[i].key == key)
        return i;

    for (size_t i (0), dyn_count (callback_count_ - stack_count);
         i < dyn_count; ++i)
      if (dyn_callbacks_[i].key == key)
        return i + stack_callback_count;

    return callback_count_;
  }

  void transaction::
  callback_unregister (void* key)
  {
    size_t i (callback_find (key));

    // It is ok for this function not to find the key.
    //
    if (i == callback_count_)
      return;

    // See if this is the last slot registered.
    //
    if (i == callback_count_ - 1)
    {
      if (i >= stack_callback_count)
        dyn_callbacks_.pop_back ();

      callback_count_--;
    }
    else
    {
      callback_data& d (
        i < stack_callback_count
        ? stack_callbacks_[i]
        : dyn_callbacks_[i - stack_callback_count]);

      // Add to the free list.
      //
      d.event = 0;
      d.key = reinterpret_cast<void*> (free_callback_);
      free_callback_ = i;
    }
  }

  void transaction::
  callback_update (void* key,
                   unsigned short event,
                   unsigned long long data,
                   transaction** state)
  {
    size_t i (callback_find (key));

    // It is ok for this function not to find the key.
    //
    if (i == callback_count_)
      return;

    callback_data& d (
      i < stack_callback_count
      ? stack_callbacks_[i]
      : dyn_callbacks_[i - stack_callback_count]);

    d.event = event;
    d.data = data;
    d.state = state;
  }

  //
  // transaction_impl
  //

  transaction_impl::
  ~transaction_impl ()
  {
  }
}
