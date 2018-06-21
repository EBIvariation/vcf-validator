// file      : odb/database.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::strlen()
#include <utility> // std::move
#include <iterator>

#include <odb/transaction.hxx>
#include <odb/pointer-traits.hxx>

namespace odb
{
  template <typename T>
  struct object_pointer_traits
  {
    typedef details::meta::no result_type;
    typedef T object_type;
    static const T& get_ref (const T& x) {return x;}
  };

  template <typename T>
  struct object_pointer_traits<T*>
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const T* p) {return *p;}
  };

  template <typename T>
  struct object_pointer_traits<T* const>
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const T* p) {return *p;}
  };

  template <typename T, template <typename> class P>
  struct object_pointer_traits<P<T> >
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const P<T>& p) {
      return pointer_traits<P<T> >::get_ref (p);}
  };

  template <typename T, typename A1, template <typename, typename> class P>
  struct object_pointer_traits<P<T, A1> >
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const P<T, A1>& p) {
      return pointer_traits<P<T, A1> >::get_ref (p);}
  };

  template <typename T, template <typename> class P>
  struct object_pointer_traits<const P<T> >
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const P<T>& p) {
      return pointer_traits<P<T> >::get_ref (p);}
  };

  template <typename T, typename A1, template <typename, typename> class P>
  struct object_pointer_traits<const P<T, A1> >
  {
    typedef details::meta::yes result_type;
    typedef T object_type;
    static const T& get_ref (const P<T, A1>& p) {
      return pointer_traits<P<T, A1> >::get_ref (p);}
  };

  inline database::
  database (database_id id)
      : id_ (id), tracer_ (0), schema_version_seq_ (1)
  {
  }

  inline database_id database::
  id () const
  {
    return id_;
  }

  inline database::schema_version_type database::
  schema_version (const std::string& name) const
  {
    return schema_version_migration (name).version;
  }

  inline bool database::
  schema_migration (const std::string& name) const
  {
    return schema_version_migration (name).migration;
  }

  inline void database::
  schema_version_migration (schema_version_type v,
                            bool m,
                            const std::string& name)
  {
    schema_version_migration (schema_version_migration_type (v, m), name);
  }

  inline void database::
  schema_version_table (const std::string& tname)
  {
    schema_version_table_ = tname;
  }

  inline void database::
  schema_version_table (const std::string& tname, const std::string& sname)
  {
    schema_version_map_[sname].version_table = tname;
  }

  inline unsigned int database::
  schema_version_sequence () const
  {
    return schema_version_seq_;
  }

  inline connection_ptr database::
  connection ()
  {
    return connection_ptr (connection_ ());
  }

#ifndef ODB_CXX11
  inline void database::
  query_factory (const char* name, query_factory_ptr f)
  {
    query_factory (name, query_factory_wrapper (f));
  }
#endif

  inline void database::
  tracer (tracer_type& t)
  {
    tracer_ = &t;
  }

  inline void database::
  tracer (tracer_type* t)
  {
    tracer_ = t;
  }

  inline database::tracer_type* database::
  tracer () const
  {
    return tracer_;
  }

  template <typename T>
  inline typename object_traits<T>::id_type database::
  persist (T& obj)
  {
    return persist_<T, id_common> (obj);
  }

  template <typename T>
  inline typename object_traits<T>::id_type database::
  persist (const T& obj)
  {
    return persist_<const T, id_common> (obj);
  }

  template <typename T>
  inline typename object_traits<T>::id_type database::
  persist (T* p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    return persist_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline typename object_traits<T>::id_type database::
  persist (const P<T>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    return persist_<T, id_common> (pobj);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline typename object_traits<T>::id_type database::
  persist (const P<T, A1>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    return persist_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline typename object_traits<T>::id_type database::
  persist (P<T>& p)
  {
    const P<T>& cr (p);
    return persist<T, P> (cr);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline typename object_traits<T>::id_type database::
  persist (P<T, A1>& p)
  {
    const P<T, A1>& cr (p);
    return persist<T, A1, P> (cr);
  }

  template <typename T>
  inline typename object_traits<T>::id_type database::
  persist (const typename object_traits<T>::pointer_type& pobj)
  {
    return persist_<T, id_common> (pobj);
  }

  template <typename I>
  inline void database::
  persist (I b, I e, bool cont)
  {
    persist_<I, id_common> (b, e, cont);
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  load (const typename object_traits<T>::id_type& id)
  {
    return load_<T, id_common> (id);
  }

  template <typename T>
  inline void database::
  load (const typename object_traits<T>::id_type& id, T& obj)
  {
    return load_<T, id_common> (id, obj);
  }

  template <typename T>
  inline void database::
  load (T& obj, section& s)
  {
    return load_<T, id_common> (obj, s);
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  find (const typename object_traits<T>::id_type& id)
  {
    return find_<T, id_common> (id);
  }

  template <typename T>
  inline bool database::
  find (const typename object_traits<T>::id_type& id, T& obj)
  {
    return find_<T, id_common> (id, obj);
  }

  template <typename T>
  inline void database::
  reload (T& obj)
  {
    reload_<T, id_common> (obj);
  }

  template <typename T>
  inline void database::
  reload (T* p)
  {
    reload<T> (*p);
  }

  template <typename T, template <typename> class P>
  inline void database::
  reload (const P<T>& p)
  {
    reload (odb::pointer_traits< P<T> >::get_ref (p));
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  reload (const P<T, A1>& p)
  {
    reload (odb::pointer_traits< P<T, A1> >::get_ref (p));
  }

  template <typename T, template <typename> class P>
  inline void database::
  reload (P<T>& p)
  {
    reload (odb::pointer_traits< P<T> >::get_ref (p));
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  reload (P<T, A1>& p)
  {
    reload (odb::pointer_traits< P<T, A1> >::get_ref (p));
  }

  template <typename T>
  inline void database::
  reload (const typename object_traits<T>::pointer_type& pobj)
  {
    typedef typename object_traits<T>::pointer_type pointer_type;

    reload (odb::pointer_traits<pointer_type>::get_ref (pobj));
  }

  template <typename T>
  inline void database::
  update (T& obj)
  {
    update_<T, id_common> (obj);
  }

  template <typename T>
  inline void database::
  update (T* p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    update_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline void database::
  update (const P<T>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    update_<T, id_common> (pobj);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  update (const P<T, A1>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    update_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline void database::
  update (P<T>& p)
  {
    const P<T>& cr (p);
    update<T, P> (cr);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  update (P<T, A1>& p)
  {
    const P<T, A1>& cr (p);
    update<T, A1, P> (cr);
  }

  template <typename T>
  inline void database::
  update (const typename object_traits<T>::pointer_type& pobj)
  {
    update_<T, id_common> (pobj);
  }

  template <typename I>
  inline void database::
  update (I b, I e, bool cont)
  {
    update_<I, id_common> (b, e, cont);
  }

  template <typename T>
  inline void database::
  update (const T& obj, const section& s)
  {
    update_<T, id_common> (obj, s);
  }

  template <typename T>
  inline void database::
  erase (const typename object_traits<T>::id_type& id)
  {
    return erase_<T, id_common> (id);
  }

  template <typename T>
  inline void database::
  erase (T& obj)
  {
    return erase_<T, id_common> (obj);
  }

  template <typename T>
  inline void database::
  erase (T* p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    erase_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline void database::
  erase (const P<T>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    erase_<T, id_common> (pobj);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  erase (const P<T, A1>& p)
  {
    typedef typename object_traits<T>::pointer_type object_pointer;

    // The passed pointer should be the same or implicit-convertible
    // to the object pointer. This way we make sure the object pointer
    // does not assume ownership of the passed object.
    //
    const object_pointer& pobj (p);

    erase_<T, id_common> (pobj);
  }

  template <typename T, template <typename> class P>
  inline void database::
  erase (P<T>& p)
  {
    const P<T>& cr (p);
    erase<T, P> (cr);
  }

  template <typename T, typename A1, template <typename, typename> class P>
  inline void database::
  erase (P<T, A1>& p)
  {
    const P<T, A1>& cr (p);
    erase<T, A1, P> (cr);
  }

  template <typename T>
  inline void database::
  erase (const typename object_traits<T>::pointer_type& pobj)
  {
    erase_<T, id_common> (pobj);
  }

  template <typename T, typename I>
  inline void database::
  erase (I idb, I ide, bool cont)
  {
    erase_id_<I, T, id_common> (idb, ide, cont);
  }

  template <typename I>
  inline void database::
  erase (I ob, I oe, bool cont)
  {
    erase_object_<I, id_common> (ob, oe, cont);
  }

  template <typename T>
  inline unsigned long long database::
  erase_query ()
  {
    // T is always object_type.
    //
    return erase_query<T> (odb::query<T> ());
  }

  template <typename T>
  inline unsigned long long database::
  erase_query (const char* q)
  {
    // T is always object_type.
    //
    return erase_query<T> (odb::query<T> (q));
  }

  template <typename T>
  inline unsigned long long database::
  erase_query (const std::string& q)
  {
    // T is always object_type.
    //
    return erase_query<T> (odb::query<T> (q));
  }

  template <typename T>
  inline unsigned long long database::
  erase_query (const odb::query<T>& q)
  {
    // T is always object_type.
    //
    return object_traits_impl<T, id_common>::erase_query (*this, q);
  }

  template <typename T>
  inline result<T> database::
  query (bool cache)
  {
    return query<T> (odb::query<T> (), cache);
  }

  template <typename T>
  inline result<T> database::
  query (const char* q, bool cache)
  {
    return query<T> (odb::query<T> (q), cache);
  }

  template <typename T>
  inline result<T> database::
  query (const std::string& q, bool cache)
  {
    return query<T> (odb::query<T> (q), cache);
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  query_one ()
  {
    return query_one<T> (odb::query<T> ());
  }

  template <typename T>
  inline bool database::
  query_one (T& o)
  {
    return query_one<T> (odb::query<T> (), o);
  }

  template <typename T>
  inline T database::
  query_value ()
  {
    return query_value<T> (odb::query<T> ());
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  query_one (const char* q)
  {
    return query_one<T> (odb::query<T> (q));
  }

  template <typename T>
  inline bool database::
  query_one (const char* q, T& o)
  {
    return query_one<T> (odb::query<T> (q), o);
  }

  template <typename T>
  inline T database::
  query_value (const char* q)
  {
    return query_value<T> (odb::query<T> (q));
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  query_one (const std::string& q)
  {
    return query_one<T> (odb::query<T> (q));
  }

  template <typename T>
  inline bool database::
  query_one (const std::string& q, T& o)
  {
    return query_one<T> (odb::query<T> (q), o);
  }

  template <typename T>
  inline T database::
  query_value (const std::string& q)
  {
    return query_value<T> (odb::query<T> (q));
  }

  template <typename T>
  inline bool database::
  query_one (const odb::query<T>& q, T& o)
  {
    return query_one_<T, id_common> (q, o);
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type database::
  query_one (const odb::query<T>& q)
  {
    return query_one_<T, id_common> (q);
  }

  template <typename T>
  inline T database::
  query_value (const odb::query<T>& q)
  {
    return query_value_<T, id_common> (q);
  }

  template <typename T>
  inline prepared_query<T> database::
  prepare_query (const char* n, const char* q)
  {
    return prepare_query<T> (n, odb::query<T> (q));
  }

  template <typename T>
  inline prepared_query<T> database::
  prepare_query (const char* n, const std::string& q)
  {
    return prepare_query<T> (n, odb::query<T> (q));
  }

  template <typename T>
  inline prepared_query<T> database::
  prepare_query (const char* n, const odb::query<T>& q)
  {
    connection_type& c (transaction::current ().connection ());
    return c.prepare_query (n, q);
  }

  template <typename T>
  inline void database::
  cache_query (const prepared_query<T>& pq)
  {
    connection_type& c (transaction::current ().connection ());
    c.cache_query (pq);
  }

  template <typename T, typename P>
  inline void database::
  cache_query (const prepared_query<T>& pq, std::auto_ptr<P> params)
  {
    connection_type& c (transaction::current ().connection ());
    c.cache_query (pq, params);
  }

#ifdef ODB_CXX11
  template <typename T, typename P>
  inline void database::
  cache_query (const prepared_query<T>& pq, std::unique_ptr<P> params)
  {
    connection_type& c (transaction::current ().connection ());
    c.cache_query (pq, std::move (params));
  }
#endif

  template <typename T>
  inline prepared_query<T> database::
  lookup_query (const char* name) const
  {
    connection_type& c (transaction::current ().connection ());
    return c.lookup_query<T> (name);
  }

  template <typename T, typename P>
  inline prepared_query<T> database::
  lookup_query (const char* name, P*& params) const
  {
    connection_type& c (transaction::current ().connection ());
    return c.lookup_query<T, P> (name, params);
  }

  // Implementations (i.e., the *_() functions).
  //
  template <typename I, database_id DB>
  inline void database::
  persist_ (I b, I e, bool cont)
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

    typedef object_pointer_traits<value_type> opt;

    persist_<I, typename opt::object_type, id_common> (
      b, e, cont, typename opt::result_type ());
  }

  template <typename T, database_id DB>
  inline typename object_traits<T>::pointer_type database::
  find_ (const typename object_traits<T>::id_type& id)
  {
    // T is always object_type.
    //

    // Compiler error pointing here? Perhaps the object doesn't have the
    // default constructor?
    //
    return object_traits_impl<T, DB>::find (*this, id);
  }

  template <typename T, database_id DB>
  inline bool database::
  find_ (const typename object_traits<T>::id_type& id, T& obj)
  {
    // T is always object_type.
    //
    return object_traits_impl<T, DB>::find (*this, id, obj);
  }

  template <typename T, database_id DB>
  inline void database::
  update_ (T& obj)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;

    // Compiler error pointing here? Perhaps the object is readonly or
    // doesn't have an object id? Such objects cannot be updated.
    //
    object_traits_impl<object_type, DB>::update (*this, obj);
  }

  template <typename T, database_id DB>
  inline void database::
  update_ (const typename object_traits<T>::pointer_type& pobj)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;
    typedef typename object_traits<T>::pointer_type pointer_type;

    T& obj (pointer_traits<pointer_type>::get_ref (pobj));

    // Compiler error pointing here? Perhaps the object is readonly or
    // doesn't have an object id? Such objects cannot be updated.
    //
    object_traits_impl<object_type, DB>::update (*this, obj);
  }

  template <typename T, database_id DB>
  inline void database::
  erase_ (const typename object_traits<T>::id_type& id)
  {
    // T is always object_type.
    //
    object_traits_impl<T, DB>::erase (*this, id);
  }

  template <typename T, database_id DB>
  inline void database::
  erase_ (T& obj)
  {
    // T can be const T while object_type will always be T.
    //
    typedef typename object_traits<T>::object_type object_type;

    object_traits_impl<object_type, DB>::erase (*this, obj);
  }

  template <typename T, database_id DB>
  inline void database::
  erase_ (const typename object_traits<T>::pointer_type& pobj)
  {
    typedef typename object_traits<T>::pointer_type pointer_type;

    erase_<T, DB> (pointer_traits<pointer_type>::get_ref (pobj));
  }

  template <typename T, database_id DB, typename Q>
  inline typename object_traits<T>::pointer_type database::
  query_one_ (const Q& q)
  {
    result<T> r (query_<T, DB>::call (*this, q));

    // We still have to cache the result since loading the object
    // may result in loading of it's related objects and that would
    // invalidate the result even for just getting the 'end' status.
    //
    r.cache ();

    return r.one ();
  }

  template <typename T, database_id DB, typename Q>
  inline bool database::
  query_one_ (const Q& q, T& o)
  {
    result<T> r (query_<T, DB>::call (*this, q));
    r.cache (); // See above.
    return r.one (o);
  }

  template <typename T, database_id DB, typename Q>
  inline T database::
  query_value_ (const Q& q)
  {
    result<T> r (query_<T, DB>::call (*this, q));
    r.cache (); // See above.

    // Compiler error pointing here? The object must be default-constructible
    // in order to use the return-by-value API.
    //
    T o;
    r.value (o);
    return o;
  }

  // execute()
  //
  inline unsigned long long database::
  execute (const char* statement)
  {
    return execute (statement, std::strlen (statement));
  }

  inline unsigned long long database::
  execute (const std::string& statement)
  {
    return execute (statement.c_str (), statement.size ());
  }
}
