// file      : odb/details/posix/mutex.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_MUTEX_HXX
#define ODB_DETAILS_POSIX_MUTEX_HXX

#include <odb/pre.hxx>

#include <pthread.h>

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT mutex
    {
    public:
      ~mutex ();
      mutex ();

      void
      lock ();

      void
      unlock ();

    private:
      mutex (const mutex&);
      mutex& operator= (const mutex&);

    private:
      friend class condition;
      pthread_mutex_t mutex_;
    };
  }
}

#include <odb/details/posix/mutex.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_POSIX_MUTEX_HXX
