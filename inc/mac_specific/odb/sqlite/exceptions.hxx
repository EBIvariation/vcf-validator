// file      : odb/sqlite/exceptions.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_EXCEPTIONS_HXX
#define ODB_SQLITE_EXCEPTIONS_HXX

#include <odb/pre.hxx>

#include <string>

#include <odb/exceptions.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    // This exception is thrown if SQLite is forcing the current transaction
    // to rollback. This can happen in SQLite 3.7.11 or later if one of the
    // connections participating in the shared cache rolls back a transaction.
    // See the SQLITE_ABORT_ROLLBACK extended error code for detail on this
    // behavior.
    //
    struct LIBODB_SQLITE_EXPORT forced_rollback: recoverable
    {
      virtual const char*
      what () const throw ();

      virtual forced_rollback*
      clone () const;
    };

    struct LIBODB_SQLITE_EXPORT database_exception: odb::database_exception
    {
      database_exception (int error,
                          int extended_error,
                          const std::string& message);

      ~database_exception () throw ();

      int
      error () const
      {
        return error_;
      }

      int
      extended_error () const
      {
        return extended_error_;
      }

      const std::string&
      message () const
      {
        return message_;
      }

      virtual const char*
      what () const throw ();

      virtual database_exception*
      clone () const;

    private:
      int error_;
      int extended_error_;
      std::string message_;
      std::string what_;
    };

    struct LIBODB_SQLITE_EXPORT cli_exception: odb::exception
    {
      cli_exception (const std::string& what);
      ~cli_exception () throw ();

      virtual const char*
      what () const throw ();

      virtual cli_exception*
      clone () const;

    private:
      std::string what_;
    };

    namespace core
    {
      using sqlite::database_exception;
      using sqlite::cli_exception;
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_EXCEPTIONS_HXX
