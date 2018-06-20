// file      : odb/session.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/exceptions.hxx>

namespace odb
{
  template <typename T>
  inline void session::
  cache_erase (const cache_position<T>& p)
  {
    // @@ Empty maps are not cleaned up by this version of erase.
    //
    if (p.map_ != 0)
      p.map_->erase (p.pos_);
  }

  template <typename T>
  inline typename session::cache_position<T> session::
  _cache_insert (database_type& db,
                 const typename object_traits<T>::id_type& id,
                 const typename object_traits<T>::pointer_type& obj)
  {
    if (session* s = current_pointer ())
      return s->cache_insert<T> (db, id, obj);
    else
      return cache_position<T> ();
  }

  template <typename T>
  inline typename object_traits<T>::pointer_type session::
  _cache_find (database_type& db, const typename object_traits<T>::id_type& id)
  {
    typedef typename object_traits<T>::pointer_type pointer_type;

    if (const session* s = current_pointer ())
      return s->cache_find<T> (db, id);
    else
      return pointer_type ();
  }

  template <typename T>
  inline void session::
  _cache_erase (const cache_position<T>& p)
  {
    // @@ Empty maps are not cleaned up by this version of erase.
    //
    if (p.map_ != 0)
      p.map_->erase (p.pos_);
  }

  template <typename T>
  inline void session::
  _cache_erase (database_type& db,
                const typename object_traits<T>::id_type& id)
  {
    if (session* s = current_pointer ())
      s->cache_erase<T> (db, id);
  }
}
