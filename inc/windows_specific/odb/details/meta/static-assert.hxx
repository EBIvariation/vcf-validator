// file      : odb/details/meta/static-assert.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_STATIC_ASSERT_HXX
#define ODB_DETAILS_META_STATIC_ASSERT_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11

#ifndef ODB_CXX11

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <bool>
      struct static_assert_test;

      template <>
      struct static_assert_test<true> {};
    }
  }
}

#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_STATIC_ASSERT_HXX
