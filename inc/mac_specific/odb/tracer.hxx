// file      : odb/tracer.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_HXX
#define ODB_TRACER_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>
#include <odb/details/export.hxx>

namespace odb
{
  class LIBODB_EXPORT tracer
  {
  public:
    virtual
    ~tracer ();

    virtual void
    prepare (connection&, const statement&);

    virtual void
    execute (connection&, const statement&);

    virtual void
    execute (connection&, const char* statement) = 0;

    virtual void
    deallocate (connection&, const statement&);
  };
}

#include <odb/post.hxx>

#endif // ODB_TRACER_HXX
