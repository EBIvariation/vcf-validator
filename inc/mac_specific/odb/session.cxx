// file      : odb/session.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/exceptions.hxx>
#include <odb/session.hxx>

#include <odb/details/tls.hxx>

namespace odb
{
  using namespace details;

  static ODB_TLS_POINTER (session) current_session;

  session::
  session (bool make_current)
  {
    if (make_current)
    {
      if (has_current ())
        throw already_in_session ();

      current_pointer (this);
    }
  }

  session::
  ~session ()
  {
    // If we are the current thread's session, reset it.
    //
    if (current_pointer () == this)
      reset_current ();
  }

  session* session::
  current_pointer ()
  {
    return tls_get (current_session);
  }

  void session::
  current_pointer (session* s)
  {
    tls_set (current_session, s);
  }

  session& session::
  current ()
  {
    session* cur (tls_get (current_session));

    if (cur == 0)
      throw not_in_session ();

    return *cur;
  }

  //
  // object_map_base
  //
  session::object_map_base::
  ~object_map_base ()
  {
  }
}
