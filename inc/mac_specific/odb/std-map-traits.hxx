// file      : odb/std-map-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STD_MAP_TRAITS_HXX
#define ODB_STD_MAP_TRAITS_HXX

#include <odb/pre.hxx>

#include <map>
#include <utility> // std::move

#include <odb/container-traits.hxx>
#include <odb/details/config.hxx>   // ODB_CXX11

namespace odb
{
  template <typename K, typename V, typename C, typename A>
  class access::container_traits<std::map<K, V, C, A> >
  {
  public:
    static const container_kind kind = ck_map;
    static const bool smart = false;

    typedef std::map<K, V, C, A> container_type;

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
#ifdef ODB_CXX11
        c.insert (pair_type (std::move (k), std::move (v)));
#else
        c.insert (pair_type (k, v));
#endif
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

  // C++03 does not guarantee insertion order of equal values but C++11
  // changes that. The current implementation in the generated code does
  // not guarantee this either.
  //
  template <typename K, typename V, typename C, typename A>
  class access::container_traits<std::multimap<K, V, C, A> >
  {
  public:
    static const container_kind kind = ck_multimap;
    static const bool smart = false;

    typedef std::multimap<K, V, C, A> container_type;

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
#ifdef ODB_CXX11
        c.insert (pair_type (std::move (k), std::move (v)));
#else
        c.insert (pair_type (k, v));
#endif
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

#endif // ODB_STD_MAP_TRAITS_HXX
