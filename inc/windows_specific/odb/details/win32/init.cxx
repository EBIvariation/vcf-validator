// file      : odb/details/win32/init.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/init.hxx>
#include <odb/details/win32/once-init.hxx>
#include <odb/details/win32/tls-init.hxx>

namespace odb
{
  namespace details
  {
    void
    process_start ()
    {
      // The order is important.
      //
      once_process_start ();
      tls_process_start ();
    }

    void
    process_end (bool safe)
    {
      // The order is important.
      //
      tls_process_end (safe);
      once_process_end (safe);
    }

    void
    thread_start ()
    {
    }

    void
    thread_end ()
    {
      tls_thread_end ();
    }
  }
}
