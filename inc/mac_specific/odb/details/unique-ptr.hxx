// file      : odb/details/unique-ptr.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_UNIQUE_PTR_HXX
#define ODB_DETAILS_UNIQUE_PTR_HXX

#include <odb/pre.hxx>

namespace odb
{
  namespace details
  {
    template <typename T>
    class unique_ptr
    {
    public:
      typedef T element_type;

      explicit unique_ptr (T* p = 0): p_ (p) {}
      ~unique_ptr () {delete p_;}

    private:
      unique_ptr (const unique_ptr&);
      unique_ptr& operator= (const unique_ptr&);

    public:
      T*
      operator-> () const {return p_;}

      T&
      operator* () const {return *p_;}

      typedef T* unique_ptr::*unspecified_bool_type;
      operator unspecified_bool_type () const
      {
        return p_ != 0 ? &unique_ptr::p_ : 0;
      }

      T*
      get () const {return p_;}

      void
      reset (T* p = 0)
      {
        delete p_;
        p_ = p;
      }

      T*
      release ()
      {
        T* r (p_);
        p_ = 0;
        return r;
      }

    private:
      T* p_;
    };

    template <typename T1, typename T2>
    inline bool
    operator== (const unique_ptr<T1>& a, const unique_ptr<T2>& b)
    {
      return a.get () == b.get ();
    }

    template <typename T1, typename T2>
    inline bool
    operator!= (const unique_ptr<T1>& a, const unique_ptr<T2>& b)
    {
      return a.get () != b.get ();
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_UNIQUE_PTR_HXX
