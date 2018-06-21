// file      : odb/query.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_QUERY_HXX
#define ODB_QUERY_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>
#include <odb/traits.hxx>

namespace odb
{
  // Table alias for type T and tag Tag.
  //
  // The alias_traits interface consists of two things: the table_name
  // static variable containing the name and, in case of a derived type
  // in a polymorphic hierarchy, the base_traits typedef. Note that the
  // same interface is exposed by object_traits, which is used when
  // we need straight tables instead of aliases.
  //
  //
  template <typename T, database_id DB, typename Tag>
  struct alias_traits;

  template <typename T, database_id DB>
  struct query_columns_base;

  template <typename T, database_id DB, typename A>
  struct query_columns;

  template <typename T, database_id DB, typename A>
  struct pointer_query_columns;

  // Object pointer syntax wrapper.
  //
  template <typename T>
  struct query_pointer
  {
    query_pointer ()
    {
      // For some reason GCC needs this dummy c-tor if we make a static
      // data member of this type const.
    }

    T*
    operator-> () const
    {
      return 0; // All members in T are static.
    }
  };

  // Query parameter decay traits.
  //
  template <typename T>
  struct decay_traits
  {
    typedef const T& type;

    static type
    instance ();
  };

  template <typename T, std::size_t N>
  struct decay_traits<T[N]>
  {
    typedef const T* type;

    // Use the pointer comparability as a proxy for data comparability.
    // Note that it is stricter than using element comparability (i.e.,
    // one can compare int to char but not int* to char*).
    //
    static type
    instance ();
  };

  // VC9 cannot handle certain cases of non-type arguments with default
  // values in template functions (e.g., database::query()). As a result,
  // we have to use the impl trick below instead of simply having kind
  // as a second template argument with a default value.
  //
  template <typename T, database_id DB, class_kind kind>
  struct query_selector_impl;

  template <typename T, database_id DB>
  struct query_selector_impl<T, DB, class_object>
  {
    typedef typename object_traits_impl<T, DB>::query_base_type base_type;

    typedef
    query_columns<T, DB, access::object_traits_impl<T, DB> >
    columns_type;
  };

  template <typename T, database_id DB>
  struct query_selector_impl<T, DB, class_view>
  {
    typedef typename view_traits_impl<T, DB>::query_base_type base_type;
    typedef typename view_traits_impl<T, DB>::query_columns columns_type;
  };

  template <typename T, database_id DB>
  struct query_selector: query_selector_impl<T, DB, class_traits<T>::kind>
  {
  };

  template <typename T,
            typename B = typename query_selector<T, id_common>::base_type>
  class query;

  namespace core
  {
    using odb::query;
  }
}

#include <odb/post.hxx>

#endif // ODB_QUERY_HXX
