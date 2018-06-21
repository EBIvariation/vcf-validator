// file      : odb/connection.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  template <typename T, database_id DB>
  struct connection::query_<T, DB, class_object>
  {
    template <typename Q>
    static prepared_query<T>
    call (connection& c, const char* n, const Q& q)
    {
      // C++ compiler complaining there is no prepare_query()? Perhaps
      // you forgot to specify --generate-prepared when compiling your
      // persistent classes.
      //
      return prepared_query<T> (
        object_traits_impl<T, DB>::prepare_query (c, n, q));
    }
  };

  template <typename T, database_id DB>
  struct connection::query_<T, DB, class_view>
  {
    template <typename Q>
    static prepared_query<T>
    call (connection& c, const char* n, const Q& q)
    {
      // C++ compiler complaining there is no prepare_query()? Perhaps
      // you forgot to specify --generate-prepared when compiling your
      // views.
      //
      return prepared_query<T> (
        view_traits_impl<T, DB>::prepare_query (c, n, q));
    }
  };

  template <typename P>
  void connection::
  params_deleter (void* p)
  {
    delete static_cast<P*> (p);
  }
}
