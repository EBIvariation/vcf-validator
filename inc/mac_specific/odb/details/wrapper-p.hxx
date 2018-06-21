// file      : odb/details/wrapper-p.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WRAPPER_P_HXX
#define ODB_DETAILS_WRAPPER_P_HXX

#include <odb/pre.hxx>

#include <odb/wrapper-traits.hxx>

#include <odb/details/meta/answer.hxx>

namespace odb
{
  namespace details
  {
    // GCC doesn't like these to be inside wrapper_p.
    //
    template <typename T>
    meta::no
    wrapper_p_test (...);

    template <typename T>
    meta::yes
    wrapper_p_test (typename wrapper_traits<T>::wrapped_type*);

    template <typename T>
    struct wrapper_p
    {
      static const bool r =
        sizeof (wrapper_p_test<T> (0)) == sizeof (meta::yes);
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_WRAPPER_P_HXX
