// file      : odb/section.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/section.hxx>

namespace odb
{
  void section::
  disarm ()
  {
    transaction& t (transaction::current ());
    t.callback_unregister (this);
    state_.armed = 0;
  }

  void section::
  transacion_callback (unsigned short event, void* key, unsigned long long)
  {
    section& s (*static_cast<section*> (key));

    if (event == transaction::event_rollback && s.state_.restore)
      s.state_.changed = 1;

    s.state_.armed = 0;
    s.state_.restore = 0;
  }
}
