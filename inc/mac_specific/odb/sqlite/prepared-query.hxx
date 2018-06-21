// file      : odb/sqlite/prepared-query.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_PREPARED_QUERY_HXX
#define ODB_SQLITE_PREPARED_QUERY_HXX

#include <odb/pre.hxx>

#include <odb/prepared-query.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/query.hxx>

#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    struct LIBODB_SQLITE_EXPORT prepared_query_impl: odb::prepared_query_impl
    {
      virtual
      ~prepared_query_impl ();

      prepared_query_impl (odb::connection& c): odb::prepared_query_impl (c) {}

      sqlite::query_base query;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_PREPARED_QUERY_HXX
