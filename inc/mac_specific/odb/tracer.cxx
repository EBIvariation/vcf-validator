// file      : odb/tracer.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <iostream>

#include <odb/tracer.hxx>
#include <odb/statement.hxx>

using namespace std;

namespace odb
{
  //
  // tracer
  //

  tracer::
  ~tracer ()
  {
  }

  void tracer::
  prepare (connection&, const statement&)
  {
  }

  void tracer::
  execute (connection& c, const statement& s)
  {
    execute (c, s.text ());
  }

  void tracer::
  deallocate (connection&, const statement&)
  {
  }

  //
  // stderr_tracer
  //

  class stderr_tracer_type: public tracer
  {
  public:
    stderr_tracer_type (bool full): full_ (full) {}

    virtual void
    prepare (connection&, const statement&);

    virtual void
    execute (connection&, const char* statement);

    virtual void
    deallocate (connection&, const statement&);

    // Override the other version to get rid of a Sun CC warning.
    //
    virtual void
    execute (connection&, const statement&);

  private:
    bool full_;
  };

  void stderr_tracer_type::
  prepare (connection&, const statement& s)
  {
    if (full_)
      cerr << "PREPARE " << s.text () << endl;
  }

  void stderr_tracer_type::
  execute (connection&, const char* s)
  {
    cerr << s << endl;
  }

  void stderr_tracer_type::
  deallocate (connection&, const statement& s)
  {
    if (full_)
      cerr << "DEALLOCATE " << s.text () << endl;
  }

  void stderr_tracer_type::
  execute (connection& c, const statement& s)
  {
    execute (c, s.text ());
  }

  static stderr_tracer_type stderr_tracer_ (false);
  static stderr_tracer_type stderr_full_tracer_ (true);
  tracer& stderr_tracer = stderr_tracer_;
  tracer& stderr_full_tracer = stderr_full_tracer_;
}
