// file      : odb/view-image.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VIEW_IMAGE_HXX
#define ODB_VIEW_IMAGE_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>
#include <odb/traits.hxx>

namespace odb
{
  // Helper to create a complete image chain for a polymorphic
  // object hierarchy.
  //
  template <typename D, typename R, database_id DB>
  struct view_object_image: object_traits_impl<D, DB>::image_type
  {
    view_object_image () {this->base = &base_;}

  private:
    // Data member names in the generated image_type never end with
    // an underscore, so this name shouldn't clash.
    //
    view_object_image<typename object_traits_impl<D, DB>::base_type, R, DB>
    base_;
  };

  template <typename R, database_id DB>
  struct view_object_image<R, R, DB>: object_traits_impl<R, DB>::image_type {};
}

#include <odb/post.hxx>

#endif // ODB_VIEW_IMAGE_HXX
