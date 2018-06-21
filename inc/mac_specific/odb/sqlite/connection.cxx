// file      : odb/sqlite/connection.cxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <new>    // std::bad_alloc
#include <string>
#include <cassert>

#include <odb/details/lock.hxx>

#include <odb/sqlite/database.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/prepared-query.hxx>
#include <odb/sqlite/error.hxx>
#include <odb/sqlite/exceptions.hxx> // deadlock

#include <odb/sqlite/details/config.hxx> // LIBODB_SQLITE_HAVE_UNLOCK_NOTIFY

using namespace std;

extern "C" void
odb_sqlite_connection_unlock_callback (void**, int);

namespace odb
{
  namespace sqlite
  {
    connection::
    connection (database_type& db, int extra_flags)
        : odb::connection (db),
          db_ (db),
          unlock_cond_ (unlock_mutex_),
          statements_ (0)
    {
      int f (db.flags () | extra_flags);
      const string& n (db.name ());

      // If we are opening a temporary database, then add the create flag.
      //
      if (n.empty () || n == ":memory:")
        f |= SQLITE_OPEN_CREATE;

      // A connection can only be used by a single thread at a time. So
      // disable locking in SQLite unless explicitly requested.
      //
#if defined(SQLITE_OPEN_NOMUTEX)
      if ((f & SQLITE_OPEN_FULLMUTEX) == 0)
        f |= SQLITE_OPEN_NOMUTEX;
#endif

      sqlite3* h (0);

      // sqlite3_open_v2() was only addedin SQLite 3.5.0.
      //
#if SQLITE_VERSION_NUMBER >= 3005000
      const string& vfs (db.vfs ());
      int e (
        sqlite3_open_v2 (
          n.c_str (), &h, f, (vfs.empty () ? 0 : vfs.c_str ())));
#else
      // Readonly opening not supported in SQLite earlier than 3.5.0.
      //
      assert ((f & SQLITE_OPEN_READONLY) == 0);
      int e (sqlite3_open (n.c_str (), &h));
#endif

      handle_.reset (h);

      if (e != SQLITE_OK)
      {
        if (handle_ == 0)
          throw bad_alloc ();

        translate_error (e, *this);
      }

      init ();
    }

    connection::
    connection (database_type& db, sqlite3* handle)
        : odb::connection (db),
          db_ (db),
          handle_ (handle),
          unlock_cond_ (unlock_mutex_),
          statements_ (0)
    {
      init ();
    }

    void connection::
    init ()
    {
      // Enable/disable foreign key constraints.
      //
      generic_statement st (
        *this,
        db_.foreign_keys ()
        ? "PRAGMA foreign_keys=ON"
        : "PRAGMA foreign_keys=OFF",
        db_.foreign_keys () ? 22 : 23);
      st.execute ();

      // Create statement cache.
      //
      statement_cache_.reset (new statement_cache_type (*this));
    }

    connection::
    ~connection ()
    {
      // Destroy prepared query statements before freeing the connections.
      //
      recycle ();
      clear_prepared_map ();
    }

    transaction_impl* connection::
    begin ()
    {
      return new transaction_impl (
        connection_ptr (inc_ref (this)), transaction_impl::deferred);
    }

    transaction_impl* connection::
    begin_immediate ()
    {
      return new transaction_impl (
        connection_ptr (inc_ref (this)), transaction_impl::immediate);
    }

    transaction_impl* connection::
    begin_exclusive ()
    {
      return new transaction_impl (
        connection_ptr (inc_ref (this)), transaction_impl::exclusive);
    }

    unsigned long long connection::
    execute (const char* s, std::size_t n)
    {
      generic_statement st (*this, s, n);
      return st.execute ();
    }

    inline void
    connection_unlock_callback (void** args, int n)
    {
      for (int i (0); i < n; ++i)
      {
        connection* c (static_cast<connection*> (args[i]));
        details::lock l (c->unlock_mutex_);
        c->unlocked_ = true;
        c->unlock_cond_.signal ();
      }
    }

    void connection::
    wait ()
    {
#ifdef LIBODB_SQLITE_HAVE_UNLOCK_NOTIFY
      unlocked_ = false;

      // unlock_notify() returns SQLITE_OK or SQLITE_LOCKED (deadlock).
      //
      int e (sqlite3_unlock_notify (handle_,
                                    &odb_sqlite_connection_unlock_callback,
                                    this));
      if (e == SQLITE_LOCKED)
        throw deadlock ();

      details::lock l (unlock_mutex_);

      while (!unlocked_)
        unlock_cond_.wait ();
#else
      translate_error (SQLITE_LOCKED, *this);
#endif
    }

    void connection::
    clear ()
    {
      // The current first statement will remove itself from the list
      // and make the second statement (if any) the new first.
      //
      while (statements_ != 0)
        statements_->reset ();
    }
  }
}

extern "C" void
odb_sqlite_connection_unlock_callback (void** args, int n)
{
  odb::sqlite::connection_unlock_callback (args, n);
}
