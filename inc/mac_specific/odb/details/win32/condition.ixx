// file      : odb/details/win32/condition.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/exceptions.hxx>

namespace odb
{
  namespace details
  {
    inline condition::
    ~condition ()
    {
      CloseHandle (event_);
    }

    inline condition::
    condition (mutex& mutex)
        : mutex_ (mutex), waiters_ (0), signals_ (0)
    {
      // Auto-reset event. Releases one waiting thread and automatically
      // resets the event state. If no threads are waiting the event
      // remains signalled.
      //
      event_ = CreateEvent (0, false, false, 0);

      if (event_ == 0)
        throw win32_exception ();
    }
  }
}
