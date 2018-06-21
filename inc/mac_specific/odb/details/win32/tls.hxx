// file      : odb/details/win32/tls.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_TLS_HXX
#define ODB_DETAILS_WIN32_TLS_HXX

#include <odb/pre.hxx>

#include <cstddef> // std::size_t

#include <odb/details/export.hxx>
#include <odb/details/win32/once.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT tls_common
    {
    public:
      static std::size_t
      _allocate (void (*dtor) (void*));

      static void*
      _get (std::size_t key);

      static void
      _set (std::size_t key, void* value);
    };

    template <typename T>
    class tls: protected tls_common
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
      static win32_once_t once_;
      static std::size_t key_;
    };

    template <typename T>
    class tls<T*>: protected tls_common
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
      static win32_once_t once_;
      static std::size_t key_;
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

#include <odb/details/win32/tls.ixx>
#include <odb/details/win32/tls.txx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_TLS_HXX
