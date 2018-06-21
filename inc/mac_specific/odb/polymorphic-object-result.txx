// file      : odb/polymorphic-object-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/exceptions.hxx>

namespace odb
{
  //
  // polymorphic_object_result_impl
  //

  template <typename T>
  void polymorphic_object_result_impl<T>::
  load ()
  {
    typedef typename root_traits::pointer_type root_pointer_type;
    typedef typename root_traits::pointer_traits root_pointer_traits;

    // First check the session.
    //
    const id_type& id (load_id ());

    root_pointer_type rp (
      object_traits::pointer_cache_traits::find (this->db_, id));

    if (!root_pointer_traits::null_ptr (rp))
    {
      // Check if the types match.
      //
      pointer_type p (
        root_pointer_traits::template dynamic_pointer_cast<
          object_type> (rp));

      if (!pointer_traits::null_ptr (p))
        current (p, false); // Pointer from cache should not be guarded.
      else
        // We have an object in session that has a different type
        // compared to the one in the database.
        //
        throw object_not_persistent (); // @@ type_mismatch?
    }
    else
      // load() is responsible for creating the object of a correct
      // dynamic type and for object cache insertion.
      //
      load (0, false);
  }

  //
  // object_result_iterator
  //

  template <typename T, typename ID>
  void object_result_iterator<T, ID, true>::
  load (object_type& obj)
  {
    if (res_->end ())
      return;

    typedef odb::object_traits<object_type> object_traits;

    typename object_traits::reference_cache_traits::position_type p (
      object_traits::reference_cache_traits::insert (
        res_->db_, res_->load_id (), obj));
    typename object_traits::reference_cache_traits::insert_guard ig (p);
    res_->load (&obj, false);
    object_traits::reference_cache_traits::load (p);
    ig.release ();
  }
}
