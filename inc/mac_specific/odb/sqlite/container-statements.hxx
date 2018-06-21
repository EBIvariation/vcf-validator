// file      : odb/sqlite/container-statements.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_CONTAINER_STATEMENTS_HXX
#define ODB_SQLITE_CONTAINER_STATEMENTS_HXX

#include <odb/pre.hxx>

#include <cstddef> // std::size_t

#include <odb/forward.hxx>
#include <odb/schema-version.hxx>
#include <odb/traits.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class connection;

    // Template argument is the generated abstract container traits type.
    // That is, it doesn't need to provide column counts and statements.
    //
    template <typename T>
    class container_statements
    {
    public:
      typedef T traits;

      typedef typename traits::data_image_type data_image_type;
      typedef typename traits::functions_type functions_type;

      typedef sqlite::insert_statement insert_statement_type;
      typedef sqlite::select_statement select_statement_type;
      typedef sqlite::delete_statement delete_statement_type;

      typedef sqlite::connection connection_type;

      container_statements (connection_type&, binding& id_binding);

      connection_type&
      connection ()
      {
        return conn_;
      }

      // Functions.
      //
      functions_type&
      functions ()
      {
        return functions_;
      }

      // Schema version.
      //
      const schema_version_migration&
      version_migration () const {return *svm_;}

      void
      version_migration (const schema_version_migration& svm) {svm_ = &svm;}

      // Id image binding (external).
      //
      const binding&
      id_binding ()
      {
        return id_binding_;
      }

      // Data image. The image is split into the id (that comes as a
      // binding) and index/key plus value which are in data_image_type.
      // The select binding is a subset of the full binding (no id).
      //
      data_image_type&
      data_image ()
      {
        return data_image_;
      }

      bind*
      data_bind ()
      {
        return insert_image_binding_.bind;
      }

      bool
      data_binding_test_version () const
      {
        return data_id_binding_version_ != id_binding_.version ||
          data_image_version_ != data_image_.version ||
          insert_image_binding_.version == 0;
      }

      void
      data_binding_update_version ()
      {
        data_id_binding_version_ = id_binding_.version;
        data_image_version_ = data_image_.version;
        insert_image_binding_.version++;
        select_image_binding_.version++;
      }

      bool*
      select_image_truncated ()
      {
        return select_image_truncated_;
      }

      //
      // Statements.
      //

      insert_statement_type&
      insert_statement ()
      {
        if (insert_ == 0)
          insert_.reset (
            new (details::shared) insert_statement_type (
              conn_,
              insert_text_,
              versioned_, // Process if versioned.
              insert_image_binding_,
              0));

        return *insert_;
      }

      select_statement_type&
      select_statement ()
      {
        if (select_ == 0)
          select_.reset (
            new (details::shared) select_statement_type (
              conn_,
              select_text_,
              versioned_,   // Process if versioned.
              false,        // Don't optimize.
              id_binding_,
              select_image_binding_));

        return *select_;
      }

      delete_statement_type&
      delete_statement ()
      {
        if (delete_ == 0)
          delete_.reset (
            new (details::shared) delete_statement_type (
              conn_, delete_text_, id_binding_));

        return *delete_;
      }

    private:
      container_statements (const container_statements&);
      container_statements& operator= (const container_statements&);

    protected:
      connection_type& conn_;
      binding& id_binding_;

      functions_type functions_;

      data_image_type data_image_;
      std::size_t data_image_version_;
      std::size_t data_id_binding_version_;

      binding insert_image_binding_;

      binding select_image_binding_;
      bool* select_image_truncated_;

      const char* insert_text_;
      const char* select_text_;
      const char* delete_text_;

      bool versioned_;
      const schema_version_migration* svm_;

      details::shared_ptr<insert_statement_type> insert_;
      details::shared_ptr<select_statement_type> select_;
      details::shared_ptr<delete_statement_type> delete_;
    };

    template <typename T>
    class smart_container_statements: public container_statements<T>
    {
    public:
      typedef T traits;
      typedef typename traits::cond_image_type cond_image_type;

      typedef sqlite::update_statement update_statement_type;
      typedef sqlite::delete_statement delete_statement_type;

      typedef sqlite::connection connection_type;

      smart_container_statements (connection_type&, binding& id_binding);

      // Condition image. The image is split into the id (that comes as
      // a binding) and index/key/value which is in cond_image_type.
      //
      cond_image_type&
      cond_image ()
      {
        return cond_image_;
      }

      bind*
      cond_bind ()
      {
        return cond_image_binding_.bind;
      }

      bool
      cond_binding_test_version () const
      {
        return cond_id_binding_version_ != this->id_binding_.version ||
          cond_image_version_ != cond_image_.version ||
          cond_image_binding_.version == 0;
      }

      void
      cond_binding_update_version ()
      {
        cond_id_binding_version_ = this->id_binding_.version;
        cond_image_version_ = cond_image_.version;
        cond_image_binding_.version++;
      }

      // Update image. The image is split as follows: value comes
      // from the data image, id comes as binding, and index/key
      // comes from the condition image.
      //
      bind*
      update_bind ()
      {
        return update_image_binding_.bind;
      }

      bool
      update_binding_test_version () const
      {
        return update_id_binding_version_ != this->id_binding_.version ||
          update_cond_image_version_ != cond_image_.version ||
          update_data_image_version_ != this->data_image_.version ||
          update_image_binding_.version == 0;
      }

      void
      update_binding_update_version ()
      {
        update_id_binding_version_ = this->id_binding_.version;
        update_cond_image_version_ = cond_image_.version;
        update_data_image_version_ = this->data_image_.version;
        update_image_binding_.version++;
      }

      //
      // Statements.
      //

      delete_statement_type&
      delete_statement ()
      {
        if (this->delete_ == 0)
          this->delete_.reset (
            new (details::shared) delete_statement_type (
              this->conn_,
              this->delete_text_,
              this->cond_image_binding_));

        return *this->delete_;
      }

      update_statement_type&
      update_statement ()
      {
        if (update_ == 0)
          update_.reset (
            new (details::shared) update_statement_type (
              this->conn_,
              update_text_,
              this->versioned_, // Process if versioned.
              update_image_binding_));

        return *update_;
      }

    protected:
      cond_image_type cond_image_;
      std::size_t cond_image_version_;
      std::size_t cond_id_binding_version_;
      binding cond_image_binding_;

      std::size_t update_id_binding_version_;
      std::size_t update_cond_image_version_;
      std::size_t update_data_image_version_;
      binding update_image_binding_;

      const char* update_text_;

      details::shared_ptr<update_statement_type> update_;
    };

    // Template argument is the generated concrete container traits type.
    //
    template <typename T>
    class container_statements_impl: public T::statements_type
    {
    public:
      typedef T traits;
      typedef typename T::statements_type base;
      typedef sqlite::connection connection_type;

      container_statements_impl (connection_type&, binding&);

    private:
      container_statements_impl (const container_statements_impl&);
      container_statements_impl& operator= (const container_statements_impl&);

    private:
      bind data_image_bind_[traits::data_column_count];
      bool select_image_truncated_array_[traits::data_column_count -
                                         traits::id_column_count];
    };

    template <typename T>
    class smart_container_statements_impl: public container_statements_impl<T>
    {
    public:
      typedef T traits;
      typedef sqlite::connection connection_type;

      smart_container_statements_impl (connection_type&, binding&);

    private:
      bind cond_image_bind_[traits::cond_column_count];
      bind update_image_bind_[traits::value_column_count +
                              traits::cond_column_count];
    };
  }
}

#include <odb/sqlite/container-statements.txx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_CONTAINER_STATEMENTS_HXX
