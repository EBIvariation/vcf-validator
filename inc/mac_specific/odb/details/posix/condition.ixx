// file      : odb/details/posix/condition.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/posix/exceptions.hxx>

namespace odb
{
  namespace details
  {
    inline condition::
    ~condition ()
    {
      pthread_cond_destroy (&cond_);
    }

    inline condition::
    condition (mutex& mutex)
        : mutex_ (mutex)
    {
      if (int e = pthread_cond_init (&cond_, 0))
        throw posix_exception (e);
    }

    inline void condition::
    signal ()
    {
      if (int e = pthread_cond_signal (&cond_))
        throw posix_exception (e);
    }

    inline void condition::
    wait ()
    {
      if (int e = pthread_cond_wait (&cond_, &mutex_.mutex_))
        throw posix_exception (e);
    }
  }
}
