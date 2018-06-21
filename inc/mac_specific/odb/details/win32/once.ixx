// file      : odb/details/win32/once.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/lock.hxx>

namespace odb
{
  namespace details
  {
    inline void
    win32_once (win32_once_t& o, void (*func) ())
    {
      win32_lock l (win32_once_cs_);

      if (o == 0)
      {
        o = 1;
        l.unlock ();
        func ();
      }
    }

    inline once::
    once ()
        : called_ (false)
    {
    }

    inline void once::
    call (void (*func) ())
    {
      win32_lock l (win32_once_cs_);

      if (!called_)
      {
        called_ = true;
        l.unlock ();
        func ();
      }
    }
  }
}
