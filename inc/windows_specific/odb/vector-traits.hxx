// file      : odb/vector-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VECTOR_TRAITS_HXX
#define ODB_VECTOR_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/vector.hxx>
#include <odb/vector-impl.hxx>
#include <odb/container-traits.hxx>
#include <odb/transaction.hxx>

namespace odb
{
  template <typename V, typename A LIBODB_VECTOR_ARG_DECL>
  class access::container_traits<vector<V, A LIBODB_VECTOR_ARG_USE> >
  {
  public:
    static const container_kind kind = ck_ordered;
    static const bool smart = true;

    typedef vector<V, A> container_type;

    typedef V value_type;
    typedef typename container_type::size_type index_type;

    typedef smart_ordered_functions<index_type, value_type> functions;
    typedef ordered_functions<index_type, value_type> dumb_functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      for (index_type i (0), n (c.size ()); i < n; ++i)
        f.insert (i, c[i]);

      // Now that this container is persistent, start tracking changes.
      //
      c._start ();
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      // Stop tracking changes.
      //
      c._stop ();

      // Load.
      //
      c.clear ();
      while (more)
      {
        index_type dummy;
        c.push_back (value_type ());
        more = f.select (dummy, c.modify_back ());
      }

      // Start tracking changes.
      //
      c._start ();
    }

    static bool
    changed (const container_type&);

    static void
    update (const container_type&, const functions&);

    static void
    erase (const container_type* c, const functions& f)
    {
      f.delete_ (0);

      // Stop tracking changes.
      //
      if (c != 0)
        c->_stop ();
    }

    // Version of load() for dumb functions. Used to support
    // inverse members of the container type. The implementation
    // is identical to the smart one except we don't turn off/on
    // change tracking.
    //
    static void
    load (container_type& c, bool more, const dumb_functions& f)
    {
      c.clear ();

      while (more)
      {
        index_type dummy;
        c.push_back (value_type ());
        more = f.select (dummy, c.modify_back ());
      }
    }
  };
}

#include <odb/vector-traits.txx>

#include <odb/post.hxx>

#endif // ODB_VECTOR_TRAITS_HXX
