// file      : odb/sqlite/transaction-impl.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <sqlite3.h>

#include <odb/sqlite/database.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/transaction-impl.hxx>

namespace odb
{
  namespace sqlite
  {
    transaction_impl::
    transaction_impl (database_type& db, lock l)
        : odb::transaction_impl (db), lock_ (l)
    {
    }

    transaction_impl::
    transaction_impl (connection_ptr c, lock l)
        : odb::transaction_impl (c->database (), *c),
          connection_ (c),
          lock_ (l)
    {
    }

    transaction_impl::
    ~transaction_impl ()
    {
    }

    void transaction_impl::
    start ()
    {
      // Grab a connection if we don't already have one.
      //
      if (connection_ == 0)
      {
        connection_ = static_cast<database_type&> (database_).connection ();
        odb::transaction_impl::connection_ = connection_.get ();
      }

      statement_cache& sc (connection_->statement_cache ());

      switch (lock_)
      {
      case deferred:
        {
          sc.begin_statement ().execute ();
          break;
        }
      case immediate:
        {
          sc.begin_immediate_statement ().execute ();
          break;
        }
      case exclusive:
        {
          sc.begin_exclusive_statement ().execute ();
          break;
        }
      }
    }

    // In SQLite, when a commit fails (e.g., because of the deferred
    // foreign key constraint violation), the transaction may not
    // be automatically rolled back. So we have to do it ourselves.
    //
    struct commit_guard
    {
      commit_guard (connection& c): c_ (&c) {}
      void release () {c_ = 0;}

      ~commit_guard ()
      {
        if (c_ != 0 && sqlite3_get_autocommit (c_->handle ()) == 0)
        {
          // This is happening while another exception is active.
          //
          try
          {
            c_->statement_cache ().rollback_statement ().execute ();
          }
          catch (...) {}
        }
      }

    private:
      connection* c_;
    };

    void transaction_impl::
    commit ()
    {
      // Invalidate query results.
      //
      connection_->invalidate_results ();

      // Reset active statements. Active statements will prevent COMMIT
      // from completing (write statements) or releasing the locks (read
      // statements). Normally, a statement is automatically reset on
      // completion, however, if an exception is thrown, that may not
      // happen.
      //
      connection_->clear ();

      {
        commit_guard cg (*connection_);
        connection_->statement_cache ().commit_statement ().execute ();
        cg.release ();
      }

      // Release the connection.
      //
      connection_.reset ();
    }

    void transaction_impl::
    rollback ()
    {
      // Invalidate query results.
      //
      connection_->invalidate_results ();

      // Reset active statements. Active statements will prevent ROLLBACK
      // from completing (write statements) or releasing the locks (read
      // statements). Normally, a statement is automatically reset on
      // completion, however, if an exception is thrown, that may not
      // happen.
      //
      connection_->clear ();

      connection_->statement_cache ().rollback_statement ().execute ();

      // Release the connection.
      //
      connection_.reset ();
    }
  }
}
