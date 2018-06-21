// file      : odb/std-unordered-set-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STD_UNORDERED_SET_TRAITS_HXX
#define ODB_STD_UNORDERED_SET_TRAITS_HXX

#include <odb/pre.hxx>

#include <utility>       // std::move
#include <unordered_set>

#include <odb/container-traits.hxx>

namespace odb
{
  template <typename V, typename H, typename P, typename A>
  class access::container_traits<std::unordered_set<V, H, P, A>>
  {
  public:
    static const container_kind kind = ck_set;
    static const bool smart = false;

    typedef std::unordered_set<V, H, P, A> container_type;
    typedef V value_type;

    typedef set_functions<value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (*i);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        value_type v;
        more = f.select (v);
        c.insert (std::move (v));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (*i);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };

  // @@ Does multiset preserve insertion order of equal elements? The
  // current implementation in the generated code does not guarantee
  // this.
  //
  template <typename V, typename H, typename P, typename A>
  class access::container_traits<std::unordered_multiset<V, H, P, A>>
  {
  public:
    static const container_kind kind = ck_multiset;
    static const bool smart = false;

    typedef std::unordered_multiset<V, H, P, A> container_type;
    typedef V value_type;

    typedef set_functions<value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (*i);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      while (more)
      {
        value_type v;
        more = f.select (v);
        c.insert (std::move (v));
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      for (typename container_type::const_iterator i (c.begin ()),
             e (c.end ()); i != e; ++i)
        f.insert (*i);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };
}

#include <odb/post.hxx>

#endif // ODB_STD_UNORDERED_SET_TRAITS_HXX
