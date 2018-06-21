// file      : odb/forward.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_FORWARD_HXX
#define ODB_FORWARD_HXX

#include <odb/pre.hxx>

#include <cstddef> // std::size_t

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr-fwd.hxx>

namespace odb
{
  // Common and core namespaces. The idea is that you can use the
  // using directive to get database-independent (common) names or
  // all core names (core).
  //
  namespace common {}

  namespace core
  {
    using namespace common;
  }

  //
  //
  typedef unsigned long long schema_version;
  struct schema_version_migration;

  class database;
  class connection;
  typedef details::shared_ptr<connection> connection_ptr;
  class transaction;
  class statement;
  class session;
  class section;

  namespace common
  {
    using odb::schema_version;
    using odb::schema_version_migration;
    using odb::session;
    using odb::section;
  }

  namespace core
  {
    using odb::database;
    using odb::connection;
    using odb::connection_ptr;
    using odb::transaction;
    using odb::statement;
  }

  // Tracing.
  //
  class tracer; // Not in core.
  extern LIBODB_EXPORT tracer& stderr_tracer;
  extern LIBODB_EXPORT tracer& stderr_full_tracer;

  namespace common
  {
    using odb::stderr_tracer;
  }

  // Implementation details.
  //

  // Keep real databases first since their enumerators are used as array
  // indexes.
  //
  enum database_id
  {
    id_mysql,
    id_sqlite,
    id_pgsql,
    id_oracle,
    id_mssql,
    id_common
  };

  // Number of real databases (i.e., excluding default) in the database_id
  // enum.
  //
  const std::size_t database_count = id_common;

  // Traits.
  //
  class access
  {
  public:
    template <typename T>
    class object_traits;

    template <typename T, database_id DB>
    class object_traits_impl;

    template <typename T, typename P>
    class object_factory;

    template <typename T>
    class view_traits;

    template <typename T, database_id DB>
    class view_traits_impl;

    template <typename T, typename P>
    class view_factory;

    template <typename T, typename P>
    class pointer_factory;

    template <typename T, database_id DB>
    class composite_value_traits;

    template <typename C>
    class container_traits;
  };

  template <typename T>
  struct object_traits;

  template <typename T, database_id DB>
  struct object_traits_impl;

  template <typename T>
  struct view_traits;

  template <typename T, database_id DB>
  struct view_traits_impl;

  // Cache traits.
  //
  template <typename T> struct no_id_pointer_cache_traits;
  template <typename T> struct no_op_pointer_cache_traits;
  template <typename T, typename S> struct pointer_cache_traits;
  template <typename T> struct no_id_reference_cache_traits;
  template <typename T> struct no_op_reference_cache_traits;
  template <typename T, typename S> struct reference_cache_traits;

  //
  //
  class query_base;

  template <typename T>
  struct query_column;

  //
  //
  class result_impl;
  class prepared_query_impl;

  //
  //
  struct multiple_exceptions;

  // Polymorphism support.
  //
  template <typename R>
  struct polymorphic_map;

  namespace details
  {
    template <>
    struct counter_type<connection>
    {
      typedef shared_base counter;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_FORWARD_HXX
