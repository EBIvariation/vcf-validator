// file      : odb/database.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/section.hxx>
#include <odb/exceptions.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/pointer-traits.hxx>

namespace odb
{
  template <typename T>
  result<T> database::
  query (const odb::query<T>& q, bool cache)
  {
    // T is always object_type. We also don't need to check for transaction
    // here; object_traits::query () does this.
    //
    result<T> r (query_<T, id_common>::call (*this, q));

    if (cache)
      r.cache ();

    return r;
  }

  // Implementations (i.e., the *_() functions).
  //
  template <typename T, database_id DB>
  typename object_traits<T>::id_type database::
  persist_ (T& obj)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef object_traits_impl<object_type, DB> object_traits;

    object_traits::persist (*this, obj);

    typename object_traits::reference_cache_traits::position_type p (
      object_traits::reference_cache_traits::insert (
        *this, reference_cache_type<T>::convert (obj)));

    object_traits::reference_cache_traits::persist (p);

    return object_traits::id (obj);
  }

  template <typename T, database_id DB>
  typename object_traits<T>::id_type database::
  persist_ (const typename object_traits<T>::pointer_type& pobj)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef typename object_traits<T>::pointer_type pointer_type;

    typedef object_traits_impl<object_type, DB> object_traits;

    T& obj (pointer_traits<pointer_type>::get_ref (pobj));
    object_traits::persist (*this, obj);

    // Get the canonical object pointer and insert it into object cache.
    //
    typename object_traits::pointer_cache_traits::position_type p (
      object_traits::pointer_cache_traits::insert (
        *this, pointer_cache_type<pointer_type>::convert (pobj)));

    object_traits::pointer_cache_traits::persist (p);

    return object_traits::id (obj);
  }

  template <typename T, bool = object_traits<T>::auto_id> struct persist_type;
  template <typename T> struct persist_type<T, true> {typedef T type;};
  template <typename T> struct persist_type<T, false> {typedef const T type;};

  template <typename I, typename T, database_id DB>
  void database::
  persist_ (I b, I e, bool cont, details::meta::no /*ptr*/)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef object_traits_impl<object_type, DB> object_traits;

    multiple_exceptions mex (typeid (object_already_persistent));
    try
    {
      while (b != e && (cont || mex.empty ()))
      {
        std::size_t n (0);
        T* a[object_traits::batch]; // T instead of persist_type for cache.

        for (; b != e && n < object_traits::batch; ++n)
        {
          // Compiler error pointing here? Perhaps the passed range is
          // of const objects?
          //
          typename persist_type<object_type>::type* p (&(*b++));

          a[n] = const_cast<T*> (p);
        }

        // Compiler error pointing here? Perhaps the object or the
        // database does not support bulk operations?
        //
        object_traits::persist (
          *this,
          const_cast<typename persist_type<object_type>::type**> (a),
          n,
          mex);

        if (mex.fatal ())
          break;

        for (std::size_t i (0); i < n; ++i)
        {
          if (mex[i] != 0) // Don't cache objects that have failed.
            continue;

          mex.current (i); // Set position in case the below code throws.

          typename object_traits::reference_cache_traits::position_type p (
            object_traits::reference_cache_traits::insert (
              *this, reference_cache_type<T>::convert (*a[i])));

          object_traits::reference_cache_traits::persist (p);
        }

        mex.delta (n);
      }
    }
    catch (const odb::exception& ex)
    {
      mex.insert (ex, true);
    }

    if (!mex.empty ())
    {
      mex.prepare ();
      throw mex;
    }
  }

  template <typename P>
  struct pointer_copy
  {
    const P* ref;
    P copy;

    void assign (const P& p) {ref = &p;}
    template <typename P1> void assign (const P1& p1)
    {
      // The passed pointer should be the same or implicit-convertible
      // to the object pointer. This way we make sure the object pointer
      // does not assume ownership of the passed object.
      //
      const P& p (p1);

      copy = p;
      ref = &copy;
    }
  };

  template <typename I, typename T, database_id DB>
  void database::
  persist_ (I b, I e, bool cont, details::meta::yes /*ptr*/)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef typename object_traits<T>::pointer_type pointer_type;

    typedef object_traits_impl<object_type, DB> object_traits;

    multiple_exceptions mex (typeid (object_already_persistent));
    try
    {
      while (b != e && (cont || mex.empty ()))
      {
        std::size_t n (0);
        typename persist_type<object_type>::type* a[object_traits::batch];
        pointer_copy<pointer_type> p[object_traits::batch];

        for (; b != e && n < object_traits::batch; ++n)
        {
          p[n].assign (*b++);
          a[n] = &pointer_traits<pointer_type>::get_ref (*p[n].ref);
        }

        // Compiler error pointing here? Perhaps the object or the
        // database does not support bulk operations?
        //
        object_traits::persist (*this, a, n, mex);

        if (mex.fatal ())
          break;

        for (std::size_t i (0); i < n; ++i)
        {
          if (mex[i] != 0) // Don't cache objects that have failed.
            continue;

          mex.current (i); // Set position in case the below code throws.

          // Get the canonical object pointer and insert it into object cache.
          //
          typename object_traits::pointer_cache_traits::position_type pos (
            object_traits::pointer_cache_traits::insert (
              *this, pointer_cache_type<pointer_type>::convert (*p[i].ref)));

          object_traits::pointer_cache_traits::persist (pos);
        }

        mex.delta (n);
      }
    }
    catch (const odb::exception& ex)
    {
      mex.insert (ex, true);
    }

    if (!mex.empty ())
    {
      mex.prepare ();
      throw mex;
    }
  }

  template <typename T, database_id DB>
  typename object_traits<T>::pointer_type database::
  load_ (const typename object_traits<T>::id_type& id)
  {
    // T is always object_type.
    //
    typedef typename object_traits<T>::pointer_type pointer_type;

    pointer_type r (find_<T, DB> (id));

    if (pointer_traits<pointer_type>::null_ptr (r))
      throw object_not_persistent ();

    return r;
  }

  template <typename T, database_id DB>
  void database::
  load_ (const typename object_traits<T>::id_type& id, T& obj)
  {
    if (!find_<T, DB> (id, obj))
      throw object_not_persistent ();
  }

  template <typename T, database_id DB>
  void database::
  load_ (T& obj, section& s)
  {
    connection_type& c (transaction::current ().connection ());

    // T is always object_type.
    //
    if (object_traits_impl<T, DB>::load (c, obj, s))
      s.reset (true, false); // Loaded, unchanged.
    else
      throw section_not_in_object ();
  }

  template <typename T, database_id DB>
  void database::
  reload_ (T& obj)
  {
    // T should be object_type (cannot be const). We also don't need to
    // check for transaction here; object_traits::reload () does this.
    //
    if (!object_traits_impl<T, DB>::reload (*this, obj))
      throw object_not_persistent ();
  }

  template <typename I, database_id DB>
  void database::
  update_ (I b, I e, bool cont)
  {
    // Sun CC with non-standard STL does not have iterator_traits.
    //
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
    typedef typename std::iterator_traits<I>::value_type value_type;
#else
    // Assume iterator is just a pointer.
    //
    typedef typename object_pointer_traits<I>::object_type value_type;
#endif

    // object_pointer_traits<T>::object_type can be const.
    //
    typedef object_pointer_traits<value_type> opt;

    typedef
    typename object_traits<typename opt::object_type>::object_type
    object_type;

    typedef object_traits_impl<object_type, DB> object_traits;

    multiple_exceptions mex (
      object_traits::managed_optimistic_column_count == 0
      ? typeid (object_not_persistent)
      : typeid (object_changed));

    try
    {
      while (b != e && (cont || mex.empty ()))
      {
        std::size_t n (0);
        const object_type* a[object_traits::batch];

        for (; b != e && n < object_traits::batch; ++n)
          a[n] = &opt::get_ref (*b++);

        // Compiler error pointing here? Perhaps the object or the
        // database does not support bulk operations?
        //
        object_traits::update (*this, a, n, mex);

        if (mex.fatal ())
          break;

        mex.delta (n);
      }
    }
    catch (const odb::exception& ex)
    {
      mex.insert (ex, true);
    }

    if (!mex.empty ())
    {
      mex.prepare ();
      throw mex;
    }
  }

  template <typename T, database_id DB>
  void database::
  update_ (const T& obj, const section& s)
  {
    if (!s.loaded ())
      throw section_not_loaded ();

    transaction& t (transaction::current ());

    // T is always object_type.
    //
    if (object_traits_impl<T, DB>::update (t.connection (), obj, s))
    {
      if (s.changed ())
        s.reset (true, false, &t); // Clear the change flag.
    }
    else
      throw section_not_in_object ();
  }

  template <typename I, typename T, database_id DB>
  void database::
  erase_id_ (I b, I e, bool cont)
  {
    // T is explicitly specified by the caller, so assume it is object type.
    //
    typedef T object_type;
    typedef object_traits_impl<object_type, DB> object_traits;
    typedef typename object_traits::id_type id_type;

    multiple_exceptions mex (typeid (object_not_persistent));
    try
    {
      while (b != e && (cont || mex.empty ()))
      {
        std::size_t n (0);
        const id_type* a[object_traits::batch];

        for (; b != e && n < object_traits::batch; ++n)
          // Compiler error pointing here? Perhaps the object id type
          // and the range element type don't match?
          //
          a[n] = &(*b++);

        // Compiler error pointing here? Perhaps the object or the
        // database does not support bulk operations?
        //
        object_traits::erase (*this, a, n, mex);

        if (mex.fatal ())
          break;

        mex.delta (n);
      }
    }
    catch (const odb::exception& ex)
    {
      mex.insert (ex, true);
    }

    if (!mex.empty ())
    {
      mex.prepare ();
      throw mex;
    }
  }

  template <typename I, database_id DB>
  void database::
  erase_object_ (I b, I e, bool cont)
  {
    // Sun CC with non-standard STL does not have iterator_traits.
    //
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
    typedef typename std::iterator_traits<I>::value_type value_type;
#else
    // Assume iterator is just a pointer.
    //
    typedef typename object_pointer_traits<I>::object_type value_type;
#endif

    // object_pointer_traits<T>::object_type can be const.
    //
    typedef object_pointer_traits<value_type> opt;

    typedef
    typename object_traits<typename opt::object_type>::object_type
    object_type;

    typedef object_traits_impl<object_type, DB> object_traits;

    multiple_exceptions mex (
      object_traits::managed_optimistic_column_count == 0
      ? typeid (object_not_persistent)
      : typeid (object_changed));

    try
    {
      while (b != e && (cont || mex.empty ()))
      {
        std::size_t n (0);
        const object_type* a[object_traits::batch];

        for (; b != e && n < object_traits::batch; ++n)
          a[n] = &opt::get_ref (*b++);

        // Compiler error pointing here? Perhaps the object or the
        // database does not support bulk operations?
        //
        object_traits::erase (*this, a, n, mex);

        if (mex.fatal ())
          break;

        mex.delta (n);
      }
    }
    catch (const odb::exception& ex)
    {
      mex.insert (ex, true);
    }

    if (!mex.empty ())
    {
      mex.prepare ();
      throw mex;
    }
  }

  template <typename T, database_id DB>
  struct database::query_<T, DB, class_object>
  {
    template <typename Q>
    static result<T>
    call (database& db, const Q& q)
    {
      return object_traits_impl<T, DB>::query (db, q);
    }
  };

  template <typename T, database_id DB>
  struct database::query_<T, DB, class_view>
  {
    template <typename Q>
    static result<T>
    call (database& db, const Q& q)
    {
      return view_traits_impl<T, DB>::query (db, q);
    }
  };
}
