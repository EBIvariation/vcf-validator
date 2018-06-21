// file      : odb/details/exception.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_EXCEPTION_HXX
#define ODB_DETAILS_EXCEPTION_HXX

#include <odb/pre.hxx>

#include <odb/exception.hxx>

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT exception: odb::exception
    {
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_EXCEPTION_HXX
