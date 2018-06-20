// file      : odb/details/posix/mutex.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/posix/exceptions.hxx>

namespace odb
{
  namespace details
  {
    inline mutex::
    ~mutex ()
    {
      pthread_mutex_destroy (&mutex_);
    }

    inline mutex::
    mutex ()
    {
      if (int e = pthread_mutex_init (&mutex_, 0))
        throw posix_exception (e);
    }

    inline void mutex::
    lock ()
    {
      if (int e = pthread_mutex_lock (&mutex_))
        throw posix_exception (e);
    }

    inline void mutex::
    unlock ()
    {
      if (int e = pthread_mutex_unlock (&mutex_))
        throw posix_exception (e);
    }
  }
}
