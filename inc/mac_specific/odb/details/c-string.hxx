// file      : odb/details/c-string.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_C_STRING_HXX
#define ODB_DETAILS_C_STRING_HXX

#include <odb/pre.hxx>

#include <cstring>

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT c_string_comparator
    {
      bool
      operator() (const char* x, const char* y) const
      {
        return std::strcmp (x, y) < 0;
      }
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_C_STRING_HXX
