// file      : odb/details/win32/exceptions.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_EXCEPTIONS_HXX
#define ODB_DETAILS_WIN32_EXCEPTIONS_HXX

#include <odb/pre.hxx>

#include <odb/details/win32/windows.hxx>
#include <odb/details/export.hxx>
#include <odb/details/exception.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT win32_exception: details::exception
    {
      win32_exception () : code_ (GetLastError ()) {}
      win32_exception (DWORD code) : code_ (code) {}

      DWORD
      code () const {return code_;}

      virtual const char*
      what () const throw ();

      virtual win32_exception*
      clone () const;

    private:
      DWORD code_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_EXCEPTIONS_HXX
