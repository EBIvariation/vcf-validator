// file      : odb/connection.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_CONNECTION_HXX
#define ODB_CONNECTION_HXX

#include <odb/pre.hxx>

#include <map>
#include <string>
#include <memory>   // std::auto_ptr, std::unique_ptr
#include <cstddef>  // std::size_t
#include <typeinfo>

#include <odb/forward.hxx>
#include <odb/traits.hxx>
#include <odb/query.hxx>
#include <odb/prepared-query.hxx>

#include <odb/details/config.hxx> // ODB_CXX11
#include <odb/details/export.hxx>
#include <odb/details/c-string.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  class transaction_impl;

  class connection;
  typedef details::shared_ptr<connection> connection_ptr;

  class LIBODB_EXPORT connection: public details::shared_base
  {
  public:
    typedef odb::database database_type;

    database_type&
    database ();

    // Transactions.
    //
  public:
    virtual transaction_impl*
    begin () = 0;

    // Native database statement execution. Note that unlike the
    // versions in the database class, these can be executed
    // without a transaction.
    //
  public:
    unsigned long long
    execute (const char* statement);

    unsigned long long
    execute (const std::string& statement);

    virtual unsigned long long
    execute (const char* statement, std::size_t length) = 0;

    // Query preparation.
    //
  public:
    template <typename T>
    prepared_query<T>
    prepare_query (const char* name, const char*);

    template <typename T>
    prepared_query<T>
    prepare_query (const char* name, const std::string&);

    template <typename T>
    prepared_query<T>
    prepare_query (const char* name, const query<T>&);

    template <typename T>
    void
    cache_query (const prepared_query<T>&);

    template <typename T, typename P>
    void
    cache_query (const prepared_query<T>&, std::auto_ptr<P> params);

#ifdef ODB_CXX11
    template <typename T, typename P>
    void
    cache_query (const prepared_query<T>&, std::unique_ptr<P> params);
#endif

    template <typename T>
    prepared_query<T>
    lookup_query (const char* name) const;

    template <typename T, typename P>
    prepared_query<T>
    lookup_query (const char* name, P*& params) const;

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

   public:
    // Store the transaction-spacific tracer in the connection. If we
    // were to store it in the transaction, then in order to check if
    // it was set, we would need to get the transaction instance using
    // the current() API. But that requires a TLS lookup, which can be
    // slow.
    //
    tracer_type*
    transaction_tracer () const;

  public:
    virtual
    ~connection ();

    // Recycle the connection to be used by another thread. This call
    // invalidates uncached prepared queries.
    //
    void
    recycle ();

  protected:
    connection (database_type&);

    template <typename T,
              database_id DB,
              class_kind kind = class_traits<T>::kind>
    struct query_;

    virtual void
    cache_query_ (prepared_query_impl* pq,
                  const std::type_info& ti,
                  void* params,
                  const std::type_info* params_info,
                  void (*params_deleter) (void*));

    prepared_query_impl*
    lookup_query_ (const char* name,
                   const std::type_info& ti,
                   void** params, // out
                   const std::type_info* params_info) const;

    template <typename P>
    static void
    params_deleter (void*);

  private:
    connection (const connection&);
    connection& operator= (const connection&);

    // Prepared query cache.
    //
  protected:
    struct prepared_entry_type
    {
      details::shared_ptr<prepared_query_impl> prep_query;
      const std::type_info* type_info;
      void* params;
      const std::type_info* params_info;
      void (*params_deleter) (void*);
    };

    typedef
    std::map<const char*, prepared_entry_type, details::c_string_comparator>
    prepared_map_type;

    prepared_map_type prepared_map_;

    void
    clear_prepared_map ();

  protected:
    database_type& database_;
    tracer_type* tracer_;

    // Active query result list.
    //
  protected:
    friend class result_impl;
    result_impl* results_;

    void
    invalidate_results ();

    // Prepared but uncached query list (cached ones are stored in
    // prepared_map_).
    //
  protected:
    friend class prepared_query_impl;
    prepared_query_impl* prepared_queries_;

  protected:
    friend class transaction;
    tracer_type* transaction_tracer_;
  };
}

#include <odb/connection.ixx>
#include <odb/connection.txx>

#include <odb/post.hxx>

#endif // ODB_CONNECTION_HXX
