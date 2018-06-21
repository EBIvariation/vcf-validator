// file      : odb/details/shared-ptr/base.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/meta/answer.hxx>
#include <odb/details/meta/polymorphic-p.hxx>

namespace odb
{
  namespace details
  {
    namespace bits
    {
      // Support for locating the counter in the memory block.
      //
      struct LIBODB_EXPORT locator_common
      {
        static std::size_t*
        counter (void*);
      };

      template <typename X, bool poly = meta::polymorphic_p<X>::result>
      struct locator;

      template <typename X>
      struct locator<X, false>: locator_common
      {
        static std::size_t*
        counter (X* x)
        {
          return locator_common::counter (x);
        }
      };

      template <typename X>
      struct locator<X, true>: locator_common
      {
        static std::size_t*
        counter (X* x)
        {
          return locator_common::counter (dynamic_cast<void*> (x));
        }
      };

      template <typename X>
      std::size_t*
      counter (const X* p)
      {
        return bits::locator<X>::counter (const_cast<X*> (p));
      }

      // Counter type and operations.
      //
      meta::no test (...);
      meta::yes test (shared_base*);

      template <typename X,
                std::size_t A = sizeof (bits::test (reinterpret_cast<X*> (0)))>
      struct counter_type;

      template <typename X>
      struct counter_type<X, sizeof (meta::no)>
      {
        typedef typename details::counter_type<X>::counter r;
      };

      template <typename X>
      struct counter_type<X, sizeof (meta::yes)>
      {
        typedef shared_base r;
      };

      template <typename X, typename Y>
      struct counter_ops;

      template <typename X>
      struct counter_ops<X, X>
      {
        counter_ops (const X* p) : counter_ (p ? bits::counter (p) : 0) {}
        counter_ops (const counter_ops& x) : counter_ (x.counter_) {}

        template <typename Z>
        counter_ops (const counter_ops<Z, Z>& x) : counter_ (x.counter_) {}

        counter_ops&
        operator= (const counter_ops& x)
        {
          counter_ = x.counter_;
          return *this;
        }

        template <typename Z>
        counter_ops&
        operator= (const counter_ops<Z, Z>& x)
        {
          counter_ = x.counter_;
          return *this;
        }

        void
        reset (const X* p)
        {
          counter_ = p ? bits::counter (p) : 0;
        }

        void
        inc (X*)
        {
          (*counter_)++;
        }

        void
        dec (X* p)
        {
          if (--(*counter_) == 0)
          {
            p->~X ();

            // Counter is the top of the memory block.
            //
            operator delete (counter_);
          }
        }

        std::size_t
        count (const X*) const
        {
          return *counter_;
        }

        std::size_t* counter_;
      };

      template <typename Y>
      struct counter_ops<shared_base, Y>
      {
        counter_ops (const Y*) {}
        counter_ops (const counter_ops&) {}

        template <typename Z>
        counter_ops (const counter_ops<shared_base, Z>&) {}

        counter_ops&
        operator= (const counter_ops&)
        {
          return *this;
        }

        template <typename Z>
        counter_ops&
        operator= (const counter_ops<shared_base, Z>&)
        {
          return *this;
        }

        void
        reset (const Y*) {}

        void
        inc (shared_base* p) {p->_inc_ref ();}

        void
        dec (Y* p)
        {
          if (static_cast<shared_base*> (p)->_dec_ref ())
            delete p;
        }

        std::size_t
        count (const shared_base* p) const {return p->_ref_count ();}
      };
    }

    template <typename X>
    inline X*
    inc_ref (X* p)
    {
      bits::counter_ops<typename bits::counter_type<X>::r, X> c (p);
      c.inc (p);
      return p;
    }

    template <typename X>
    inline void
    dec_ref (X* p)
    {
      bits::counter_ops<typename bits::counter_type<X>::r, X> c (p);
      c.dec (p);
    }

    template <typename X>
    inline std::size_t
    ref_count (const X* p)
    {
      bits::counter_ops<typename bits::counter_type<X>::r, X> c (p);
      return c.count (p);
    }
  }
}
