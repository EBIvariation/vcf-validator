// file      : odb/details/win32/exceptions.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/exceptions.hxx>

namespace odb
{
  namespace details
  {
    const char* win32_exception::
    what () const throw ()
    {
      return "Win32 API error";
    }

    win32_exception* win32_exception::
    clone () const
    {
      return new win32_exception (*this);
    }
  }
}
