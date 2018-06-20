// file      : odb/details/posix/condition.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_CONDITION_HXX
#define ODB_DETAILS_POSIX_CONDITION_HXX

#include <odb/pre.hxx>

#include <pthread.h>

#include <odb/details/export.hxx>
#include <odb/details/posix/mutex.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT condition
    {
    public:
      ~condition ();
      condition (mutex&);

      void
      signal ();

      void
      wait ();

    private:
      condition (const condition&);
      condition& operator= (const condition&);

    private:
      mutex& mutex_;
      pthread_cond_t cond_;
    };
  }
}

#include <odb/details/posix/condition.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_POSIX_CONDITION_HXX
