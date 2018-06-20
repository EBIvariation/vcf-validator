// file      : odb/callback.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_CALLBACK_HXX
#define ODB_CALLBACK_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>        // odb::core
#include <odb/details/export.hxx>

namespace odb
{
  struct LIBODB_EXPORT callback_event
  {
    enum value
    {
      pre_persist,
      post_persist,
      pre_load,
      post_load,
      pre_update,
      post_update,
      pre_erase,
      post_erase
    };

    callback_event (value v): v_ (v) {}
    operator value () const {return v_;}

  private:
    value v_;
  };

  namespace common
  {
    using odb::callback_event;
  }
}

#include <odb/post.hxx>

#endif // ODB_CALLBACK_HXX
