// file      : odb/sqlite/database.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_DATABASE_HXX
#define ODB_SQLITE_DATABASE_HXX

#include <odb/pre.hxx>

#include <sqlite3.h>

#include <string>
#include <memory> // std::auto_ptr, std::unique_ptr
#include <iosfwd> // std::ostream

#include <odb/database.hxx>
#include <odb/details/unique-ptr.hxx>
#include <odb/details/transfer-ptr.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/sqlite/tracer.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/connection-factory.hxx>
#include <odb/sqlite/transaction-impl.hxx>

#include <odb/sqlite/details/export.hxx>

// We use the sqlite3_open_v2() flags in our interface. Define them
// for SQLite earlier that 3.5.0.
//
#if SQLITE_VERSION_NUMBER < 3005000
#  define SQLITE_OPEN_READONLY         0x00000001
#  define SQLITE_OPEN_READWRITE        0x00000002
#  define SQLITE_OPEN_CREATE           0x00000004
#endif

namespace odb
{
  namespace sqlite
  {
    class transaction_impl;

    class LIBODB_SQLITE_EXPORT database: public odb::database
    {
    public:
      database (const std::string& name,
                int flags = SQLITE_OPEN_READWRITE,
                bool foreign_keys = true,
                const std::string& vfs = "",
                details::transfer_ptr<connection_factory> =
                  details::transfer_ptr<connection_factory> ());

#ifdef _WIN32
      database (const std::wstring& name,
                int flags = SQLITE_OPEN_READWRITE,
                bool foreign_keys = true,
                const std::string& vfs = "",
                details::transfer_ptr<connection_factory> =
                  details::transfer_ptr<connection_factory> ());
#endif

      // Extract the database parameters from the command line. The
      // following options are recognized:
      //
      // --database
      // --create
      // --read-only
      // --options-file
      //
      // For more information, see the output of the print_usage() function
      // below. If erase is true, the above options are removed from the argv
      // array and the argc count is updated accordingly. The command line
      // options override the flags passed as an argument. This constructor
      // may throw the cli_exception exception.
      //
      database (int& argc,
                char* argv[],
                bool erase = false,
                int flags = SQLITE_OPEN_READWRITE,
                bool foreign_keys = true,
                const std::string& vfs = "",
                details::transfer_ptr<connection_factory> =
                  details::transfer_ptr<connection_factory> ());

      static void
      print_usage (std::ostream&);

    public:
      const std::string&
      name () const
      {
        return name_;
      }

      int
      flags () const
      {
        return flags_;
      }

      bool
      foreign_keys () const
      {
        return foreign_keys_;
      }

      const std::string&
      vfs () const
      {
        return vfs_;
      }

      // Object persistence API.
      //
    public:

      // Make the object persistent.
      //
      template <typename T>
      typename object_traits<T>::id_type
      persist (T& object);

      template <typename T>
      typename object_traits<T>::id_type
      persist (const T& object);

      template <typename T>
      typename object_traits<T>::id_type
      persist (T* obj_ptr);

      template <typename T, template <typename> class P>
      typename object_traits<T>::id_type
      persist (const P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      typename object_traits<T>::id_type
      persist (const P<T, A1>& obj_ptr);

      template <typename T, template <typename> class P>
      typename object_traits<T>::id_type
      persist (P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      typename object_traits<T>::id_type
      persist (P<T, A1>& obj_ptr);

      template <typename T>
      typename object_traits<T>::id_type
      persist (const typename object_traits<T>::pointer_type& obj_ptr);

      // Load an object. Throw object_not_persistent if not found.
      //
      template <typename T>
      typename object_traits<T>::pointer_type
      load (const typename object_traits<T>::id_type& id);

      template <typename T>
      void
      load (const typename object_traits<T>::id_type& id, T& object);

      // Load (or reload, if it is already loaded) a section of an object.
      //
      template <typename T>
      void
      load (T& object, section&);

      // Reload an object.
      //
      template <typename T>
      void
      reload (T& object);

      template <typename T>
      void
      reload (T* obj_ptr);

      template <typename T, template <typename> class P>
      void
      reload (const P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      reload (const P<T, A1>& obj_ptr);

      template <typename T, template <typename> class P>
      void
      reload (P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      reload (P<T, A1>& obj_ptr);

      template <typename T>
      void
      reload (const typename object_traits<T>::pointer_type& obj_ptr);

      // Loan an object if found. Return NULL/false if not found.
      //
      template <typename T>
      typename object_traits<T>::pointer_type
      find (const typename object_traits<T>::id_type& id);

      template <typename T>
      bool
      find (const typename object_traits<T>::id_type& id, T& object);

      // Update the state of a modified objects.
      //
      template <typename T>
      void
      update (T& object);

      template <typename T>
      void
      update (T* obj_ptr);

      template <typename T, template <typename> class P>
      void
      update (const P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      update (const P<T, A1>& obj_ptr);

      template <typename T, template <typename> class P>
      void
      update (P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      update (P<T, A1>& obj_ptr);

      template <typename T>
      void
      update (const typename object_traits<T>::pointer_type& obj_ptr);

      // Update a section of an object. Throws the section_not_loaded
      // exception if the section is not loaded. Note also that this
      // function does not clear the changed flag if it is set.
      //
      template <typename T>
      void
      update (const T& object, const section&);

      // Make the object transient. Throw object_not_persistent if not
      // found.
      //
      template <typename T>
      void
      erase (const typename object_traits<T>::id_type& id);

      template <typename T>
      void
      erase (T& object);

      template <typename T>
      void
      erase (T* obj_ptr);

      template <typename T, template <typename> class P>
      void
      erase (const P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      erase (const P<T, A1>& obj_ptr);

      template <typename T, template <typename> class P>
      void
      erase (P<T>& obj_ptr);

      template <typename T, typename A1, template <typename, typename> class P>
      void
      erase (P<T, A1>& obj_ptr);

      template <typename T>
      void
      erase (const typename object_traits<T>::pointer_type& obj_ptr);

      // Erase multiple objects matching a query predicate.
      //
      template <typename T>
      unsigned long long
      erase_query ();

      template <typename T>
      unsigned long long
      erase_query (const char*);

      template <typename T>
      unsigned long long
      erase_query (const std::string&);

      template <typename T>
      unsigned long long
      erase_query (const sqlite::query_base&);

      template <typename T>
      unsigned long long
      erase_query (const odb::query_base&);

      // Query API.
      //
      template <typename T>
      result<T>
      query ();

      template <typename T>
      result<T>
      query (const char*);

      template <typename T>
      result<T>
      query (const std::string&);

      template <typename T>
      result<T>
      query (const sqlite::query_base&);

      template <typename T>
      result<T>
      query (const odb::query_base&);

      // Query one API.
      //
      template <typename T>
      typename object_traits<T>::pointer_type
      query_one ();

      template <typename T>
      bool
      query_one (T& object);

      template <typename T>
      T
      query_value ();

      template <typename T>
      typename object_traits<T>::pointer_type
      query_one (const char*);

      template <typename T>
      bool
      query_one (const char*, T& object);

      template <typename T>
      T
      query_value (const char*);

      template <typename T>
      typename object_traits<T>::pointer_type
      query_one (const std::string&);

      template <typename T>
      bool
      query_one (const std::string&, T& object);

      template <typename T>
      T
      query_value (const std::string&);

      template <typename T>
      typename object_traits<T>::pointer_type
      query_one (const sqlite::query_base&);

      template <typename T>
      bool
      query_one (const sqlite::query_base&, T& object);

      template <typename T>
      T
      query_value (const sqlite::query_base&);

      template <typename T>
      typename object_traits<T>::pointer_type
      query_one (const odb::query_base&);

      template <typename T>
      bool
      query_one (const odb::query_base&, T& object);

      template <typename T>
      T
      query_value (const odb::query_base&);

      // Query preparation.
      //
      template <typename T>
      prepared_query<T>
      prepare_query (const char* name, const char*);

      template <typename T>
      prepared_query<T>
      prepare_query (const char* name, const std::string&);

      template <typename T>
      prepared_query<T>
      prepare_query (const char* name, const sqlite::query_base&);

      template <typename T>
      prepared_query<T>
      prepare_query (const char* name, const odb::query_base&);

      // Transactions.
      //
    public:
      virtual transaction_impl*
      begin ();

      transaction_impl*
      begin_immediate ();

      transaction_impl*
      begin_exclusive ();

    public:
      connection_ptr
      connection ();

      // SQL statement tracing.
      //
    public:
      typedef sqlite::tracer tracer_type;

      void
      tracer (tracer_type& t)
      {
        odb::database::tracer (t);
      }

      void
      tracer (tracer_type* t)
      {
        odb::database::tracer (t);
      }

      using odb::database::tracer;

      // Database schema version.
      //
    protected:
      virtual const schema_version_info&
      load_schema_version (const std::string& schema_name) const;

      // Database id constant (useful for meta-programming).
      //
    public:
      static const odb::database_id database_id = id_sqlite;

    public:
      virtual
      ~database ();

    protected:
      virtual odb::connection*
      connection_ ();

    private:
      std::string name_;
      int flags_;
      bool foreign_keys_;
      std::string vfs_;
      details::unique_ptr<connection_factory> factory_;
    };
  }
}

#include <odb/sqlite/database.ixx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_DATABASE_HXX
