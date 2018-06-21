// file      : odb/tr1/wrapper-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TR1_WRAPPER_TRAITS_HXX
#define ODB_TR1_WRAPPER_TRAITS_HXX

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

#include <odb/wrapper-traits.hxx>

namespace odb
{
  // Specialization for std::tr1::shared_ptr.
  //
  template <typename T>
  class wrapper_traits< std::tr1::shared_ptr<T> >
  {
  public:
    typedef T wrapped_type;
    typedef std::tr1::shared_ptr<T> wrapper_type;

    // T can be const.
    //
    typedef
    typename odb::details::meta::remove_const<T>::result
    unrestricted_wrapped_type;

    static const bool null_handler = true;
    static const bool null_default = false;

    static bool
    get_null (const wrapper_type& p)
    {
      return !p;
    }

    static void
    set_null (wrapper_type& p)
    {
      p.reset ();
    }

    static const wrapped_type&
    get_ref (const wrapper_type& p)
    {
      return *p;
    }

    static unrestricted_wrapped_type&
    set_ref (wrapper_type& p)
    {
      if (!p)
        p.reset (new unrestricted_wrapped_type);

      return const_cast<unrestricted_wrapped_type&> (*p);
    }
  };
}

#endif // !(ODB_CXX11 && _MSC_VER)

#include <odb/post.hxx>

#endif // ODB_TR1_WRAPPER_TRAITS_HXX
