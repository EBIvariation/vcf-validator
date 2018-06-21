// file      : odb/schema-catalog.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SCHEMA_CATALOG_HXX
#define ODB_SCHEMA_CATALOG_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11

#include <string>
#include <cstddef> // std::size_t

#ifdef ODB_CXX11
#  include <utility>     // std::move
#  include <functional>  // std::function
#  include <type_traits> // std::enable_if, std::is_convertible
#endif

#include <odb/forward.hxx> // schema_version, odb::core
#include <odb/database.hxx>

#include <odb/details/export.hxx>
#include <odb/details/unused.hxx>
#include <odb/details/meta/static-assert.hxx>

namespace odb
{
  class LIBODB_EXPORT schema_catalog
  {
  public:
    // Schema creation.
    //
    static void
    create_schema (database&, const std::string& name = "", bool drop = true);

    static void
    drop_schema (database&, const std::string& name = "");

    // Schema migration.
    //
  public:
    static void
    migrate_schema_pre (database& db,
                        schema_version v,
                        const std::string& name = "")
    {
      migrate_schema_impl (db, v, name, migrate_pre);
    }

    static void
    migrate_schema_post (database& db,
                         schema_version v,
                         const std::string& name = "")
    {
      migrate_schema_impl (db, v, name, migrate_post);
    }

    static void
    migrate_schema (database& db,
                    schema_version v,
                    const std::string& name = "")
    {
      migrate_schema_impl (db, v, name, migrate_both);
    }

    // Data migration.
    //
  public:
    // If version is 0, then use the current database version and also
    // check whether we are in migration. Returns the number of calls made.
    //
    static std::size_t
    migrate_data (database&,
                  schema_version = 0,
                  const std::string& name = "");

    typedef void data_migration_function_type (database&);
    typedef data_migration_function_type* data_migration_function_ptr;

    typedef details::function_wrapper<data_migration_function_type>
    data_migration_function_wrapper;

    // The following three variants of the registration functions make
    // sure that the version is greater that the base model version.
    // This helps with identifying and removing data migration function
    // that are no longer required.
    //
    // Data migration functions are called in the order of registration.
    //
#ifndef ODB_CXX11
    template <schema_version v, schema_version base>
    static void
    data_migration_function (data_migration_function_ptr f,
                             const std::string& name = "")
    {
      data_migration_function<v, base> (id_common, f, name);
    }

#else
    template <schema_version v, schema_version base, typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (F f, const std::string& name = "")
    {
      data_migration_function<v, base> (id_common, std::move (f), name);
    }
#endif

    // Database-specific data migration.
    //
#ifndef ODB_CXX11
    template <schema_version v, schema_version base>
    static void
    data_migration_function (database& db,
                             data_migration_function_ptr f,
                             const std::string& name = "")
    {
      data_migration_function<v, base> (db.id (), f, name);
    }
#else
    template <schema_version v, schema_version base, typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (database& db, F f, const std::string& name = "")
    {
      data_migration_function<v, base> (db.id (), std::move (f), name);
    }
#endif

#ifndef ODB_CXX11
    template <schema_version v, schema_version base>
    static void
    data_migration_function (database_id id,
                             data_migration_function_ptr f,
                             const std::string& name = "")
    {
      // If the data migration version is below the base model version
      // then it will never be called.
      //

      // Poor man's static_assert.
      //
      typedef details::meta::static_assert_test<(v > base || base == 0)>
      data_migration_function_is_no_longer_necessary;

      char sa [sizeof (data_migration_function_is_no_longer_necessary)];
      ODB_POTENTIALLY_UNUSED (sa);

      data_migration_function (id, v, f, name);
    }
#else
    template <schema_version v, schema_version base, typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (database_id id, F f, const std::string& name = "")
    {
      // If the data migration version is below the base model version
      // then it will never be called.
      //
      static_assert (v > base || base == 0,
                     "data migration function is no longer necessary");

      data_migration_function (id, v, std::move (f), name);
    }
#endif

    // The same as above but take the version as an argument and do
    // not check whether it is greater than the base model version.
    //
#ifndef ODB_CXX11
    static void
    data_migration_function (schema_version v,
                             data_migration_function_ptr f,
                             const std::string& name = "")
    {
      data_migration_function (id_common, v, f, name);
    }
#else
    template <typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (schema_version v,
                             F f,
                             const std::string& name = "")
    {
      data_migration_function (id_common, v, std::move (f), name);
    }
#endif

#ifndef ODB_CXX11
    static void
    data_migration_function (database& db,
                             schema_version v,
                             data_migration_function_ptr f,
                             const std::string& name = "")
    {
      data_migration_function (db.id (), v, f, name);
    }
#else
    template <typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (database& db,
                             schema_version v,
                             F f,
                             const std::string& name = "")
    {
      data_migration_function (db.id (), v, std::move (f), name);
    }
#endif

#ifndef ODB_CXX11
    static void
    data_migration_function (database_id i,
                             schema_version v,
                             data_migration_function_ptr f,
                             const std::string& name = "")
    {
      data_migration_function (i,
                               v,
                               data_migration_function_wrapper (f),
                               name);
    }
#else
    template <typename F>
    static typename std::enable_if<
      std::is_convertible<
        F, std::function<data_migration_function_type>>::value, void>::type
    data_migration_function (database_id i,
                             schema_version v,
                             F f,
                             const std::string& name = "")
    {
      data_migration_function (
        i,
        v,
        data_migration_function_wrapper (std::move (f)),
        name);
    }
#endif

  private:
    static void
    data_migration_function (database_id,
                             schema_version,
                             data_migration_function_wrapper,
                             const std::string& name);

    // Combined schema and data migration.
    //
  public:
    // Migrate both schema and data to the specified version. If version
    // is not specified, then migrate to the current model version.
    //
    static void
    migrate (database&, schema_version = 0, const std::string& name = "");

    // Schema version information.
    //
  public:
    // Return the base model version.
    //
    static schema_version
    base_version (const database& db, const std::string& name = "")
    {
      return base_version (db.id (), name);
    }

    static schema_version
    base_version (database_id, const std::string& name = "");

    // Return the current model version.
    //
    static schema_version
    current_version (const database& db, const std::string& name = "")
    {
      return current_version (db.id (), name);
    }

    static schema_version
    current_version (database_id, const std::string& name = "");

    // Return current model version + 1 (that is, one past current) if
    // the passed version is equal to or greater than current. If the
    // version is not specified, then use the current database version.
    //
    static schema_version
    next_version (const database& db,
                  schema_version v = 0,
                  const std::string& name = "")
    {
      return next_version (db.id (), v == 0 ? db.schema_version () : v, name);
    }

    static schema_version
    next_version (database_id,
                  schema_version,
                  const std::string& name = "");

    // Schema existence.
    //
  public:
    // Test for presence of a schema with a specific name.
    //
    static bool
    exists (const database& db, const std::string& name = "")
    {
      return exists (db.id (), name);
    }

    static bool
    exists (database_id, const std::string& name = "");

  private:
    enum migrate_mode
    {
      migrate_pre,
      migrate_post,
      migrate_both
    };

    static void
    migrate_schema_impl (database&,
                         schema_version,
                         const std::string& name,
                         migrate_mode);
  };

  // Static data migration function registration.
  //
  template <schema_version v, schema_version base>
  struct data_migration_entry
  {
    typedef schema_catalog::data_migration_function_type function_type;

#ifndef ODB_CXX11
    data_migration_entry (function_type* f, const std::string& name = "")
    {
      schema_catalog::data_migration_function<v, base> (f, name);
    }
#else
    template <typename F>
    data_migration_entry (F f,
                          const std::string& name = "",
                          typename std::enable_if<std::is_convertible<
                            F, std::function<function_type>>::value>
                          ::type* = 0)
    {
      schema_catalog::data_migration_function<v, base> (std::move (f), name);
    }
#endif

#ifndef ODB_CXX11
    data_migration_entry (database_id id,
                          function_type *f,
                          const std::string& name = "")
    {
      schema_catalog::data_migration_function<v, base> (id, v, f, name);
    }
#else
    template <typename F>
    data_migration_entry (database_id id,
                          F f,
                          const std::string& name = "",
                          typename std::enable_if<std::is_convertible<
                            F, std::function<function_type>>::value>
                          ::type* = 0)
    {
      schema_catalog::data_migration_function<v, base> (id,
                                                        v,
                                                        std::move (f),
                                                        name);
    }
#endif
  };

  namespace common
  {
    using odb::schema_catalog;
    using odb::data_migration_entry;
  }
}

#include <odb/post.hxx>

#endif // ODB_SCHEMA_CATALOG_HXX
