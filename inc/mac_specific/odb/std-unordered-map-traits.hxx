// file      : odb/std-unordered-map-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STD_UNORDERED_MAP_TRAITS_HXX
#define ODB_STD_UNORDERED_MAP_TRAITS_HXX

#include <odb/pre.hxx>

#include <utility>       // std::move
#include <unordered_map>

#include <odb/container-traits.hxx>

namespace odb
{
  template <typename K, typename V, typename H, typename P, typename A>
  class access::container_traits<std::unordered_map<K, V, H, P, A>>
  {
  public:
    static const container_kind kind = ck_map;
    static const bool smart = false;

    typedef std::unordered_map<K, V, H, P, A> container_type;

    typedef K key_type;
    typedef V value_type;
    typedef typename container_type::value_type pair_type;

    typedef map_functions<key_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (i->first, i->second);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        key_type k;
        value_type v;
        more = f.select (k, v);
        c.insert (pair_type (std::move (k), std::move (v)));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (i->first, i->second);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };

  // @@ Does multimap preserve insertion order of equal elements? The
  // current implementation in the generated code does not guarantee
  // this.
  //
  template <typename K, typename V, typename H, typename P, typename A>
  class access::container_traits<std::unordered_multimap<K, V, H, P, A>>
  {
  public:
    static const container_kind kind = ck_multimap;
    static const bool smart = false;

    typedef std::unordered_multimap<K, V, H, P, A> container_type;

    typedef K key_type;
    typedef V value_type;
    typedef typename container_type::value_type pair_type;

    typedef map_functions<key_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (i->first, i->second);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        key_type k;
        value_type v;
        more = f.select (k, v);
        c.insert (pair_type (std::move (k), std::move (v)));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (i->first, i->second);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };
}

#include <odb/post.hxx>

#endif // ODB_STD_UNORDERED_MAP_TRAITS_HXX
