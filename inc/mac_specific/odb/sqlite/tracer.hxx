// file      : odb/sqlite/tracer.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_TRACER_HXX
#define ODB_SQLITE_TRACER_HXX

#include <odb/pre.hxx>

#include <odb/tracer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class LIBODB_SQLITE_EXPORT tracer: private odb::tracer
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

    private:
      // Allow these classes to convert sqlite::tracer to odb::tracer.
      //
      friend class database;
      friend class connection;
      friend class transaction;

      virtual void
      prepare (odb::connection&, const odb::statement&);

      virtual void
      execute (odb::connection&, const odb::statement&);

      virtual void
      execute (odb::connection&, const char* statement);

      virtual void
      deallocate (odb::connection&, const odb::statement&);
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_TRACER_HXX
