// file      : odb/vector-impl.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifdef ODB_CXX11
#  include <utility> // std::swap, std::move
#else
#  include <algorithm> // std::swap
#endif

namespace odb
{
  // vector_impl
  //
  inline vector_impl::
  vector_impl ()
      : state_ (state_not_tracking),
        size_ (0), tail_ (0), capacity_ (0), data_ (0)
  {
  }

#ifdef ODB_CXX11
  inline vector_impl::
  vector_impl (vector_impl&& x)
      : state_ (state_not_tracking),
        size_ (0), tail_ (0), capacity_ (0), data_ (0)
  {
    swap (x);
  }
#endif

  inline vector_impl::
  ~vector_impl ()
  {
    if (data_ != 0)
      operator delete (data_);
  }

  inline void vector_impl::
  swap (vector_impl& x)
  {
    std::swap (state_, x.state_);
    std::swap (size_, x.size_);
    std::swap (tail_, x.tail_);
    std::swap (capacity_, x.capacity_);
    std::swap (data_, x.data_);
  }

  inline void vector_impl::
  reserve (std::size_t n)
  {
    if (n > capacity_)
      realloc (n);
  }

  inline void vector_impl::
  stop ()
  {
    state_ = state_not_tracking;
    size_ = tail_ = 0;
  }

  inline void vector_impl::
  change ()
  {
    state_ = state_changed;
    size_ = tail_ = 0;
  }

  inline vector_impl::container_state_type vector_impl::
  state () const
  {
    return state_;
  }

  inline bool vector_impl::
  tracking () const
  {
    return state_ == state_tracking;
  }

  inline std::size_t vector_impl::
  size () const
  {
    return size_;
  }

  inline std::size_t vector_impl::
  capacity () const
  {
    return capacity_;
  }

  inline vector_impl::element_state_type vector_impl::
  state (std::size_t i) const
  {
    std::size_t r (i % 4);
    unsigned char v (data_[i / 4]);
    return static_cast<element_state_type> ((v & mask_[r]) >> shift_[r]);
  }

  inline void vector_impl::
  set (std::size_t i, element_state_type s)
  {
    std::size_t r (i % 4);
    i /= 4;
    unsigned char v (static_cast<unsigned char> (s));
    v <<= shift_[r];
    data_[i] = (data_[i] & ~mask_[r]) | v;
  }

  inline void vector_impl::
  modify (std::size_t i, std::size_t n)
  {
    for (; n != 0; --n, ++i)
      if (state (i) != state_inserted)
        set (i, state_updated);
  }

  inline void vector_impl::
  assign (std::size_t n)
  {
    if (tail_ != 0)
      clear ();

    push_back (n);
  }

  inline void vector_impl::
  resize (size_t n)
  {
    if (n < tail_)
      pop_back (tail_ - n);
    else if (n > tail_)
      push_back (n - tail_);
  }

  // vector_base
  //
  inline vector_base::
  ~vector_base ()
  {
    if (tran_ != 0)
      tran_->callback_unregister (this);
  }

  inline vector_base::
  vector_base (): tran_ (0) {}

  inline vector_base::
  vector_base (const vector_base& x)
      : impl_ (x.impl_), tran_ (0)
  {
    // If the original is armed, then arm ourselves as well.
    //
    if (x.tran_ != 0)
      _arm (*x.tran_);
  }

  inline void vector_base::
  swap (vector_base& x)
  {
    impl_.swap (x.impl_);

    if (tran_ != 0 || x.tran_ != 0)
      swap_tran (x);
  }

#ifdef ODB_CXX11
  inline vector_base::
  vector_base (vector_base&& x)
      : impl_ (std::move (x.impl_)), tran_ (0)
  {
    if (x.tran_ != 0)
    {
      x.tran_->callback_unregister (&x);
      _arm (*x.tran_);
    }
  }
#endif

  inline void vector_base::
  _stop () const
  {
    impl_.stop ();
  }

  inline bool vector_base::
  _tracking () const
  {
    return impl_.tracking ();
  }

  inline void vector_base::
  _arm (transaction& t) const
  {
    tran_ = &t;
    t.callback_register (&rollback,
                         const_cast<vector_base*> (this),
                         transaction::event_rollback,
                         0,
                         &tran_);
  }
}
