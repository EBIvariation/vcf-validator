// file      : odb/sqlite/view-result.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_VIEW_RESULT_HXX
#define ODB_SQLITE_VIEW_RESULT_HXX

#include <odb/pre.hxx>

#include <cstddef> // std::size_t

#include <odb/schema-version.hxx>
#include <odb/view-result.hxx>

#include <odb/details/shared-ptr.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx> // query_base, query_params
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/traits-calls.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    class view_result_impl: public odb::view_result_impl<T>
    {
    public:
      typedef odb::view_result_impl<T> base_type;

      typedef typename base_type::view_type view_type;
      typedef typename base_type::pointer_type pointer_type;

      typedef view_traits_impl<view_type, id_sqlite> view_traits;
      typedef typename base_type::pointer_traits pointer_traits;

      typedef view_statements<view_type> statements_type;

      virtual
      ~view_result_impl ();

      view_result_impl (const query_base&,
                        const details::shared_ptr<select_statement>&,
                        statements_type&,
                        const schema_version_migration*);

      virtual void
      load (view_type&);

      virtual void
      next ();

      virtual void
      cache ();

      virtual std::size_t
      size ();

      virtual void
      invalidate ();

      using base_type::current;

    private:
      // We need to hold on to the query parameters because SQLite uses
      // the parameter buffers to find each next row.
      //
      details::shared_ptr<query_params> params_;
      details::shared_ptr<select_statement> statement_;
      statements_type& statements_;
      view_traits_calls<view_type> tc_;
    };
  }
}

#include <odb/sqlite/view-result.txx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_VIEW_RESULT_HXX
