// file      : odb/details/win32/once.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_ONCE_HXX
#define ODB_DETAILS_WIN32_ONCE_HXX

#include <odb/pre.hxx>

#include <odb/details/win32/windows.hxx>
#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT once
    {
    public:
      once ();

      void
      call (void (*func) ());

    private:
      once (const once&);
      once& operator= (const once&);

    private:
      bool called_;
    };

    // Low-level, POSIX-like API that can be used safely during static
    // initialization (that is, win32_once() can be called during static
    // initialization) provided once_process_start() has been called.
    //
    typedef unsigned int win32_once_t;
    const win32_once_t WIN32_ONCE_INIT = 0;

    LIBODB_EXPORT void
    win32_once (win32_once_t&, void (*func) ());

    extern LIBODB_EXPORT CRITICAL_SECTION win32_once_cs_;
  }
}

#include <odb/details/win32/once.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_ONCE_HXX
