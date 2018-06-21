// file      : odb/sqlite/statement-cache.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_STATEMENT_CACHE_HXX
#define ODB_SQLITE_STATEMENT_CACHE_HXX

#include <odb/pre.hxx>

#include <map>
#include <typeinfo>

#include <odb/forward.hxx>
#include <odb/traits.hxx>

#include <odb/details/shared-ptr.hxx>
#include <odb/details/type-info.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statements-base.hxx>

#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class LIBODB_SQLITE_EXPORT statement_cache
    {
    public:
      statement_cache (connection&);

      generic_statement&
      begin_statement () const
      {
        return *begin_;
      }

      generic_statement&
      begin_immediate_statement () const
      {
        if (!begin_immediate_)
          begin_immediate_statement_ ();

        return *begin_immediate_;
      }

      generic_statement&
      begin_exclusive_statement () const
      {
        if (!begin_exclusive_)
          begin_exclusive_statement_ ();

        return *begin_exclusive_;
      }

      generic_statement&
      commit_statement () const
      {
        return *commit_;
      }

      generic_statement&
      rollback_statement () const
      {
        return *rollback_;
      }

      template <typename T>
      typename object_traits_impl<T, id_sqlite>::statements_type&
      find_object ();

      template <typename T>
      view_statements<T>&
      find_view ();

    private:
      void
      begin_immediate_statement_ () const;

      void
      begin_exclusive_statement_ () const;

    private:
      typedef std::map<const std::type_info*,
                       details::shared_ptr<statements_base>,
                       details::type_info_comparator> map;

      connection& conn_;
      unsigned int version_seq_;

      details::shared_ptr<generic_statement> begin_;
      mutable details::shared_ptr<generic_statement> begin_immediate_;
      mutable details::shared_ptr<generic_statement> begin_exclusive_;
      details::shared_ptr<generic_statement> commit_;
      details::shared_ptr<generic_statement> rollback_;

      map map_;
    };
  }
}

#include <odb/sqlite/statement-cache.txx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_STATEMENT_CACHE_HXX
