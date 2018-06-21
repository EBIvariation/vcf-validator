// file      : odb/details/meta/polymorphic-p.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_POLYMORPHIC_HXX
#define ODB_DETAILS_META_POLYMORPHIC_HXX

#include <odb/pre.hxx>

#include <odb/details/meta/class-p.hxx>
#include <odb/details/meta/remove-const-volatile.hxx>

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename CVX>
      struct polymorphic_p
      {
        typedef typename remove_const_volatile<CVX>::result X;

        template <typename Y, bool C>
        struct impl
        {
          static const bool result = false;
        };

        template <typename Y>
        struct impl<Y, true>
        {
          struct t1: Y
          {
            t1 ();
          };

          struct t2: Y
          {
            t2 ();

            virtual
            ~t2 () throw ();
          };

          static const bool result = sizeof (t1) == sizeof (t2);
        };

        static const bool result = impl<X, class_p<X>::result>::result;
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_POLYMORPHIC_HXX
