// file      : odb/details/meta/remove-const-volatile.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX
#define ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX

#include <odb/pre.hxx>

#include <odb/details/meta/remove-const.hxx>
#include <odb/details/meta/remove-volatile.hxx>

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename X>
      struct remove_const_volatile
      {
        typedef
        typename remove_volatile<typename remove_const<X>::result>::result
        result;
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX
