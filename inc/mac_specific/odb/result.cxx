// file      : odb/result.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/result.hxx>
#include <odb/connection.hxx>

namespace odb
{
  result_impl::
  ~result_impl ()
  {
    if (next_ != this)
      list_remove ();
  }

  result_impl::
  result_impl (connection& c)
      : db_ (c.database ()), conn_ (c), prev_ (0), next_ (this)
  {
    // Add to the list.
    //
    next_ = conn_.results_;
    conn_.results_ = this;

    if (next_ != 0)
      next_->prev_ = this;
  }

  void result_impl::
  list_remove ()
  {
    (prev_ == 0 ? conn_.results_ : prev_->next_) = next_;

    if (next_ != 0)
      next_->prev_ = prev_;

    prev_ = 0;
    next_ = this;
  }
}
