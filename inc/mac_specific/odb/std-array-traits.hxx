// file      : odb/std-array-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STD_ARRAY_TRAITS_HXX
#define ODB_STD_ARRAY_TRAITS_HXX

#include <odb/pre.hxx>

#include <array>
#include <cstddef> // std::size_t
#include <cassert>

#include <odb/container-traits.hxx>

namespace odb
{
  template <typename V, std::size_t N>
  class access::container_traits<std::array<V, N>>
  {
  public:
    static const container_kind kind = ck_ordered;
    static const bool smart = false;

    typedef std::array<V, N> container_type;

    typedef V value_type;
    typedef typename container_type::size_type index_type;

    typedef ordered_functions<index_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (index_type i (0); i < N; ++i)
        f.insert (i, c[i]);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      index_type i (0);

      for (; more && i < N; ++i)
      {
        index_type dummy;
        more = f.select (dummy, c[i]);
      }

      assert (!more && i == N);
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      for (index_type i (0); i < N; ++i)
        f.insert (i, c[i]);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };
}

#include <odb/post.hxx>

#endif // ODB_STD_ARRAY_TRAITS_HXX
