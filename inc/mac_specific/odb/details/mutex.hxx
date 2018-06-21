// file      : odb/details/mutex.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_MUTEX_HXX
#define ODB_DETAILS_MUTEX_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx>
#include <odb/details/export.hxx>

#ifdef ODB_THREADS_NONE

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT mutex
    {
    public:
      mutex () {}

      void
      lock () {}

      void
      unlock () {}

    private:
      mutex (const mutex&);
      mutex& operator= (const mutex&);
    };
  }
}

#elif defined(ODB_THREADS_POSIX)
#include <odb/details/posix/mutex.hxx>
#elif defined(ODB_THREADS_WIN32)
#include <odb/details/win32/mutex.hxx>
#else
# error unknown threading model
#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_MUTEX_HXX
