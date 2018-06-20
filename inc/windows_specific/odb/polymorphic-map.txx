// file      : odb/polymorphic-map.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/exceptions.hxx> // no_type_info

namespace odb
{
  //
  // polymorphic_map
  //

  template <typename R>
  const typename polymorphic_map<R>::info_type& polymorphic_map<R>::
  find (const std::type_info& t) const
  {
    typename type_map::const_iterator i (type_map_.find (&t));

    if (i != type_map_.end ())
      return *i->second;
    else
      throw no_type_info ();
  }

  template <typename R>
  const typename polymorphic_map<R>::info_type& polymorphic_map<R>::
  find (const discriminator_type& d) const
  {
    typename discriminator_map::const_iterator i (
      discriminator_map_.find (&d));

    if (i != discriminator_map_.end ())
      return *i->second;
    else
      throw no_type_info ();
  }

  //
  // polymorphic_entry_impl
  //

  template <typename R, database_id DB>
  void polymorphic_entry_impl<R, DB>::
  insert (const info_type& i)
  {
    // VC10 cannot grok constructor call syntax here.
    //
    polymorphic_map<root_type>*& pm = root_traits::map;

    if (pm == 0)
      pm = new polymorphic_map<root_type>;
    else
      pm->ref_count_++;

    pm->type_map_[&i.type] = &i;
    pm->discriminator_map_[&i.discriminator] = &i;
  }

  template <typename R, database_id DB>
  void polymorphic_entry_impl<R, DB>::
  erase (const info_type& i)
  {
    // VC10 cannot grok constructor call syntax here.
    //
    polymorphic_map<root_type>*& pm = root_traits::map;

    pm->discriminator_map_.erase (&i.discriminator);
    pm->type_map_.erase (&i.type);

    if (--pm->ref_count_ == 0)
    {
      delete pm;
      pm = 0;
    }
  }
}
