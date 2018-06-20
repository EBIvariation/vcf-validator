// file      : odb/schema-version.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SCHEMA_VERSION_HXX
#define ODB_SCHEMA_VERSION_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx> // schema_version
#include <odb/details/export.hxx>

namespace odb
{
  struct LIBODB_EXPORT schema_version_migration
  {
    schema_version_migration (schema_version v = 0, bool m = false)
      : version (v), migration (m) {}

    schema_version version;
    bool migration;
  };

  // Version ordering is as follows: {1,f} < {2,t} < {2,f} < {3,t}
  //
  inline bool
  operator== (const schema_version_migration& x,
              const schema_version_migration& y)
  {
    return x.version == y.version && x.migration == y.migration;
  }

  inline bool
  operator!= (const schema_version_migration& x,
              const schema_version_migration& y)
  {
    return !(x == y);
  }

  inline bool
  operator< (const schema_version_migration& x,
             const schema_version_migration& y)
  {
    return x.version < y.version ||
      (x.version == y.version && x.migration && !y.migration);
  }

  inline bool
  operator> (const schema_version_migration& x,
             const schema_version_migration& y)
  {
    return x.version > y.version ||
      (x.version == y.version && !x.migration && y.migration);
  }

  inline bool
  operator<= (const schema_version_migration& x,
              const schema_version_migration& y)
  {
    return !(x > y);
  }

  inline bool
  operator>= (const schema_version_migration& x,
              const schema_version_migration& y)
  {
    return !(x < y);
  }
}

#include <odb/post.hxx>

#endif // ODB_SCHEMA_VERSION_HXX
