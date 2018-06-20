// file      : odb/details/condition.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_CONDITION_HXX
#define ODB_DETAILS_CONDITION_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx>
#include <odb/details/export.hxx>

#ifdef ODB_THREADS_NONE

namespace odb
{
  namespace details
  {
    class mutex;
    class LIBODB_EXPORT condition
    {
    public:
      condition (mutex&) {}

      void
      signal () {}

      void
      wait () {}

    private:
      condition (const condition&);
      condition& operator= (const condition&);
    };
  }
}

#elif defined(ODB_THREADS_POSIX)
#include <odb/details/posix/condition.hxx>
#elif defined(ODB_THREADS_WIN32)
#include <odb/details/win32/condition.hxx>
#else
# error unknown threading model
#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_CONDITION_HXX
