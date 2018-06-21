// file      : odb/details/posix/tls.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/unique-ptr.hxx>
#include <odb/details/posix/exceptions.hxx>

namespace odb
{
  namespace details
  {
    // tls<T>
    //

    template <typename T>
    int tls<T>::error_ = 0;

    template <typename T>
    pthread_once_t tls<T>::once_ = PTHREAD_ONCE_INIT;

    template <typename T>
    pthread_key_t tls<T>::key_;

    template <typename T>
    T& tls<T>::
    get () const
    {
      int e (pthread_once (&once_, key_init));

      if (e != 0 || error_ != 0)
        throw posix_exception (e ? e : error_);

      if (void* v = pthread_getspecific (key_))
        return *static_cast<T*> (v);

      unique_ptr<T> p (new T);

      if ((e = pthread_setspecific (key_, p.get ())))
        throw posix_exception (e);

      T& r (*p);
      p.release ();
      return r;
    }

    template <typename T>
    void tls<T>::
    free ()
    {
      int e (pthread_once (&once_, key_init));

      if (e != 0 || error_ != 0)
        throw posix_exception (e ? e : error_);

      if (void* v = pthread_getspecific (key_))
      {
        if ((e = pthread_setspecific (key_, 0)))
          throw posix_exception (e);

        delete static_cast<T*> (v);
      }
    }

    template <typename T>
    void tls<T>::
    key_init ()
    {
      error_ = pthread_key_create (&key_, destructor);
    }

    template <typename T>
    void tls<T>::
    destructor (void* v)
    {
      delete static_cast<T*> (v);
    }

    // tls<T*>
    //

    template <typename T>
    int tls<T*>::error_ = 0;

    template <typename T>
    pthread_once_t tls<T*>::once_ = PTHREAD_ONCE_INIT;

    template <typename T>
    pthread_key_t tls<T*>::key_;

    template <typename T>
    T* tls<T*>::
    get () const
    {
      int e (pthread_once (&once_, key_init));

      if (e != 0 || error_ != 0)
        throw posix_exception (e ? e : error_);

      return static_cast<T*> (pthread_getspecific (key_));
    }

    template <typename T>
    void tls<T*>::
    set (T* p)
    {
      int e (pthread_once (&once_, key_init));

      if (e != 0 || error_ != 0)
        throw posix_exception (e ? e : error_);

      if ((e = pthread_setspecific (key_, p)))
        throw posix_exception (e);
    }

    template <typename T>
    void tls<T*>::
    key_init ()
    {
      error_ = pthread_key_create (&key_, 0);
    }
  }
}
