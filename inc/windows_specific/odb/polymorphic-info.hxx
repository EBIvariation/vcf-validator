// file      : odb/polymorphic-info.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_POLYMORPHIC_INFO_HXX
#define ODB_POLYMORPHIC_INFO_HXX

#include <odb/pre.hxx>

#include <cstddef>  // std::size_t
#include <typeinfo>

#include <odb/forward.hxx> // database, connection
#include <odb/schema-version.hxx>
#include <odb/traits.hxx>

namespace odb
{
  template <typename R>
  struct polymorphic_abstract_info
  {
    typedef void (*section_load) (odb::connection&, R&, bool top);
    typedef void (*section_update) (odb::connection&, const R&);

    struct section_functions
    {
      section_load load;
      section_update update;
    };

    struct section_list
    {
      std::size_t count;
      const section_functions* functions;
    };

  public:
    polymorphic_abstract_info (const std::type_info& t,
                               const polymorphic_abstract_info* b,
                               const section_list* s)
        : type (t), base (b), sections (s) {}

    bool
    derived (const polymorphic_abstract_info& b) const
    {
      for (const polymorphic_abstract_info* p (base); p != 0; p = p->base)
        if (&b == p)
          return true;

      return false;
    }

    // Find the "most overridden" section functions.
    //
    section_load
    find_section_load (std::size_t index) const
    {
      for (const polymorphic_abstract_info* b (this); b != 0; b = b->base)
        if (b->sections != 0 &&
            index < b->sections->count &&
            b->sections->functions[index].load != 0)
          return b->sections->functions[index].load;

      return 0;
    }

    section_update
    find_section_update (std::size_t index) const
    {
      for (const polymorphic_abstract_info* b (this); b != 0; b = b->base)
        if (b->sections != 0 &&
            index < b->sections->count &&
            b->sections->functions[index].update != 0)
          return b->sections->functions[index].update;

      return 0;
    }

    bool
    final_section_update (const polymorphic_abstract_info& i,
                          std::size_t index) const
    {
      return i.sections != 0 &&
        index < i.sections->count &&
        i.sections->functions[index].update != 0 &&
        i.sections->functions[index].update == find_section_update (index);
    }

  public:
    const std::type_info& type;
    const polymorphic_abstract_info* base;

    // Sections.
    //
    // There could be "concrete" (i.e., not overridden) section in an
    // abstract class. Which means the section table has to be in
    // abstract_info.
    //
    const section_list* sections;
  };

  template <typename R>
  struct polymorphic_concrete_info: polymorphic_abstract_info<R>
  {
    // Have to use access::object_traits directly because of VC10.
    //
    typedef R root_type;
    typedef access::object_traits<root_type> root_traits;
    typedef typename root_traits::id_type id_type;
    typedef typename root_traits::pointer_type pointer_type;
    typedef typename root_traits::discriminator_type discriminator_type;

    typedef typename polymorphic_abstract_info<R>::section_list section_list;

    enum call_type
    {
      call_callback, // arg points to callback event.
      call_persist,  // arg is not used.
      call_update,   // arg is not used.
      call_find,     // arg points to object id.
      call_reload,   // arg is not used.
      call_load,     // arg points to depth.
      call_erase     // arg points to object id.
    };

    typedef pointer_type (*create_function) ();
    typedef bool (*dispatch_function) (
      call_type, odb::database&, const root_type*, const void* arg);
    typedef void (*delayed_loader_function) (
      odb::database&,
      const id_type&,
      root_type&,
      const schema_version_migration*);

  public:
    polymorphic_concrete_info (const std::type_info& t,
                               const polymorphic_abstract_info<R>* b,
                               const section_list* s,
                               const discriminator_type& d,
                               create_function cf,
                               dispatch_function df,
                               delayed_loader_function dlf)
        : polymorphic_abstract_info<R> (t, b, s),
          discriminator (d),
          create (cf), dispatch (df), delayed_loader (dlf)
    {
    }

  public:
    discriminator_type discriminator;
    create_function create;
    dispatch_function dispatch;
    delayed_loader_function delayed_loader;
  };

  // Register concrete type T in the root's map.
  //
  template <typename T, database_id DB>
  struct polymorphic_entry
  {
    typedef T object_type;
    typedef object_traits_impl<object_type, DB> object_traits;
    typedef typename object_traits::root_type root_type;

    polymorphic_entry ();
    ~polymorphic_entry ();
  };

  // Helper functions that either return the concrete info or NULL
  // depending on what kind of info we pass (used in query support).
  //
  template <typename R>
  inline const polymorphic_concrete_info<R>*
  polymorphic_info (const polymorphic_concrete_info<R>& i)
  {
    return &i;
  }

  template <typename R>
  inline const polymorphic_concrete_info<R>*
  polymorphic_info (const polymorphic_abstract_info<R>&)
  {
    return 0;
  }
}

#include <odb/post.hxx>

#endif // ODB_POLYMORPHIC_INFO_HXX
