// file      : odb/transaction.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/connection.hxx>

namespace odb
{
  inline transaction::
  transaction ()
      : finalized_ (true),
        impl_ (0),
        free_callback_ (max_callback_count),
        callback_count_ (0)
  {
  }

  inline transaction::
  transaction (transaction_impl* impl, bool make_current)
      : finalized_ (true),
        impl_ (0),
        free_callback_ (max_callback_count),
        callback_count_ (0)
  {
    reset (impl, make_current);
  }

  inline transaction::database_type& transaction::
  database ()
  {
    return impl_->database ();
  }

  inline transaction::connection_type& transaction::
  connection ()
  {
    return impl_->connection ();
  }

  inline transaction_impl& transaction::
  implementation ()
  {
    return *impl_;
  }

  // The transaction-specific tracer is stored in the connection. See
  // the connection class for the reason.
  //
  inline void transaction::
  tracer (tracer_type& t)
  {
    impl_->connection ().transaction_tracer_ = &t;
  }

  inline void transaction::
  tracer (tracer_type* t)
  {
    impl_->connection ().transaction_tracer_ = t;
  }

  inline transaction::tracer_type* transaction::
  tracer () const
  {
    return impl_->connection ().transaction_tracer_;
  }
}
