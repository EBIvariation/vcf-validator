// file      : odb/details/shared-ptr/counter-type.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX
#define ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX

#include <odb/pre.hxx>

namespace odb
{
  namespace details
  {
    template <typename X>
    struct counter_type
    {
      typedef X counter;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX
