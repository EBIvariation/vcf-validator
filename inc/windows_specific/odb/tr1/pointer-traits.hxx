// file      : odb/tr1/pointer-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TR1_POINTER_TRAITS_HXX
#define ODB_TR1_POINTER_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11

// In VC++ std::shared_ptr and std::tr1::shared_ptr is the same class
// template. One is just a using-declaration for the other.
//
#if !(defined(ODB_CXX11) && defined(_MSC_VER))

//
// This header assumes that the necessary TR1 header has already
// been included.
//

#include <odb/pointer-traits.hxx>
#include <odb/details/meta/remove-const.hxx>

namespace odb
{
  // Specialization for std::tr1::shared_ptr.
  //
  template <typename T>
  class pointer_traits<std::tr1::shared_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_shared;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::tr1::shared_ptr<element_type> pointer_type;
    typedef std::tr1::shared_ptr<const element_type> const_pointer_type;
    typedef typename odb::details::meta::remove_const<element_type>::result
    unrestricted_element_type;
    typedef std::tr1::shared_ptr<unrestricted_element_type>
    unrestricted_pointer_type;
    typedef smart_ptr_guard<pointer_type> guard;

    static element_type*
    get_ptr (const pointer_type& p)
    {
      return p.get ();
    }

    static element_type&
    get_ref (const pointer_type& p)
    {
      return *p;
    }

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    static unrestricted_pointer_type
    const_pointer_cast (const pointer_type& p)
    {
      return std::tr1::const_pointer_cast<unrestricted_element_type> (p);
    }

    template <typename T1>
    static std::tr1::shared_ptr<T1>
    static_pointer_cast (const pointer_type& p)
    {
      return std::tr1::static_pointer_cast<T1> (p);
    }

    template <typename T1>
    static std::tr1::shared_ptr<T1>
    dynamic_pointer_cast (const pointer_type& p)
    {
      return std::tr1::dynamic_pointer_cast<T1> (p);
    }

  public:
    static void*
    allocate (std::size_t n)
    {
      return operator new (n);
    }

    static void
    free (void* p)
    {
      operator delete (p);
    }
  };

  // Specialization for std::tr1::weak_ptr.
  //
  template <typename T>
  class pointer_traits<std::tr1::weak_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_weak;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::tr1::weak_ptr<element_type> pointer_type;
    typedef std::tr1::shared_ptr<element_type> strong_pointer_type;

    static strong_pointer_type
    lock (const pointer_type& p)
    {
      return p.lock ();
    }
  };
}

#endif // !(ODB_CXX11 && _MSC_VER)

#include <odb/post.hxx>

#endif // ODB_TR1_POINTER_TRAITS_HXX
