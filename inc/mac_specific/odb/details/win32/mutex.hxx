// file      : odb/details/win32/mutex.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_MUTEX_HXX
#define ODB_DETAILS_WIN32_MUTEX_HXX

#include <odb/pre.hxx>

#include <odb/details/win32/windows.hxx>
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
      CRITICAL_SECTION cs_;
    };
  }
}

#include <odb/details/win32/mutex.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_MUTEX_HXX
