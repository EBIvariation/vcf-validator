// file      : odb/details/win32/once.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/windows.hxx>
#include <odb/details/win32/once.hxx>
#include <odb/details/win32/once-init.hxx>

namespace odb
{
  namespace details
  {
    CRITICAL_SECTION win32_once_cs_;

    void
    once_process_start ()
    {
      InitializeCriticalSection (&win32_once_cs_);
    }

    void
    once_process_end (bool)
    {
      DeleteCriticalSection (&win32_once_cs_);
    }
  }
}
