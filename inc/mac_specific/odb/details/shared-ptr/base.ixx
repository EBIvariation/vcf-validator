// file      : odb/details/shared-ptr/base.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace details
  {
    // share
    //

    inline share::
    share (char id)
        : id_ (id)
    {
    }

    inline bool share::
    operator== (share x) const
    {
      return id_ == x.id_;
    }

    // shared_base
    //

    inline shared_base::
    shared_base ()
        : counter_ (1), callback_ (0)
    {
    }

    inline shared_base::
    shared_base (const shared_base&)
        : counter_ (1), callback_ (0)
    {
    }

    inline shared_base& shared_base::
    operator= (const shared_base&)
    {
      return *this;
    }

    inline void shared_base::
    _inc_ref ()
    {
      counter_++;
    }

    inline bool shared_base::
    _dec_ref ()
    {
      if (callback_ == 0)
        return --counter_ == 0;
      else
        return _dec_ref_callback ();
    }

    inline std::size_t shared_base::
    _ref_count () const
    {
      return counter_;
    }

    inline void* shared_base::
    operator new (std::size_t n) throw (std::bad_alloc)
    {
      return ::operator new (n);
    }

    inline void* shared_base::
    operator new (std::size_t n, share) throw (std::bad_alloc)
    {
      return ::operator new (n);
    }

    inline void shared_base::
    operator delete (void* p, share) throw ()
    {
      ::operator delete (p);
    }

    inline void shared_base::
    operator delete (void* p) throw ()
    {
      ::operator delete (p);
    }
  }
}
