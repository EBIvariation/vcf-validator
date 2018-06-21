// file      : odb/no-id-object-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  //
  // object_result_impl
  //

  template <typename T>
  void no_id_object_result_impl<T>::
  load ()
  {
    // Objects without ids are not stored in session cache.
    //
    pointer_type p (object_traits::create ());
    object_type& obj (pointer_traits::get_ref (p));
    current (p);
    load (obj);
  }
}
