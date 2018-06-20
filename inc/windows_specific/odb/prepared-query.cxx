// file      : odb/prepared-query.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/connection.hxx>
#include <odb/prepared-query.hxx>

namespace odb
{
  prepared_query_impl::
  ~prepared_query_impl ()
  {
    if (next_ != this)
      list_remove ();
  }

  prepared_query_impl::
  prepared_query_impl (connection& c)
      : cached (false), conn (c), prev_ (0), next_ (this)
  {
    // Add to the list.
    //
    next_ = conn.prepared_queries_;
    conn.prepared_queries_ = this;

    if (next_ != 0)
      next_->prev_ = this;
  }

  void prepared_query_impl::
  list_remove ()
  {
    (prev_ == 0 ? conn.prepared_queries_ : prev_->next_) = next_;

    if (next_ != 0)
      next_->prev_ = prev_;

    prev_ = 0;
    next_ = this;
  }
}
