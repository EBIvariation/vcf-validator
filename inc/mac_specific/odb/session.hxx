// file      : odb/session.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SESSION_HXX
#define ODB_SESSION_HXX

#include <odb/pre.hxx>

#include <map>
#include <typeinfo>

#include <odb/traits.hxx>
#include <odb/forward.hxx>

#include <odb/details/shared-ptr.hxx>
#include <odb/details/type-info.hxx>

#include <odb/details/export.hxx>

namespace odb
{
  class LIBODB_EXPORT session
  {
  public:
    typedef odb::database database_type;

    // If the make_current argument is true, then set the current thread's
    // session to this session. If another session is already in effect,
    // throw the already_in_session exception.
    //
    session (bool make_current = true);

    // Reset the current thread's session if it is this session.
    //
    ~session ();

    // Current session.
    //
  public:
    // Return true if there is a session in effect in the current
    // thread.
    //
    static bool
    has_current () {return current_pointer () != 0;}

    // Get current thread's session. Throw if no session is in effect.
    //
    static session&
    current ();

    // Set current thread's session.
    //
    static void
    current (session& s) {current_pointer (&s);}

    // Revert to the no session in effect state for the current thread.
    //
    static void
    reset_current () {current_pointer (0);}

    // Pointer versions.
    //
    static session*
    current_pointer ();

    static void
    current_pointer (session*);

    // Copying or assignment of sessions is not supported.
    //
  private:
    session (const session&);
    session& operator= (const session&);

  public:
    struct LIBODB_EXPORT object_map_base: details::shared_base
    {
      virtual
      ~object_map_base ();
    };

    template <typename T>
    struct object_map: object_map_base,
                       std::map<typename object_traits<T>::id_type,
                                typename object_traits<T>::pointer_type>
    {
    };

    // Object cache.
    //
  public:
    // Position in the cache of the inserted element.
    //
    template <typename T>
    struct cache_position;

    template <typename T>
    cache_position<T>
    cache_insert (database_type&,
                  const typename object_traits<T>::id_type&,
                  const typename object_traits<T>::pointer_type&);

    template <typename T>
    typename object_traits<T>::pointer_type
    cache_find (database_type&,
                const typename object_traits<T>::id_type&) const;

    template <typename T>
    void
    cache_erase (const cache_position<T>&);

    template <typename T>
    void
    cache_erase (database_type&, const typename object_traits<T>::id_type&);

    // Low-level object cache access (iteration, etc).
    //
  public:
    typedef std::map<const std::type_info*,
                     details::shared_ptr<object_map_base>,
                     details::type_info_comparator> type_map;

    typedef std::map<database_type*, type_map> database_map;

    database_map&
    map () {return db_map_;}

    const database_map&
    map () const {return db_map_;}

    // Static cache API as expected by the rest of ODB.
    //
  public:
    // Position in the cache of the inserted element. The requirements
    // for this class template are: default and copy-constructible as
    // well as copy-assignable. The default constructor creates an
    // empty/NULL position.
    //
    template <typename T>
    struct cache_position
    {
      typedef object_map<T> map;
      typedef typename map::iterator iterator;

      cache_position (): map_ (0) {}
      cache_position (map& m, const iterator& p): map_ (&m), pos_ (p) {}

      cache_position&
      operator= (const cache_position& p)
      {
        // It might not be ok to use an uninitialized iterator on the rhs.
        //
        if (p.map_ != 0)
          pos_ = p.pos_;
        map_ = p.map_;
        return *this;
      }

      map* map_;
      iterator pos_;
    };

    // The following cache management functions are all static to
    // allow for a custom notion of a current session. The erase()
    // function is called to remove the object if the operation
    // that caused it to be inserted (e.g., load) failed.
    //
    template <typename T>
    static cache_position<T>
    _cache_insert (database_type&,
                   const typename object_traits<T>::id_type&,
                   const typename object_traits<T>::pointer_type&);

    template <typename T>
    static typename object_traits<T>::pointer_type
    _cache_find (database_type&, const typename object_traits<T>::id_type&);

    template <typename T>
    static void
    _cache_erase (const cache_position<T>&);

    // Notifications. These are called after per-object callbacks for
    // post_{persist, load, update, erase} events.
    //
    template <typename T>
    static void
    _cache_persist (const cache_position<T>&) {}

    template <typename T>
    static void
    _cache_load (const cache_position<T>&) {}

    template <typename T>
    static void
    _cache_update (database_type&, const T&) {}

    template <typename T>
    static void
    _cache_erase (database_type&, const typename object_traits<T>::id_type&);

  protected:
    database_map db_map_;
  };
}

#include <odb/session.ixx>
#include <odb/session.txx>

#include <odb/post.hxx>

#endif // ODB_SESSION_HXX
