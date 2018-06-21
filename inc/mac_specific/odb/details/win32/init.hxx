// file      : odb/details/win32/init.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_INIT_HXX
#define ODB_DETAILS_WIN32_INIT_HXX

#include <odb/pre.hxx>

namespace odb
{
  namespace details
  {
    void
    process_start ();

    // The safe parameter indicates whether it is safe to free heap objects.
    // If the process is terminated by a call to ExitProcess(), some threads
    // might have been killed leaving things in inconsistent state.
    //
    void
    process_end (bool safe = true);

    void
    thread_start ();

    // This function may be called even for thread for which thread_start()
    // hasn't been called.
    //
    void
    thread_end ();
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_INIT_HXX
