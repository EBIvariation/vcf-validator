// file      : odb/details/posix/exceptions.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/posix/exceptions.hxx>

namespace odb
{
  namespace details
  {
    const char* posix_exception::
    what () const throw ()
    {
      return "POSIX API error";
    }

    posix_exception* posix_exception::
    clone () const
    {
      return new posix_exception (*this);
    }
  }
}
