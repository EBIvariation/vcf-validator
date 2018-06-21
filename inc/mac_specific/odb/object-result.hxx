// file      : odb/object-result.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_OBJECT_RESULT_HXX
#define ODB_OBJECT_RESULT_HXX

#include <odb/pre.hxx>

#include <cstddef>  // std::ptrdiff_t
#include <iterator> // iterator categories

#include <odb/forward.hxx>
#include <odb/traits.hxx>
#include <odb/result.hxx>
#include <odb/pointer-traits.hxx>

namespace odb
{
  //
  // object_result_impl
  //
  template <typename T>
  class object_result_impl;

  template <typename T>
  class polymorphic_object_result_impl;

  template <typename T>
  class no_id_object_result_impl;

  //
  // object_result_impl_selector
  //
  template <typename T,
            typename ID = typename object_traits<T>::id_type,
            bool polymorphic = object_traits<T>::polymorphic>
  struct object_result_impl_selector;

  template <typename T, typename ID>
  struct object_result_impl_selector<T, ID, false>
  {
    typedef object_result_impl<T> type;
  };

  template <typename T, typename ID>
  struct object_result_impl_selector<T, ID, true>
  {
    typedef polymorphic_object_result_impl<T> type;
  };

  template <typename T>
  struct object_result_impl_selector<T, void, false>
  {
    typedef no_id_object_result_impl<T> type;
  };

  //
  // result_iterator
  //

  template <typename T, typename ID, bool polymorphic>
  class object_result_iterator;

  template <typename T>
  class result_iterator<T, class_object>: public object_result_iterator<
    T,
    typename object_traits<T>::id_type,
    object_traits<T>::polymorphic>
  {
  public:
    typedef T value_type;
    typedef value_type& reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::input_iterator_tag iterator_category;

    // T can be const T while object_type is always non-const.
    //
    typedef
    object_result_iterator<T,
                           typename object_traits<T>::id_type,
                           object_traits<T>::polymorphic> base_type;

  public:
    explicit
    result_iterator (typename base_type::result_impl_type* res = 0)
        : base_type (res)
    {
    }

    // Input iterator requirements.
    //
  public:
    reference
    operator* () const
    {
      return pointer_traits::get_ref (this->res_->current ());
    }

    // Our value_type is already a pointer so return it instead of
    // a pointer to it (operator-> will just have to go one deeper
    // in the latter case).
    //
    pointer
    operator-> () const
    {
      return pointer_traits::get_ptr (this->res_->current ());
    }

    result_iterator&
    operator++ ()
    {
      this->res_->next ();
      return *this;
    }

    result_iterator
    operator++ (int)
    {
      // All non-end iterators for a result object move together.
      //
      this->res_->next ();
      return *this;
    }

  public:
    bool
    equal (result_iterator j) const
    {
      return  (this->res_ ? this->res_->end () : true) ==
        (j.res_ ? j.res_->end () : true);
    }

  private:
    // Use unrestricted pointer traits since that's what is returned by
    // result_impl.
    //
    typedef
    odb::pointer_traits<
      typename object_traits<
        typename base_type::object_type>::pointer_type>
    pointer_traits;
  };

  //
  //
  template <typename T>
  class result_base<T, class_object>
  {
  public:
    typedef typename object_traits<T>::pointer_type value_type;

    // T can be const T while object_type is always non-const.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef
    typename object_result_impl_selector<object_type>::type
    result_impl_type;
  };
}

#include <odb/post.hxx>

#endif // ODB_OBJECT_RESULT_HXX
