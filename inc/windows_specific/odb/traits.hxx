// file      : odb/traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRAITS_HXX
#define ODB_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>
#include <odb/pointer-traits.hxx>

namespace odb
{
  // Fallback dummy for non-persistent classes. It is necessary to allow
  // the C++ compiler to instantiate persist(), etc., signatures in class
  // database when T is a pointer (raw, smart). The overloads that use
  // these dummy would never actually be selected by the compiler.
  //
  template <typename T>
  class access::object_traits
  {
    // If a C++ compiler issues an error pointing to this class and saying
    // that it is missing some declaration, then you are most likely trying
    // to perform a database operation on a C++ type that is not a persistent
    // object. Or you forgot to include the corresponding -odb.hxx file.
    //
  public:
    struct id_type {};
    typedef T object_type;
    typedef T* pointer_type;

    static const bool polymorphic = false;
  };

  template <typename T, typename P>
  class access::object_factory
  {
  public:
    typedef T object_type;
    typedef P pointer_type;

    static P
    create ()
    {
      // By default use pointer-specific construction.
      //
      return pointer_factory<T, P>::create ();
    }
  };

  template <typename T, typename P>
  class access::view_factory
  {
  public:
    typedef T view_type;
    typedef P pointer_type;

    static P
    create ()
    {
      // By default use pointer-specific construction.
      //
      return pointer_factory<T, P>::create ();
    }
  };

  template <typename T, typename P>
  class access::pointer_factory
  {
  public:
    typedef T value_type;
    typedef P pointer_type;

    static P
    create ()
    {
      void* v (pointer_traits<P>::allocate (sizeof (T)));
      mem_guard g (v);
      P p (new (v) T);
      g.release ();
      return p;
    }

  private:
    struct mem_guard
    {
      mem_guard (void* p): p_ (p) {}
      ~mem_guard () {if (p_) pointer_traits<P>::free (p_);}
      void release () {p_ = 0;}
      void* p_;
    };
  };

  //
  // class_traits
  //
  enum class_kind
  {
    class_object,
    class_view,
    class_other
  };

  template <typename T>
  struct class_traits
  {
    static const class_kind kind = class_other;
  };

  template <typename T>
  struct class_traits<const T>
  {
    static const class_kind kind = class_traits<T>::kind;
  };

  //
  // object_traits
  //

  template <typename T>
  //
  // If a C++ compiler issues an error pointing to this struct and
  // saying that it is incomplete, then you are most likely trying to
  // perform a database operation on a C++ type that is not a persistent
  // object. Or you forgot to include the corresponding -odb.hxx file.
  //
  struct object_traits:
    access::object_traits<T>,
    access::object_factory<T, typename access::object_traits<T>::pointer_type>
  {
    typedef
    odb::pointer_traits<typename access::object_traits<T>::pointer_type>
    pointer_traits;

    typedef typename access::object_traits<T>::object_type object_type;
    typedef typename access::object_traits<T>::pointer_type pointer_type;
    typedef typename pointer_traits::const_pointer_type const_pointer_type;
  };

  // Specialization for const objects. It only defines the id, object,
  // pointer, and const_pointer types with pointer and const_pointer
  // being the same. The idea is to only use this specialization in the
  // interfaces, with the implementations detecting this situation and
  // using the non-const object_traits version.
  //
  template <typename T>
  struct object_traits<const T>
  {
  private:
    typedef
    odb::pointer_traits<typename access::object_traits<T>::pointer_type>
    pointer_traits;

  public:
    typedef typename access::object_traits<T>::id_type id_type;
    typedef typename access::object_traits<T>::object_type object_type;
    typedef typename pointer_traits::const_pointer_type const_pointer_type;
    typedef const_pointer_type pointer_type;

    static const bool polymorphic = access::object_traits<T>::polymorphic;
  };

  // Specialization for section to allow instantiation of all the load()
  // signature.
  //
  template <>
  struct object_traits<section> {};

  template <typename T, database_id DB>
  //
  // If a C++ compiler issues an error pointing to this struct and
  // saying that it is incomplete, then you are most likely trying to
  // perform a database operation on a C++ type that is not a persistent
  // object. Or you forgot to include the corresponding -odb.hxx file.
  //
  struct object_traits_impl:
    access::object_traits_impl<T, DB>,
    access::object_factory<T, typename access::object_traits<T>::pointer_type>
  {
    typedef
    odb::pointer_traits<typename access::object_traits<T>::pointer_type>
    pointer_traits;

    typedef typename access::object_traits<T>::object_type object_type;
    typedef typename access::object_traits<T>::pointer_type pointer_type;
    typedef typename pointer_traits::const_pointer_type const_pointer_type;
  };

  //
  // view_traits
  //

  template <typename T>
  //
  // If a C++ compiler issues an error pointing to this struct and
  // saying that it is incomplete, then you are most likely trying to
  // perform a database operation on a C++ type that is not a view
  // Or you forgot to include the corresponding -odb.hxx file.
  //
  struct view_traits:
    access::view_traits<T>,
    access::view_factory<T, typename access::view_traits<T>::pointer_type>
  {
    typedef
    odb::pointer_traits<typename access::view_traits<T>::pointer_type>
    pointer_traits;

    typedef typename access::view_traits<T>::view_type view_type;
    typedef typename access::view_traits<T>::pointer_type pointer_type;
  };

  // Specialization for const views. It only defines the view, pointer,
  // and const_pointer types with pointer and const_pointer being the
  // same. Similar to objects, the idea is to only use this specialization
  // in the interfaces, with the implementations detecting this situation
  // and using the non-const view_traits version.
  //
  template <typename T>
  struct view_traits<const T>
  {
  private:
    typedef
    odb::pointer_traits<typename access::view_traits<T>::pointer_type>
    pointer_traits;

  public:
    typedef typename access::view_traits<T>::view_type view_type;
    typedef typename pointer_traits::const_pointer_type const_pointer_type;
    typedef const_pointer_type pointer_type;
  };

  template <typename T, database_id DB>
  //
  // If a C++ compiler issues an error pointing to this struct and
  // saying that it is incomplete, then you are most likely trying to
  // perform a database operation on a C++ type that is not a view
  // Or you forgot to include the corresponding -odb.hxx file.
  //
  struct view_traits_impl:
    access::view_traits_impl<T, DB>,
    access::view_factory<T, typename access::view_traits<T>::pointer_type>
  {
    typedef
    odb::pointer_traits<typename access::view_traits<T>::pointer_type>
    pointer_traits;

    typedef typename access::view_traits<T>::view_type view_type;
    typedef typename access::view_traits<T>::pointer_type pointer_type;
  };

  //
  // composite_value_traits
  //

  template <typename T, database_id DB>
  struct composite_value_traits: access::composite_value_traits<T, DB>
  {
  };

  //
  // Get root image from a polymorphic image chain.
  //

  template <typename T, std::size_t d>
  struct root_image_impl
  {
    typedef root_image_impl<typename T::base_traits, d - 1> base_type;
    typedef typename base_type::image_type image_type;

    static image_type&
    get (typename T::image_type& i) {return base_type::get (*i.base);}
    };

  template <typename T>
  struct root_image_impl<T, 1>
  {
    typedef typename T::image_type image_type;

    static image_type&
    get (image_type& i) {return i;}
  };

  template <typename T, bool p>
  struct root_image
  {
    typedef root_image_impl<T, T::depth> impl_type;
    typedef typename impl_type::image_type image_type;

    static image_type&
    get (typename T::image_type& i) {return impl_type::get (i);}
  };

  template <typename T>
  struct root_image<T, false>
  {
    typedef typename T::image_type image_type;

    static image_type&
    get (image_type& i) {return i;}
  };
}

#include <odb/post.hxx>

#endif // ODB_TRAITS_HXX
