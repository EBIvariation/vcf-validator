// file      : odb/polymorphic-object-result.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_POLYMORPHIC_OBJECT_RESULT_HXX
#define ODB_POLYMORPHIC_OBJECT_RESULT_HXX

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
  // Implementation for polymorphic objects with object id.
  //
  template <typename T>
  class polymorphic_object_result_impl: public result_impl
  {
  protected:
    // In result_impl, T is always non-const and the same as object_type.
    //
    typedef T object_type;
    typedef odb::object_traits<object_type> object_traits;
    typedef typename object_traits::id_type id_type;

    typedef typename object_traits::pointer_type pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    typedef typename object_traits::root_type root_type;
    typedef odb::object_traits<root_type> root_traits;
    typedef typename root_traits::discriminator_type discriminator_type;

    friend class result<T>;
    friend class result<const T>;
    friend class result_iterator<T, class_object>;
    friend class result_iterator<const T, class_object>;
    friend class object_result_iterator<T, id_type, true>;
    friend class object_result_iterator<const T, id_type, true>;

  protected:
    polymorphic_object_result_impl (odb::connection& conn)
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
    // The fetch argument is a hint to the implementation. If it is
    // false then it means load_id() was already called (and presumably
    // fetched the data into the object image) and the object image
    // is still valid (so the implementation doesn't need to fetch
    // the data again).
    //
    // The load() signature differs from the non-polymorphic cases in
    // that we pass a pointer to object instead of a reference. The
    // object is only passed if the user requests loading into an
    // existing instance. Otherwise, we pass NULL and load() is
    // responsible for creating the object of a correct dynamic
    // type and managing the object cache insertion.
    //
    virtual void
    load (object_type*, bool fetch = true) = 0;

    virtual id_type
    load_id () = 0;

    virtual discriminator_type
    load_discriminator () = 0;

    virtual void
    next () = 0;

    virtual void
    cache () = 0;

    virtual std::size_t
    size () = 0;

  protected:
#ifdef ODB_CXX11
    void
    current (pointer_type& p, bool guard = true)
    {
      current_ = std::move (p);

      if (guard)
        guard_.reset (current_);
      else
        guard_.reset ();
    }

    void
    current (pointer_type&& p, bool guard = true)
    {
      current (p, guard);
    }
#else
    void
    current (pointer_type p, bool guard = true)
    {
      current_ = p;

      if (guard)
        guard_.reset (current_);
      else
        guard_.reset ();
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

  template <typename T, typename ID>
  class object_result_iterator<T, ID, true>
  {
  public:
    // T can be const T while object_type is always non-const.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef typename object_traits<T>::id_type id_type;
    typedef typename object_traits<T>::root_type root_type;
    typedef typename object_traits<root_type>::discriminator_type
    discriminator_type;

    typedef polymorphic_object_result_impl<object_type> result_impl_type;

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
    load (object_type&);

    id_type
    id ()
    {
      return res_->load_id ();
    }

    discriminator_type
    discriminator ()
    {
      return res_->load_discriminator ();
    }

  protected:
    result_impl_type* res_;
  };
}

#include <odb/polymorphic-object-result.txx>

#include <odb/post.hxx>

#endif // ODB_POLYMORPHIC_OBJECT_RESULT_HXX
