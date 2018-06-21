// file      : odb/sqlite/query-dynamic.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_QUERY_DYNAMIC_HXX
#define ODB_SQLITE_QUERY_DYNAMIC_HXX

#include <odb/pre.hxx>

#include <odb/query.hxx>
#include <odb/query-dynamic.hxx>

#include <odb/sqlite/query.hxx>

namespace odb
{
  namespace sqlite
  {
    typedef details::shared_ptr<query_param> (*query_param_factory) (
      const void* val, bool by_ref);

    template <typename T, database_type_id ID>
    details::shared_ptr<query_param>
    query_param_factory_impl (const void*, bool);
  }
}

#include <odb/sqlite/query-dynamic.ixx>
#include <odb/sqlite/query-dynamic.txx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_QUERY_DYNAMIC_HXX
