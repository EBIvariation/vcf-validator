// file      : odb/connection.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::string
#include <cassert>

namespace odb
{
  inline connection::
  connection (database_type& database)
      : database_ (database),
        tracer_ (0),
        results_ (0),
        prepared_queries_ (0),
        transaction_tracer_ (0)
  {
  }

  inline connection::database_type& connection::
  database ()
  {
    return database_;
  }

  inline unsigned long long connection::
  execute (const char* st)
  {
    return execute (st, std::strlen (st));
  }

  inline unsigned long long connection::
  execute (const std::string& st)
  {
    return execute (st.c_str (), st.size ());
  }

  template <typename T>
  inline prepared_query<T> connection::
  prepare_query (const char* n, const char* q)
  {
    return prepare_query<T> (n, query<T> (q));
  }

  template <typename T>
  inline prepared_query<T> connection::
  prepare_query (const char* n, const std::string& q)
  {
    return prepare_query<T> (n, query<T> (q));
  }

  template <typename T>
  inline prepared_query<T> connection::
  prepare_query (const char* n, const query<T>& q)
  {
    return query_<T, id_common>::call (*this, n, q);
  }

  template <typename T>
  inline void connection::
  cache_query (const prepared_query<T>& pq)
  {
    assert (pq);
    cache_query_ (pq.impl_, typeid (T), 0, 0, 0);
  }

  template <typename T, typename P>
  inline void connection::
  cache_query (const prepared_query<T>& pq, std::auto_ptr<P> params)
  {
    assert (pq);
    assert (params.get () != 0);
    cache_query_ (
      pq.impl_, typeid (T), params.get (), &typeid (P), &params_deleter<P>);
    params.release ();
  }

#ifdef ODB_CXX11
  template <typename T, typename P>
  inline void connection::
  cache_query (const prepared_query<T>& pq, std::unique_ptr<P> params)
  {
    assert (pq);
    assert (params);
    cache_query_ (
      pq.impl_, typeid (T), params.get (), &typeid (P), &params_deleter<P>);
    params.release ();
  }
#endif

  template <typename T>
  inline prepared_query<T> connection::
  lookup_query (const char* name) const
  {
    return prepared_query<T> (lookup_query_ (name, typeid (T), 0, 0));
  }

  template <typename T, typename P>
  inline prepared_query<T> connection::
  lookup_query (const char* name, P*& params) const
  {
    return prepared_query<T> (
      lookup_query_ (name,
               typeid (T),
               reinterpret_cast<void**> (&params),
               &typeid (P)));
  }

  inline void connection::
  tracer (tracer_type& t)
  {
    tracer_ = &t;
  }

  inline void connection::
  tracer (tracer_type* t)
  {
    tracer_ = t;
  }

  inline connection::tracer_type* connection::
  tracer () const
  {
    return tracer_;
  }

  inline connection::tracer_type* connection::
  transaction_tracer () const
  {
    return transaction_tracer_;
  }
}
