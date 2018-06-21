// file      : odb/details/posix/thread.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/posix/exceptions.hxx>

namespace odb
{
  namespace details
  {
    inline thread::
    ~thread ()
    {
      if (!detached_)
      {
        if (int e = pthread_detach (id_))
          throw posix_exception (e);
      }
    }

    inline void* thread::
    join ()
    {
      void* r;

      if (int e = pthread_join (id_, &r))
        throw posix_exception (e);

      detached_ = true;
      return r;
    }
  }
}
