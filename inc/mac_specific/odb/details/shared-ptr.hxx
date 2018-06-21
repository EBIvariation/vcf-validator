// file      : odb/details/shared-ptr.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_HXX
#define ODB_DETAILS_SHARED_PTR_HXX

#include <odb/pre.hxx>

#include <odb/details/shared-ptr-fwd.hxx>
#include <odb/details/shared-ptr/base.hxx>
#include <odb/details/shared-ptr/exception.hxx>

namespace odb
{
  namespace details
  {
    template <typename X>
    class shared_ptr: bits::counter_ops<typename bits::counter_type<X>::r, X>
    {
      typedef bits::counter_ops<typename bits::counter_type<X>::r, X> base;

    public:
      ~shared_ptr ()
      {
        if (x_ != 0)
          base::dec (x_);
      }

      explicit
      shared_ptr (X* x = 0)
          : base (x), x_ (x)
      {
      }

      shared_ptr (const shared_ptr& x)
          : base (x), x_ (x.x_)
      {
        if (x_ != 0)
          base::inc (x_);
      }

      template <typename Y>
      shared_ptr (const shared_ptr<Y>& x)
          : base (x), x_ (x.x_)
      {
        if (x_ != 0)
          base::inc (x_);
      }

      shared_ptr&
      operator= (const shared_ptr& x)
      {
        if (x_ != x.x_)
        {
          if (x_ != 0)
            base::dec (x_);

          static_cast<base&> (*this) = x;
          x_ = x.x_;

          if (x_ != 0)
            base::inc (x_);
        }

        return *this;
      }

      template <typename Y>
      shared_ptr&
      operator= (const shared_ptr<Y>& x)
      {
        if (x_ != x.x_)
        {
          if (x_ != 0)
            base::dec (x_);

          static_cast<base&> (*this) = x;
          x_ = x.x_;

          if (x_ != 0)
            base::inc (x_);
        }

        return *this;
      }

    public:
      X*
      operator-> () const
      {
        return x_;
      }

      X&
      operator* () const
      {
        return *x_;
      }

      // Conversion to bool.
      //
      typedef void (shared_ptr::*boolean_convertible)();
      void true_value () {}

      operator boolean_convertible () const
      {
        return x_ ? &shared_ptr<X>::true_value : 0;
      }

    public:
      X*
      get () const
      {
        return x_;
      }

      X*
      release ()
      {
        X* r (x_);
        x_ = 0;
        return r;
      }

      void
      reset (X* x = 0)
      {
        if (x_ != 0)
          base::dec (x_);

        base::reset (x);
        x_ = x;
      }

      std::size_t
      count () const
      {
        return x_ != 0 ? base::count (x_) : 0;
      }

    private:
      template <typename>
      friend class shared_ptr;

      X* x_;
    };

    template <typename X, typename Y>
    inline bool
    operator== (const shared_ptr<X>& x, const shared_ptr<Y>& y)
    {
      return x.get () == y.get ();
    }

    template <typename X, typename Y>
    inline bool
    operator!= (const shared_ptr<X>& x, const shared_ptr<Y>& y)
    {
      return x.get () != y.get ();
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_SHARED_PTR_HXX
