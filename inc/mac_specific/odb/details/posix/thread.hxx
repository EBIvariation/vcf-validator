// file      : odb/details/posix/thread.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_THREAD_HXX
#define ODB_DETAILS_POSIX_THREAD_HXX

#include <odb/pre.hxx>

#include <pthread.h>

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT thread
    {
    public:
      ~thread ();
      thread (void* (*thread_func) (void*), void* arg = 0);

      void*
      join ();

    private:
      thread (const thread&);
      thread& operator= (const thread&);

    private:
      bool detached_;
      pthread_t id_;
    };
  }
}

#include <odb/details/posix/thread.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_POSIX_THREAD_HXX
