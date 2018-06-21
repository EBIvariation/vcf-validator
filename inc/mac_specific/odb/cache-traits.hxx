// file      : odb/cache-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_CACHE_TRAITS_HXX
#define ODB_CACHE_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/traits.hxx>
#include <odb/forward.hxx>
#include <odb/session.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/no-op-cache-traits.hxx>

namespace odb
{
  // pointer_cache_traits
  //
  // Caching traits for objects passed by pointer. P should be the canonical
  // pointer (non-const).
  //
  template <typename P, typename S, pointer_kind pk>
  struct pointer_cache_traits_impl
  {
    typedef P pointer_type;
    typedef S session_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;
    typedef typename pointer_traits::element_type object_type;
    typedef typename object_traits<object_type>::id_type id_type;
    typedef typename session_type::template cache_position<object_type>
    position_type;

    struct insert_guard
    {
      insert_guard () {}
      insert_guard (const position_type& pos): pos_ (pos) {}
      ~insert_guard () {session_type::_cache_erase (pos_);}

      const position_type&
      position () const {return pos_;}

      void
      release () {pos_ = position_type ();}

      // Note: doesn't call erase() on the old position (assumes empty).
      //
      void
      reset (const position_type& pos) {pos_ = pos;}

    private:
      position_type pos_;
    };

    // Cache management.
    //
    // We need the insert() overload with explicit id to handle self-
    // references. In such cases the object is not yet loaded and the
    // id member does not contain the correct id.
    //
    // Qualify the database type to resolve a phony ambiguity in VC 10.
    //
    static position_type
    insert (odb::database& db, const id_type& id, const pointer_type& p)
    {
      return session_type::template _cache_insert<object_type> (db, id, p);
    }

    static position_type
    insert (odb::database& db, const pointer_type& p)
    {
      const id_type& id (
        object_traits<object_type>::id (
          pointer_traits::get_ref (p)));

      return session_type::template _cache_insert<object_type> (db, id, p);
    }

    static pointer_type
    find (odb::database& db, const id_type& id)
    {
      return session_type::template _cache_find<object_type> (db, id);
    }

    static void
    erase (const position_type& p)
    {
      session_type::template _cache_erase<object_type> (p);
    }

    // Notifications.
    //
    static void
    persist (const position_type& p)
    {
      session_type::template _cache_persist<object_type> (p);
    }

    static void
    load (const position_type& p)
    {
      session_type::template _cache_load<object_type> (p);
    }

    static void
    update (odb::database& db, const object_type& obj)
    {
      session_type::template _cache_update<object_type> (db, obj);
    }

    static void
    erase (odb::database& db, const id_type& id)
    {
      session_type::template _cache_erase<object_type> (db, id);
    }
  };

  // Unique pointers don't work with the object cache.
  //
  template <typename P, typename S>
  struct pointer_cache_traits_impl<P, S, pk_unique>:
    no_op_pointer_cache_traits<P> {};

  template <typename P, typename S>
  struct pointer_cache_traits:
    pointer_cache_traits_impl<P, S, pointer_traits<P>::kind> {};

  // reference_cache_traits
  //
  // Caching traits for objects passed by reference. T should be the
  // canonical object type (non-const). Only if the object pointer
  // kind is raw do we add the object to the session.
  //
  template <typename T, typename S, pointer_kind pk>
  struct reference_cache_traits_impl: no_op_reference_cache_traits<T> {};

  template <typename T, typename S>
  struct reference_cache_traits_impl<T, S, pk_raw>
  {
    typedef T object_type;
    typedef typename object_traits<object_type>::pointer_type pointer_type;
    typedef typename object_traits<object_type>::id_type id_type;

    typedef pointer_cache_traits<pointer_type, S> pointer_traits;
    typedef typename pointer_traits::position_type position_type;
    typedef typename pointer_traits::insert_guard insert_guard;

    static position_type
    insert (odb::database& db, const id_type& id, object_type& obj)
    {
      pointer_type p (&obj);
      return pointer_traits::insert (db, id, p);
    }

    static position_type
    insert (odb::database& db, object_type& obj)
    {
      pointer_type p (&obj);
      return pointer_traits::insert (db, p);
    }

    static void
    persist (const position_type& p)
    {
      pointer_traits::persist (p);
    }

    static void
    load (const position_type& p)
    {
      pointer_traits::load (p);
    }
  };

  template <typename T, typename S>
  struct reference_cache_traits:
    reference_cache_traits_impl<
      T, S, pointer_traits<typename object_traits<T>::pointer_type>::kind> {};
}

#include <odb/post.hxx>

#endif // ODB_CACHE_TRAITS_HXX
