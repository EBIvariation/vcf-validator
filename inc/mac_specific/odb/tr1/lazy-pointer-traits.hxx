// file      : odb/tr1/lazy-pointer-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TR1_LAZY_POINTER_TRAITS_HXX
#define ODB_TR1_LAZY_POINTER_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/pointer-traits.hxx>
#include <odb/tr1/lazy-ptr.hxx>

namespace odb
{
  template <typename T>
  class pointer_traits<tr1::lazy_shared_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_shared;
    static const bool lazy = true;

    typedef T element_type;
    typedef tr1::lazy_shared_ptr<element_type> pointer_type;
    typedef std::tr1::shared_ptr<element_type> eager_pointer_type;

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
  class pointer_traits<tr1::lazy_weak_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_weak;
    static const bool lazy = true;

    typedef T element_type;
    typedef tr1::lazy_weak_ptr<element_type> pointer_type;
    typedef tr1::lazy_shared_ptr<element_type> strong_pointer_type;
    typedef std::tr1::weak_ptr<element_type> eager_pointer_type;

    static strong_pointer_type
    lock (const pointer_type& p)
    {
      return p.lock ();
    }
  };
}

#include <odb/post.hxx>

#endif // ODB_TR1_LAZY_POINTER_TRAITS_HXX
