// file      : odb/details/posix/tls.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_TLS_HXX
#define ODB_DETAILS_POSIX_TLS_HXX

#include <odb/pre.hxx>

#include <pthread.h>

namespace odb
{
  namespace details
  {
    template <typename T>
    class tls
    {
    public:
      tls ();

      T&
      get () const;

      void
      free ();

    private:
      tls (const tls&);
      tls& operator= (const tls&);

    private:
      static void
      key_init ();

      static void
      destructor (void*);

    private:
      static int error_;
      static pthread_once_t once_;
      static pthread_key_t key_;
    };

    template <typename T>
    class tls<T*>
    {
    public:
      tls ();

      T*
      get () const;

      void
      set (T* p);

    private:
      tls (const tls&);
      tls& operator= (const tls&);

    private:
      static void
      key_init ();

    private:
      static int error_;
      static pthread_once_t once_;
      static pthread_key_t key_;
    };

    template <typename T>
    inline T&
    tls_get (const tls<T>& t)
    {
      return t.get ();
    }

    template <typename T>
    inline void
    tls_free (tls<T>& t)
    {
      t.free ();
    }

    template <typename T>
    inline T*
    tls_get (const tls<T*>& t)
    {
      return t.get ();
    }

    template <typename T, typename T1>
    inline void
    tls_set (tls<T*>& t, T1* p1)
    {
      T* p (p1);
      t.set (p);
    }
  }
}

#include <odb/details/posix/tls.ixx>
#include <odb/details/posix/tls.txx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_POSIX_TLS_HXX
