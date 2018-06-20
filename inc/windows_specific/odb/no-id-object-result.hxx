// file      : odb/no-id-object-result.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_NO_ID_OBJECT_RESULT_HXX
#define ODB_NO_ID_OBJECT_RESULT_HXX

#include <odb/pre.hxx>

#include <cstddef>  // std::size_t
#include <utility>  // std::move

#include <odb/forward.hxx>
#include <odb/traits.hxx>
#include <odb/result.hxx>
#include <odb/object-result.hxx>
#include <odb/pointer-traits.hxx>

#include <odb/details/config.hxx>     // ODB_CXX11

namespace odb
{
  // Implementation for objects without object id (always non-polymorphic).
  //
  template <typename T>
  class no_id_object_result_impl: public result_impl
  {
  protected:
    // In result_impl, T is always non-const and the same as object_type.
    //
    typedef T object_type;
    typedef odb::object_traits<object_type> object_traits;

    typedef typename object_traits::pointer_type pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    friend class result<T>;
    friend class result<const T>;
    friend class result_iterator<T, class_object>;
    friend class result_iterator<const T, class_object>;
    friend class object_result_iterator<T, void, false>;
    friend class object_result_iterator<const T, void, false>;

  protected:
    no_id_object_result_impl (odb::connection& conn)
        : result_impl (conn), begin_ (true), end_ (false), current_ ()
    {
    }

    // To make this work with all kinds of pointers (raw, std::auto_ptr,
    // shared), we need to make sure we don't make any copies of the
    // pointer on the return path.
    //
    pointer_type&
    current ()
    {
      if (pointer_traits::null_ptr (current_) && !end_)
        load ();

      return current_;
    }

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
    load (object_type&) = 0;

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
    void
    load ();

  private:
    pointer_type current_;
    typename pointer_traits::guard guard_;
  };

  template <typename T>
  class object_result_iterator<T, void, false>
  {
  public:
    // T can be const T while object_type is always non-const.
    //
    typedef typename object_traits<T>::object_type object_type;

    typedef no_id_object_result_impl<object_type> result_impl_type;

  public:
    object_result_iterator (result_impl_type* res)
        : res_ (res)
    {
    }

  public:
    typename object_traits<T>::pointer_type
    load ()
    {
      typename object_traits<T>::pointer_type r (res_->current ());
      res_->release ();
      return r;
    }

    void
    load (object_type& obj)
    {
      // Objects without ids are not stored in session cache.
      //
      if (!res_->end ())
        res_->load (obj);
    }

  protected:
    result_impl_type* res_;
  };
}

#include <odb/no-id-object-result.txx>

#include <odb/post.hxx>

#endif // ODB_NO_ID_OBJECT_RESULT_HXX
