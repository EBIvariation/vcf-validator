// file      : odb/details/type-info.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_TYPE_INFO_HXX
#define ODB_DETAILS_TYPE_INFO_HXX

#include <odb/pre.hxx>

#include <typeinfo>

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT type_info_comparator
    {
      bool
      operator() (const std::type_info* x, const std::type_info* y) const
      {
        // XL C++ on AIX has buggy type_info::before() in that
        // it returns true for two different type_info objects
        // that happened to be for the same type.
        //
#if defined(__xlC__) && defined(_AIX)
        return *x != *y && x->before (*y);
#else
        return x->before (*y);
#endif
      }
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_TYPE_INFO_HXX
