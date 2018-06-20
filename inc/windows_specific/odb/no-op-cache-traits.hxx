// file      : odb/no-op-cache-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_NO_OP_CACHE_TRAITS_HXX
#define ODB_NO_OP_CACHE_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/traits.hxx>
#include <odb/forward.hxx>
#include <odb/pointer-traits.hxx>

namespace odb
{
  // pointer_cache_type
  //
  // Used to convert an object pointer to the canonical form (non-const),
  // suitable for insertion into the cache.
  //
  template <typename P,
            typename E = typename pointer_traits<P>::element_type,
            typename O = typename object_traits<E>::object_type,
            pointer_kind pk = pointer_traits<P>::kind>
  struct pointer_cache_type
  {
    typedef typename object_traits<O>::pointer_type pointer_type;

    static pointer_type
    convert (const P& p)
    {
      return pointer_traits<P>::const_pointer_cast (p);
    }
  };

  template <typename P, typename T, pointer_kind pk>
  struct pointer_cache_type<P, T, T, pk>
  {
    // If element_type and object_type are the same, then it is already
    // the canonical pointer.
    //
    static const P&
    convert (const P& p) {return p;}
  };

  template <typename P, typename E, typename O>
  struct pointer_cache_type<P, E, O, pk_unique>
  {
    // If the pointer is unique, then casting it can transfer ownership.
    // In this case we return NULL void*, which will be ignored down the
    // chain.
    //
    static void*
    convert (const P&) {return 0;}
  };

  template <typename P, typename T>
  struct pointer_cache_type<P, T, T, pk_unique>
  {
    static void*
    convert (const P&) {return 0;}
  };

  // reference_cache_type
  //
  // Used to convert an object reference to the canonical form (non-const),
  // suitable for insertion into the cache.
  //
  template <typename T,
            typename O = typename object_traits<T>::object_type>
  struct reference_cache_type
  {
    static O&
    convert (T& r)
    {
      return const_cast<O&> (r);
    }
  };

  template <typename T>
  struct reference_cache_type<T, T>
  {
    // If the types are the same, then it is already the canonical form.
    //
    static T&
    convert (T& r) {return r;}
  };

  // pointer_cache_traits
  //
  // Caching traits for objects passed by pointer. P should be the canonical
  // pointer (non-const).
  //
  template <typename P>
  struct no_op_pointer_cache_traits
  {
    typedef P pointer_type;
    typedef typename pointer_traits<pointer_type>::element_type object_type;
    typedef typename object_traits<object_type>::id_type id_type;
    struct position_type {};

    struct insert_guard
    {
      insert_guard () {}
      insert_guard (const position_type&) {}

      position_type
      position () const {return position_type ();}

      void
      release () {}

      void
      reset (const position_type&) {}
    };

    // Cache management.
    //
    static position_type
    insert (odb::database&, const id_type&, const pointer_type&)
    {
      return position_type ();
    }

    static position_type
    insert (odb::database&, const pointer_type&) {return position_type ();}

    // Special signature for unique pointers.
    //
    static position_type
    insert (odb::database&, void*) {return position_type ();}

    static pointer_type
    find (odb::database&, const id_type&) {return pointer_type ();}

    static void
    erase (const position_type&) {}

    // Notifications.
    //
    static void
    persist (const position_type&) {}

    static void
    load (const position_type&) {}

    static void
    update (odb::database&, const object_type&) {}

    static void
    erase (odb::database&, const id_type&) {}
  };

  template <typename P>
  struct no_id_pointer_cache_traits
  {
    typedef P pointer_type;
    struct position_type {};

    static position_type
    insert (odb::database&, const pointer_type&) {return position_type ();}

    // Special signature for unique pointers.
    //
    static position_type
    insert (odb::database&, void*) {return position_type ();}

    static void
    persist (const position_type&) {}

    static void
    load (const position_type&) {}
  };

  // reference_cache_traits
  //
  // Caching traits for objects passed by reference. T should be the
  // canonical object type (non-const).
  //
  template <typename T>
  struct no_op_reference_cache_traits
  {
    typedef T object_type;
    typedef typename object_traits<object_type>::id_type id_type;
    struct position_type {};

    struct insert_guard
    {
      insert_guard () {}
      insert_guard (const position_type&) {}

      position_type
      position () const {return position_type ();}

      void
      release () {}

      void
      reset () {}
    };

    static position_type
    insert (odb::database&, const id_type&, object_type&)
    {
      return position_type ();
    }

    static position_type
    insert (odb::database&, object_type&) {return position_type ();}

    static void
    persist (const position_type&) {}

    static void
    load (const position_type&) {}
  };

  template <typename T>
  struct no_id_reference_cache_traits
  {
    typedef T object_type;
    struct position_type {};

    static position_type
    insert (odb::database&, object_type&) {return position_type ();}

    static void
    persist (const position_type&) {}

    static void
    load (const position_type&) {}
  };
}

#include <odb/post.hxx>

#endif // ODB_NO_OP_CACHE_TRAITS_HXX
