// file      : odb/sqlite/transaction.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_TRANSACTION_HXX
#define ODB_SQLITE_TRANSACTION_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/tracer.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class transaction_impl;

    class LIBODB_SQLITE_EXPORT transaction: public odb::transaction
    {
    public:
      typedef sqlite::database database_type;
      typedef sqlite::connection connection_type;

      explicit
      transaction (transaction_impl*, bool make_current = true);

      transaction ();

      // Return the database this transaction is on.
      //
      database_type&
      database ();

      // Return the underlying database connection for this transaction.
      //
      connection_type&
      connection ();

      // Return current transaction or throw if there is no transaction
      // in effect.
      //
      static transaction&
      current ();

      // Set the current thread's transaction.
      //
      static void
      current (transaction&);

      // SQL statement tracing.
      //
    public:
      typedef sqlite::tracer tracer_type;

      void
      tracer (tracer_type& t)
      {
        odb::transaction::tracer (t);
      }

      void
      tracer (tracer_type* t)
      {
        odb::transaction::tracer (t);
      }

      using odb::transaction::tracer;

    public:
      transaction_impl&
      implementation ();
    };
  }
}

#include <odb/sqlite/transaction.ixx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_TRANSACTION_HXX
