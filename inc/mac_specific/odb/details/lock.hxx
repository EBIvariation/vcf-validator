// file      : odb/details/lock.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_LOCK_HXX
#define ODB_DETAILS_LOCK_HXX

#include <odb/pre.hxx>

#include <odb/details/export.hxx>
#include <odb/details/mutex.hxx>

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT lock
    {
      lock (mutex& m)
          : mutex_ (&m)
      {
        mutex_->lock ();
      }

      ~lock ()
      {
        if (mutex_ != 0)
          mutex_->unlock ();
      }

      void
      unlock ()
      {
        if (mutex_ != 0)
        {
          mutex_->unlock ();
          mutex_ = 0;
        }
      }

    private:
      mutex* mutex_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_LOCK_HXX
