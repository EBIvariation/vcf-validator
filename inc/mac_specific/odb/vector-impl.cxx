// file      : odb/vector-impl.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/vector-impl.hxx>

#include <cstring>   // std::memcpy, std::memset
#include <algorithm> // std::swap

using namespace std;

namespace odb
{
  // vector_impl
  //
  const unsigned char vector_impl::mask_[4] = {0x3, 0xC, 0x30, 0xC0};
  const unsigned char vector_impl::shift_[4] = {0, 2, 4, 6};

  vector_impl::
  vector_impl (const vector_impl& x)
      : state_ (x.state_), size_ (0), tail_ (0), capacity_ (0), data_ (0)
  {
    // Copy the data over if we are tracking.
    //
    if (state_ == state_tracking && x.size_ != 0)
    {
      realloc (x.size_ < 1024 ? 1024 : x.size_);
      memcpy (data_, x.data_, x.size_ / 4 + (x.size_ % 4 == 0 ? 0 : 1));
      size_ = x.size_;
      tail_ = x.tail_;
    }
  }

  void vector_impl::
  realloc (size_t n)
  {
    // The new capacity can be less or greater than the old one, but
    // it cannot be less than size.
    //
    size_t b (n / 4 + (n % 4 == 0 ? 0 : 1));

    if (b != capacity_ * 4)
    {
      unsigned char* d (static_cast<unsigned char*> (operator new (b)));

      if (size_ != 0)
        memcpy (d, data_, size_ / 4 + (size_ % 4 == 0 ? 0 : 1));

      if (data_ != 0)
        operator delete (data_);

      data_ = d;
      capacity_ = b * 4;
    }
  }

  void vector_impl::
  shrink_to_fit ()
  {
    if (size_ != capacity_)
    {
      if (size_ != 0)
        realloc (size_);
      else
      {
        operator delete (data_);
        data_ = 0;
        capacity_ = 0;
      }
    }
  }

  void vector_impl::
  start (size_t n)
  {
    if (n != 0)
    {
      if (capacity_ < n)
      {
        size_ = 0;
        realloc (n < 1024 ? 1024 : n);
      }

      memset (data_, 0, n / 4 + (n % 4 == 0 ? 0 : 1));
    }

    state_ = state_tracking;
    size_ = tail_ = n;
  }

  void vector_impl::
  push_back (size_t n)
  {
    for (; n != 0; --n)
    {
      size_t i (tail_);

      element_state_type s;
      if (i != size_)
        // We have an erased element we can reuse.
        //
        s = state_updated;
      else
      {
        if (size_ == capacity_)
        {
          size_t c (capacity_ == 0 ? 1024 : capacity_ * 2);
          if (c < size_ + n)
            c = size_ + n;
          realloc (c);
        }

        s = state_inserted;
        size_++;
      }

      set (i, s);
      tail_++;
    }
  }

  void vector_impl::
  pop_back (size_t n)
  {
    for (; n != 0; --n)
    {
      size_t i (tail_ - 1);

      if (state (i) != state_inserted)
        set (i, state_erased);
      else
        size_--; // tail_ == size_

      tail_--;
    }
  }

  void vector_impl::
  insert (size_t i, size_t n)
  {
    for (; i != tail_; ++i)
      if (state (i) != state_inserted)
        set (i, state_updated);

    push_back (n);
  }

  void vector_impl::
  erase (size_t i, size_t n)
  {
    pop_back (n);

    for (; i != tail_; ++i)
      if (state (i) != state_inserted)
        set (i, state_updated);
  }

  void vector_impl::
  clear ()
  {
    // The idea is to drop any inserted elements from the back and
    // set everything else to erased.
    //
    if (tail_ == size_)
    {
      while (size_ != 0 && state (size_ - 1) == state_inserted)
        size_--;

      tail_ = size_;
    }

    if (tail_ != 0)
      memset (data_, 0xFF, tail_ / 4 + (tail_ % 4 == 0 ? 0 : 1));

    tail_ = 0;
  }

  // vector_base
  //
  void vector_base::
  rollback (unsigned short, void* key, unsigned long long)
  {
    // Mark as changed.
    //
    static_cast<vector_base*> (key)->impl_.change ();
  }

  void vector_base::
  swap_tran (vector_base& x)
  {
    // If either instance is armed, then we need to update the
    // callback registration.
    //
    transaction* t (x.tran_);
    if (tran_ != 0)
    {
      tran_->callback_unregister (this);
      x._arm (*tran_);
    }

    if (t != 0)
    {
      t->callback_unregister (&x);
      _arm (*t);
    }

    std::swap (tran_, x.tran_);
  }
}
