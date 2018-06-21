// file      : odb/container-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_CONTAINER_TRAITS_HXX
#define ODB_CONTAINER_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>
#include <odb/details/config.hxx> // ODB_CXX11

namespace odb
{
  // Keep this enum synchronized with the one in odb/odb/context.hxx.
  //
  enum container_kind
  {
    ck_ordered,
    ck_set,
    ck_multiset,
    ck_map,
    ck_multimap
  };

  //
  // Container API provided by the generated code.
  //

  // Ordered containers.
  //
  template <typename I, typename V>
  struct ordered_functions
  {
    typedef I index_type;
    typedef V value_type;

    // Return true if the order is preserved in the database. If the
    // order is not preserved, then the index argument in the functions
    // below is not used.
    //
    bool
    ordered () const
    {
      return ordered_;
    }

    void
    insert (I index, const V& value) const
    {
      insert_ (index, value, data_);
    }

    bool
    select (I& next_index, V& next_value) const
    {
      return select_ (next_index, next_value, data_);
    }

    void
    delete_ () const
    {
      delete__ (data_);
    }

    // Implementation details.
    //
  public:
    ordered_functions (void* data): data_ (data) {}

  public:
    void* data_;
    bool ordered_;

    void (*insert_) (I, const V&, void*);
    bool (*select_) (I&, V&, void*);
    void (*delete__) (void*);
  };

  template <typename I, typename V>
  struct smart_ordered_functions
  {
    typedef I index_type;
    typedef V value_type;

    void
    insert (I index, const V& value) const
    {
      insert_ (index, value, data_);
    }

    bool
    select (I& next_index, V& next_value) const
    {
      return select_ (next_index, next_value, data_);
    }

    void
    update (I index, const V& value) const
    {
      update_ (index, value, data_);
    }

    // Delete all the elements starting with the specified index. To
    // delete everything, pass 0.
    //
    void
    delete_ (I start_index) const
    {
      delete__ (start_index, data_);
    }

    // Implementation details.
    //
  public:
    smart_ordered_functions (void* data) : data_ (data) {}

  public:
    void* data_;

    void (*insert_) (I, const V&, void*);
    bool (*select_) (I&, V&, void*);
    void (*update_) (I, const V&, void*);
    void (*delete__) (I, void*);
  };

  // Set/multiset containers.
  //
  template <typename V>
  struct set_functions
  {
    typedef V value_type;

    void
    insert (const V& value) const
    {
      insert_ (value, data_);
    }

    bool
    select (V& next_value) const
    {
      return select_ (next_value, data_);
    }

    void
    delete_ () const
    {
      delete__ (data_);
    }

    // Implementation details.
    //
  public:
    set_functions (void* data): data_ (data) {}

  public:
    void* data_;

    void (*insert_) (const V&, void*);
    bool (*select_) (V&, void*);
    void (*delete__) (void*);
  };

  // Map/multimap containers.
  //
  template <typename K, typename V>
  struct map_functions
  {
    typedef K key_type;
    typedef V value_type;

    void
    insert (const K& key, const V& value) const
    {
      insert_ (key, value, data_);
    }

    bool
    select (K& next_key, V& next_value) const
    {
      return select_ (next_key, next_value, data_);
    }

    void
    delete_ () const
    {
      delete__ (data_);
    }

    // Implementation details.
    //
  public:
    map_functions (void* data): data_ (data) {}

  public:
    void* data_;

    void (*insert_) (const K&, const V&, void*);
    bool (*select_) (K&, V&, void*);
    void (*delete__) (void*);
  };
}

#include <odb/post.hxx>

#include <odb/std-map-traits.hxx>
#include <odb/std-set-traits.hxx>
#include <odb/std-list-traits.hxx>
#include <odb/std-vector-traits.hxx>
#include <odb/std-deque-traits.hxx>

#ifdef ODB_CXX11
#  include <odb/std-array-traits.hxx>
#  include <odb/std-forward-list-traits.hxx>
#  include <odb/std-unordered-map-traits.hxx>
#  include <odb/std-unordered-set-traits.hxx>
#endif

#endif // ODB_CONTAINER_TRAITS_HXX
