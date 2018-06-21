// file      : odb/details/shared-ptr-fwd.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_FWD_HXX
#define ODB_DETAILS_SHARED_PTR_FWD_HXX

#include <odb/pre.hxx>

#include <odb/details/shared-ptr/counter-type.hxx>

namespace odb
{
  namespace details
  {
    template <typename X>
    class shared_ptr;

    class shared_base;
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_SHARED_PTR_FWD_HXX
