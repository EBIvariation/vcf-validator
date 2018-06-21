// file      : odb/view-result.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VIEW_RESULT_HXX
#define ODB_VIEW_RESULT_HXX

#include <odb/pre.hxx>

#include <cstddef>  // std::ptrdiff_t, std::size_t
#include <iterator> // iterator categories
#include <utility>  // std::move

#include <odb/forward.hxx>
#include <odb/traits.hxx>
#include <odb/result.hxx>
#include <odb/pointer-traits.hxx>

#include <odb/details/config.hxx>     // ODB_CXX11

namespace odb
{
  template <typename T>
  class view_result_impl: public result_impl
  {
  protected:
    friend class result<T>;
    friend class result<const T>;
    friend class result_iterator<T, class_view>;
    friend class result_iterator<const T, class_view>;

    // In result_impl, T is always non-const and the same as view_type.
    //
    typedef T view_type;
    typedef odb::view_traits<view_type> view_traits;

    typedef typename view_traits::pointer_type pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    view_result_impl (odb::connection& conn)
        : result_impl (conn), begin_ (true), end_ (false), current_ ()
    {
    }

    // To make this work with all kinds of pointers (raw, std::auto_ptr,
    // shared), we need to make sure we don't make any copies of the
    // pointer on the return path.
    //
    pointer_type&
    current ();

    void
    release ()
    {
      current_ = pointer_type ();
      guard_.release ();
    }

    void
    begin ()
    {
      if (begin_)
      {
        next ();
        begin_ = false;
      }
    }

    bool
    end () const
    {
      return end_;
    }

  protected:
    virtual void
    load (view_type&) = 0;

    virtual void
    next () = 0;

    virtual void
    cache () = 0;

    virtual std::size_t
    size () = 0;

  protected:
#ifdef ODB_CXX11
    void
    current (pointer_type& p)
    {
      current_ = std::move (p);
      guard_.reset (current_);
    }

    void
    current (pointer_type&& p)
    {
      current (p);
    }
#else
    void
    current (pointer_type p)
    {
      current_ = p;
      guard_.reset (current_);
    }
#endif

    bool begin_;
    bool end_;

  private:
    pointer_type current_;
    typename pointer_traits::guard guard_;
  };

  template <typename T>
  class result_iterator<T, class_view>
  {
  public:
    typedef T value_type;
    typedef value_type& reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::input_iterator_tag iterator_category;

    // T can be const T while view_type is always non-const.
    //
    typedef typename view_traits<T>::view_type view_type;

    typedef view_result_impl<view_type> result_impl_type;

  public:
    explicit
    result_iterator (result_impl_type* res = 0)
        : res_ (res)
    {
    }

    // Input iterator requirements.
    //
  public:
    reference
    operator* () const
    {
      return pointer_traits::get_ref (res_->current ());
    }

    // Our value_type is already a pointer so return it instead of
    // a pointer to it (operator-> will just have to go one deeper
    // in the latter case).
    //
    pointer
    operator-> () const
    {
      return pointer_traits::get_ptr (res_->current ());
    }

    result_iterator&
    operator++ ()
    {
      res_->next ();
      return *this;
    }

    result_iterator
    operator++ (int)
    {
      // All non-end iterators for a result object move together.
      //
      res_->next ();
      return *this;
    }

  public:
    typename view_traits<T>::pointer_type
    load ()
    {
      typename view_traits<T>::pointer_type r (res_->current ());
      res_->release ();
      return r;
    }

    void
    load (view_type&);

  public:
    bool
    equal (result_iterator j) const
    {
      return  (res_ ? res_->end () : true) == (j.res_ ? j.res_->end () : true);
    }

  private:
    // Use unrestricted pointer traits since that's what is returned by
    // result_impl.
    //
    typedef
    odb::pointer_traits<typename view_traits<view_type>::pointer_type>
    pointer_traits;

    result_impl_type* res_;
  };

  //
  //
  template <typename T>
  class result_base<T, class_view>
  {
  public:
    typedef typename view_traits<T>::pointer_type value_type;

    // T can be const T while view_type is always non-const.
    //
    typedef typename view_traits<T>::view_type view_type;
    typedef view_result_impl<view_type> result_impl_type;
  };
}

#include <odb/view-result.txx>

#include <odb/post.hxx>

#endif // ODB_VIEW_RESULT_HXX
