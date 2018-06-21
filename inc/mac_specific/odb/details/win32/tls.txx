// file      : odb/details/win32/tls.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/unique-ptr.hxx>
#include <odb/details/win32/exceptions.hxx>

namespace odb
{
  namespace details
  {
    // tls<T>
    //
    template <typename T>
    win32_once_t tls<T>::once_= WIN32_ONCE_INIT;

    template <typename T>
    size_t tls<T>::key_;

    template <typename T>
    T& tls<T>::
    get () const
    {
      win32_once (once_, key_init);

      if (void* v = _get (key_))
        return *static_cast<T*> (v);

      unique_ptr<T> p (new T);
      _set (key_, p.get ());

      T& r (*p);
      p.release ();
      return r;
    }

    template <typename T>
    void tls<T>::
    free ()
    {
      win32_once (once_, key_init);

      if (void* v = _get (key_))
      {
        _set (key_, 0);
        delete static_cast<T*> (v);
      }
    }

    template <typename T>
    void tls<T>::
    key_init ()
    {
      key_ = _allocate (destructor);
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
    win32_once_t tls<T*>::once_ = WIN32_ONCE_INIT;

    template <typename T>
    size_t tls<T*>::key_;

    template <typename T>
    T* tls<T*>::
    get () const
    {
      win32_once (once_, key_init);
      return static_cast<T*> (_get (key_));
    }

    template <typename T>
    void tls<T*>::
    set (T* p)
    {
      win32_once (once_, key_init);
      _set (key_, p);
    }

    template <typename T>
    void tls<T*>::
    key_init ()
    {
      key_ = _allocate (0);
    }
  }
}
