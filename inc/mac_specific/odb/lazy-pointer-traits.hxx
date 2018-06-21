// file      : odb/lazy-pointer-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_LAZY_POINTER_TRAITS_HXX
#define ODB_LAZY_POINTER_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/pointer-traits.hxx>
#include <odb/lazy-ptr.hxx>
#include <odb/details/config.hxx> // ODB_CXX11

namespace odb
{
  template <typename T>
  class pointer_traits< lazy_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_raw;
    static const bool lazy = true;

    typedef T element_type;
    typedef lazy_ptr<element_type> pointer_type;
    typedef element_type* eager_pointer_type;

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    template <class O /* = T */>
    static typename object_traits<O>::id_type
    object_id (const pointer_type& p)
    {
      return p.template object_id<O> ();
    }
  };

  template <typename T>
  class pointer_traits< lazy_auto_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_unique;
    static const bool lazy = true;

    typedef T element_type;
    typedef lazy_auto_ptr<element_type> pointer_type;
    typedef std::auto_ptr<element_type> eager_pointer_type;

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    template <class O /* = T */>
    static typename object_traits<O>::id_type
    object_id (const pointer_type& p)
    {
      return p.template object_id<O> ();
    }
  };

#ifdef ODB_CXX11
  template <typename T, typename D>
  class pointer_traits<lazy_unique_ptr<T, D>>
  {
  public:
    static const pointer_kind kind = pk_unique;
    static const bool lazy = true;

    typedef T element_type;
    typedef lazy_unique_ptr<element_type, D> pointer_type;
    typedef std::unique_ptr<element_type, D> eager_pointer_type;

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    template <class O /* = T */>
    static typename object_traits<O>::id_type
    object_id (const pointer_type& p)
    {
      return p.template object_id<O> ();
    }
  };

  template <typename T>
  class pointer_traits<lazy_shared_ptr<T>>
  {
  public:
    static const pointer_kind kind = pk_shared;
    static const bool lazy = true;

    typedef T element_type;
    typedef lazy_shared_ptr<element_type> pointer_type;
    typedef std::shared_ptr<element_type> eager_pointer_type;

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    template <class O /* = T */>
    static typename object_traits<O>::id_type
    object_id (const pointer_type& p)
    {
      return p.template object_id<O> ();
    }
  };

  template <typename T>
  class pointer_traits<lazy_weak_ptr<T>>
  {
  public:
    static const pointer_kind kind = pk_weak;
    static const bool lazy = true;

    typedef T element_type;
    typedef lazy_weak_ptr<element_type> pointer_type;
    typedef lazy_shared_ptr<element_type> strong_pointer_type;
    typedef std::weak_ptr<element_type> eager_pointer_type;

    static strong_pointer_type
    lock (const pointer_type& p)
    {
      return p.lock ();
    }
  };
#endif // ODB_CXX11
}

#include <odb/post.hxx>

#endif // ODB_LAZY_POINTER_TRAITS_HXX
