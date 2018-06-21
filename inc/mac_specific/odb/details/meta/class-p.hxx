// file      : odb/details/meta/class-p.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_CLASS_HXX
#define ODB_DETAILS_META_CLASS_HXX

#include <odb/pre.hxx>

#include <odb/details/meta/answer.hxx>

namespace odb
{
  namespace details
  {
    namespace meta
    {
      // g++ cannot have these inside class_p.
      //
      template <typename X> no class_p_test (...);
      template <typename X> yes class_p_test (void (X::*) ());

      template <typename X>
      struct class_p
      {
        static const bool result =
          sizeof (class_p_test<X> (0)) == sizeof (yes);
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_CLASS_HXX
