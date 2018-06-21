// file      : odb/details/tls.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_TLS_HXX
#define ODB_DETAILS_TLS_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx>

#ifdef ODB_THREADS_NONE

#  define ODB_TLS_POINTER(type) type*
#  define ODB_TLS_OBJECT(type) type

namespace odb
{
  namespace details
  {
    template <typename T>
    inline T&
    tls_get (T& x)
    {
      return x;
    }

    // If early destructions is possible, destroy the object and free
    // any allocated resources.
    //
    template <typename T>
    inline void
    tls_free (T& x)
    {
    }

    template <typename T>
    inline T*
    tls_get (T* p)
    {
      return p;
    }

    template <typename T, typename T1>
    inline void
    tls_set (T*& rp, T1* p)
    {
      rp = p;
    }
  }
}

#elif defined(ODB_THREADS_POSIX)

#  include <odb/details/posix/tls.hxx>

#  ifdef ODB_THREADS_TLS_KEYWORD
#    define ODB_TLS_POINTER(type) __thread type*

namespace odb
{
  namespace details
  {
    template <typename T>
    inline T*
    tls_get (T* p)
    {
      return p;
    }

    template <typename T, typename T1>
    inline void
    tls_set (T*& rp, T1* p)
    {
      rp = p;
    }
  }
}

#  else
#    define ODB_TLS_POINTER(type) tls<type*>
#  endif
#  define ODB_TLS_OBJECT(type) tls<type>

#elif defined(ODB_THREADS_WIN32)

#  include <odb/details/win32/tls.hxx>

#  ifdef ODB_THREADS_TLS_DECLSPEC
#    define ODB_TLS_POINTER(type) __declspec(thread) type*

namespace odb
{
  namespace details
  {
    template <typename T>
    inline T*
    tls_get (T* p)
    {
      return p;
    }

    template <typename T, typename T1>
    inline void
    tls_set (T*& rp, T1* p)
    {
      rp = p;
    }
  }
}

#  else
#    define ODB_TLS_POINTER(type) tls<type*>
#  endif
#  define ODB_TLS_OBJECT(type) tls<type>
#else
# error unknown threading model
#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_TLS_HXX
