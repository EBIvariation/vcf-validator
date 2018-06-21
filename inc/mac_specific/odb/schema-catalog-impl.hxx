// file      : odb/schema-catalog-impl.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SCHEMA_CATALOG_IMPL_HXX
#define ODB_SCHEMA_CATALOG_IMPL_HXX

#include <odb/pre.hxx>

#include <cstddef>

#include <odb/forward.hxx> // schema_version

#include <odb/details/export.hxx>

namespace odb
{
  struct schema_catalog_impl;

  // Translation unit initializer.
  //
  struct LIBODB_EXPORT schema_catalog_init
  {
    static schema_catalog_impl* catalog;
    static std::size_t count;

    schema_catalog_init ();
    ~schema_catalog_init ();
  };

  static const schema_catalog_init schema_catalog_init_;

  // Catalog entry registration.
  //
  struct LIBODB_EXPORT schema_catalog_create_entry
  {
    schema_catalog_create_entry (
      database_id,
      const char* name,
      bool (*create_function) (database&, unsigned short pass, bool drop));
  };

  struct LIBODB_EXPORT schema_catalog_migrate_entry
  {
    schema_catalog_migrate_entry (
      database_id,
      const char* name,
      schema_version,
      bool (*migrate_function) (database&, unsigned short pass, bool pre));
  };
}

#include <odb/post.hxx>

#endif // ODB_SCHEMA_CATALOG_IMPL_HXX
