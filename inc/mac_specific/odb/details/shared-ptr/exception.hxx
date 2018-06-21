// file      : odb/details/shared-ptr/exception.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX
#define ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX

#include <odb/pre.hxx>

#include <odb/exception.hxx>
#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT not_shared: exception
    {
      virtual const char*
      what () const throw ();

      virtual not_shared*
      clone () const;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX
