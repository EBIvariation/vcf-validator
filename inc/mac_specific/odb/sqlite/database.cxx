// file      : odb/sqlite/database.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifdef _WIN32
#  include <odb/details/win32/windows.hxx> // WideCharToMultiByte
#endif

#include <sqlite3.h>

#include <cassert>
#include <sstream>

#include <odb/sqlite/database.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/connection-factory.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/error.hxx>
#include <odb/sqlite/exceptions.hxx>

#include <odb/sqlite/details/options.hxx>

using namespace std;

namespace odb
{
  namespace sqlite
  {
    using odb::details::transfer_ptr;

    database::
    ~database ()
    {
    }

    database::
    database (const string& name,
              int flags,
              bool foreign_keys,
              const string& vfs,
              transfer_ptr<connection_factory> factory)
        : odb::database (id_sqlite),
          name_ (name),
          flags_ (flags),
          foreign_keys_ (foreign_keys),
          vfs_ (vfs),
          factory_ (factory.transfer ())
    {
      if (!factory_)
        factory_.reset (new connection_pool_factory ());

      factory_->database (*this);
    }

#ifdef _WIN32
    database::
    database (const wstring& name,
              int flags,
              bool foreign_keys,
              const string& vfs,
              transfer_ptr<connection_factory> factory)
        : odb::database (id_sqlite),
          flags_ (flags),
          foreign_keys_ (foreign_keys),
          vfs_ (vfs),
          factory_ (factory.transfer ())
    {
      // Convert UTF-16 name to UTF-8 using the WideCharToMultiByte() Win32
      // function.
      //
      int n (
        WideCharToMultiByte (
          CP_UTF8,
          0,
          name.c_str (),
          static_cast<int> (name.size ()),
          0,
          0,
          0,
          0));

      if (n == 0)
        throw database_exception (
          SQLITE_CANTOPEN, SQLITE_CANTOPEN, "unable to open database file");

      // This string is not shared so we are going to modify the underlying
      // buffer directly.
      //
      name_.resize (static_cast<string::size_type> (n));

      n = WideCharToMultiByte (
        CP_UTF8,
        0,
        name.c_str (),
        static_cast<int> (name.size ()),
        const_cast<char*> (name_.c_str ()),
        n,
        0,
        0);

      if (n == 0)
        throw database_exception (
          SQLITE_CANTOPEN, SQLITE_CANTOPEN, "unable to open database file");

      if (!factory_)
        factory_.reset (new connection_pool_factory ());

      factory_->database (*this);
    }
#endif

    database::
    database (int& argc,
              char* argv[],
              bool erase,
              int flags,
              bool foreign_keys,
              const string& vfs,
              transfer_ptr<connection_factory> factory)
        : odb::database (id_sqlite),
          flags_ (flags),
          foreign_keys_ (foreign_keys),
          vfs_ (vfs),
          factory_ (factory.transfer ())
    {
      using namespace details;

      try
      {
        cli::argv_file_scanner scan (argc, argv, "--options-file", erase);
        options ops (scan, cli::unknown_mode::skip, cli::unknown_mode::skip);

        name_ = ops.database ();

        if (ops.create ())
          flags_ |= SQLITE_OPEN_CREATE;

        if (ops.read_only ())
          flags_ = (flags_ & ~SQLITE_OPEN_READWRITE) | SQLITE_OPEN_READONLY;
      }
      catch (const cli::exception& e)
      {
        ostringstream ostr;
        ostr << e;
        throw cli_exception (ostr.str ());
      }

      if (!factory_)
        factory_.reset (new connection_pool_factory ());

      factory_->database (*this);
    }

    void database::
    print_usage (std::ostream& os)
    {
      details::options::print_usage (os);
    }

    transaction_impl* database::
    begin ()
    {
      return new transaction_impl (*this, transaction_impl::deferred);
    }

    transaction_impl* database::
    begin_immediate ()
    {
      return new transaction_impl (*this, transaction_impl::immediate);
    }

    transaction_impl* database::
    begin_exclusive ()
    {
      return new transaction_impl (*this, transaction_impl::exclusive);
    }

    odb::connection* database::
    connection_ ()
    {
      connection_ptr c (factory_->connect ());
      return c.release ();
    }

    const database::schema_version_info& database::
    load_schema_version (const string& name) const
    {
      schema_version_info& svi (schema_version_map_[name]);

      // Construct the SELECT statement text.
      //
      string text ("SELECT \"version\", \"migration\" FROM ");

      if (!svi.version_table.empty ())
        text += svi.version_table; // Already quoted.
      else if (!schema_version_table_.empty ())
        text += schema_version_table_; // Already quoted.
      else
        text += "\"schema_version\"";

      text += " WHERE \"name\" = ?";

      // Bind parameters and results.
      //
      size_t psize[1] = {name.size ()};
      bind pbind[1] = {{bind::text,
                        const_cast<char*> (name.c_str ()),
                        &psize[0],
                        0, 0, 0}};
      binding param (pbind, 1);
      param.version++;

      long long migration;
      bool rnull[2];
      bind rbind[2] = {{bind::integer, &svi.version, 0, 0, &rnull[0], 0},
                       {bind::integer, &migration, 0, 0, &rnull[1], 0}};
      binding result (rbind, 2);
      result.version++;

      // If we are not in transaction, SQLite will start an implicit one
      // which suits us just fine.
      //
      connection_ptr cp;
      if (!transaction::has_current ())
        cp = factory_->connect ();

      sqlite::connection& c (
        cp != 0 ? *cp : transaction::current ().connection ());

      try
      {
        select_statement st (c,
                             text,
                             false, // Don't process.
                             false, // Don't optimize.
                             param,
                             result);
        st.execute ();
        auto_result ar (st);

        switch (st.fetch ())
        {
        case select_statement::success:
          {
            svi.migration = migration != 0;
            assert (st.fetch () == select_statement::no_data);
            break;
          }
        case select_statement::no_data:
          {
            svi.version = 0; // No schema.
            break;
          }
        case select_statement::truncated:
          {
            assert (false);
            break;
          }
        }
      }
      catch (const database_exception& e)
      {
        // Try to detect the case where there is no version table. SQLite
        // doesn't have an extended error code for this so we have to use
        // the error text.
        //
        if (e.error () == SQLITE_ERROR &&
            e.message ().compare (0, 14, "no such table:") == 0)
          svi.version = 0; // No schema.
        else
          throw;
      }

      return svi;
    }
  }
}
