// file      : odb/details/meta/remove-const.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_REMOVE_CONST_HXX
#define ODB_DETAILS_META_REMOVE_CONST_HXX

#include <odb/pre.hxx>

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename X>
      struct remove_const
      {
        typedef X result;
      };

      template <typename X>
      struct remove_const<const X>
      {
        typedef X result;
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_REMOVE_CONST_HXX
