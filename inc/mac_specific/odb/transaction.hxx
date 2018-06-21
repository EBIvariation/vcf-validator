// file      : odb/transaction.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRANSACTION_HXX
#define ODB_TRANSACTION_HXX

#include <odb/pre.hxx>

#include <vector>
#include <cstddef> // std::size_t

#include <odb/forward.hxx>

#include <odb/details/export.hxx>
#include <odb/details/unique-ptr.hxx>

namespace odb
{
  class transaction_impl;

  class LIBODB_EXPORT transaction
  {
  public:
    typedef odb::database database_type;
    typedef odb::connection connection_type;

    // If the second argument is false, then this transaction is not made
    // the current transaction of the thread.
    //
    explicit
    transaction (transaction_impl*, bool make_current = true);

    // Create a finalized transaction instance which can later be initialized
    // with reset().
    //
    transaction ();

    // Unless the transaction has already been finalized (explicitly
    // committed or rolled back), the destructor will roll it back.
    //
    ~transaction ();

    // Unless the current transaction has already been finalized (explicitly
    // committed or rolled back), reset will roll it back. If the second
    // argument is false, then this transaction is not made the current
    // transaction of the thread.
    //
    void
    reset (transaction_impl*, bool make_current = true);

    void
    commit ();

    void
    rollback ();

    // Return the database this transaction is on.
    //
    database_type&
    database ();

    // Return the connection this transaction is on.
    //
    connection_type&
    connection ();

    bool
    finalized () const {return finalized_;}

  public:
    // Return true if there is a transaction in effect.
    //
    static bool
    has_current ();

    // Return current transaction or throw if there is no transaction
    // in effect.
    //
    static transaction&
    current ();

    // Set the current thread's transaction.
    //
    static void
    current (transaction&);

    // Revert to the no transaction in effect state for the current thread.
    //
    static void
    reset_current ();

    // SQL statement tracing.
    //
  public:
    typedef odb::tracer tracer_type;

    void
    tracer (tracer_type&);

    void
    tracer (tracer_type*);

    tracer_type*
    tracer () const;

    // Post-commit/rollback callbacks.
    //
  public:
    static const unsigned short event_commit = 0x01;
    static const unsigned short event_rollback = 0x02;
    static const unsigned short event_all = event_commit | event_rollback;

    typedef void (*callback_type) (
      unsigned short event, void* key, unsigned long long data);

    // Register a post-commit/rollback callback. The data argument
    // can be used to store any user data that does not exceed 8
    // bytes and doesn't require alignment greater than unsigned
    // long long, such as an old value that needs to be restored
    // in case of a rollback.
    //
    // The state argument can be used to indicate to the caller
    // that the callback has been unregistered because the
    // transaction has terminated. In this case the transaction
    // resets the passed pointer to 0.
    //
    // Note that the order in which the callbacks are called is
    // unspecified.
    //
    void
    callback_register (callback_type,
                       void* key,
                       unsigned short event = event_all,
                       unsigned long long data = 0,
                       transaction** state = 0);

    // Unregister a post-commit/rollback callback. Note that this is a
    // potentially slow operation. You also don't need to unregister
    // a callback that has been called or auto-reset using the state
    // argument passed to register(). This function does nothing if
    // the key is not found.
    //
    void
    callback_unregister (void* key);

    // Update the event, data, and state values for a callback. Note
    // that just like unregister(), this is a potentially slow operation.
    //
    void
    callback_update (void* key,
                     unsigned short event,
                     unsigned long long data = 0,
                     transaction** state = 0);

  public:
    transaction_impl&
    implementation ();

    // Copying or assignment of transactions is not supported.
    //
  private:
    transaction (const transaction&);
    transaction& operator= (const transaction&);

  protected:
    friend struct rollback_guard;

    std::size_t
    callback_find (void* key);

    void
    callback_call (unsigned short event);

  protected:
    bool finalized_;
    details::unique_ptr<transaction_impl> impl_;

    // Callbacks.
    //
    struct callback_data
    {
      unsigned short event;
      callback_type func;
      void* key;
      unsigned long long data;
      transaction** state;
    };

    // Slots for the first 20 callback are pre-allocated on the stack.
    // For the rest they are allocated dynamically as needed.
    //
    // Note, if you change stack_callback_count, make sure you also
    // update the common/transaction/callback test accordingly.
    //
    static const std::size_t stack_callback_count = 20;
    static const std::size_t max_callback_count = ~(std::size_t (0));

    callback_data stack_callbacks_[stack_callback_count];
    std::vector<callback_data> dyn_callbacks_;

    // When a callback is unregistered, the free slot from the stack is
    // added to the linked list of free slots which is organized by
    // re-using the key data member to store the slot's index (we cannot
    // store a pointer because std::vector may move slots on expansion).
    // The value equal to max_callback_count indicates no free slots are
    // available.
    //
    std::size_t free_callback_;

    // Total number of used slots, both registered and in the free list.
    //
    std::size_t callback_count_;
  };

  class LIBODB_EXPORT transaction_impl
  {
  public:
    typedef odb::database database_type;
    typedef odb::connection connection_type;

    virtual
    ~transaction_impl ();

    virtual void
    start () = 0;

    virtual void
    commit () = 0;

    virtual void
    rollback () = 0;

    database_type&
    database ()
    {
      return database_;
    }

    connection_type&
    connection ()
    {
      return *connection_;
    }

  protected:
    transaction_impl (database_type& db)
        : database_ (db), connection_ (0)
    {
    }

    transaction_impl (database_type& db, connection_type& c)
        : database_ (db), connection_ (&c)
    {
    }

  protected:
    database_type& database_;
    connection_type* connection_;
  };
}

#include <odb/transaction.ixx>

#include <odb/post.hxx>

#endif // ODB_TRANSACTION_HXX
