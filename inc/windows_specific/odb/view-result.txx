// file      : odb/view-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  //
  // view_result_impl
  //

  template <typename T>
  typename view_result_impl<T>::pointer_type&
  view_result_impl<T>::
  current ()
  {
    if (pointer_traits::null_ptr (current_) && !end_)
    {
      pointer_type p (view_traits::create ());
      view_type& view (pointer_traits::get_ref (p));
      current (p);
      load (view);
    }

    return current_;
  }

  //
  // result_iterator
  //

  template <typename T>
  void result_iterator<T, class_view>::
  load (view_type& view)
  {
    if (res_->end ())
      return;

    res_->load (view);
  }
}
