// file      : odb/sqlite/polymorphic-object-statements.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::memset

#include <odb/callback.hxx>
#include <odb/exceptions.hxx>

#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/traits-calls.hxx>

namespace odb
{
  namespace sqlite
  {
    //
    // polymorphic_root_object_statements
    //

    template <typename T>
    polymorphic_root_object_statements<T>::
    ~polymorphic_root_object_statements ()
    {
    }

    template <typename T>
    polymorphic_root_object_statements<T>::
    polymorphic_root_object_statements (connection_type& conn)
        : object_statements<T> (conn),
          discriminator_image_binding_ (discriminator_image_bind_,
                                        discriminator_column_count +
                                        managed_optimistic_column_count),
          discriminator_id_image_binding_ (discriminator_id_image_bind_,
                                           id_column_count)
    {
      discriminator_image_.version = 0;
      discriminator_id_image_.version = 0;

      discriminator_image_version_ = 0;
      discriminator_id_image_version_ = 0;

      std::memset (discriminator_image_bind_,
                   0,
                   sizeof (discriminator_image_bind_));
      std::memset (discriminator_id_image_bind_,
                   0,
                   sizeof (discriminator_id_image_bind_));
      std::memset (discriminator_image_truncated_,
                   0,
                   sizeof (discriminator_image_truncated_));

      for (std::size_t i (0);
           i < discriminator_column_count + managed_optimistic_column_count;
           ++i)
      {
        discriminator_image_bind_[i].truncated =
          discriminator_image_truncated_ + i;
      }
    }

    //
    // polymorphic_derived_object_statements
    //

    template <typename T>
    polymorphic_derived_object_statements<T>::
    ~polymorphic_derived_object_statements ()
    {
    }

    template <typename T>
    polymorphic_derived_object_statements<T>::
    polymorphic_derived_object_statements (connection_type& conn)
        : statements_base (conn),
          root_statements_ (conn.statement_cache ().find_object<root_type> ()),
          base_statements_ (conn.statement_cache ().find_object<base_type> ()),
          insert_image_binding_ (insert_image_bind_, insert_column_count),
          update_image_binding_ (update_image_bind_,
                                 update_column_count + id_column_count)
    {
      image_.base = &base_statements_.image ();
      image_.version = 0;

      for (std::size_t i (0); i < object_traits::depth; ++i)
        select_image_versions_[i] = 0;

      for (std::size_t i (0);
           i < (object_traits::abstract ? 1 : object_traits::depth);
           ++i)
      {
        select_image_bindings_[i].bind = select_image_bind_;
        select_image_bindings_[i].count = object_traits::find_column_counts[i];
      }

      insert_image_version_ = 0;
      insert_id_binding_version_ = 0;
      update_image_version_ = 0;
      update_id_binding_version_ = 0;

      std::memset (insert_image_bind_, 0, sizeof (insert_image_bind_));
      std::memset (update_image_bind_, 0, sizeof (update_image_bind_));
      std::memset (select_image_bind_, 0, sizeof (select_image_bind_));
      std::memset (
        select_image_truncated_, 0, sizeof (select_image_truncated_));

      for (std::size_t i (0); i < select_column_count; ++i)
        select_image_bind_[i].truncated = select_image_truncated_ + i;
    }

    template <typename T>
    void polymorphic_derived_object_statements<T>::
    delayed_loader (odb::database& db,
                    const id_type& id,
                    root_type& robj,
                    const schema_version_migration* svm)
    {
      connection_type& conn (transaction::current ().connection ());
      polymorphic_derived_object_statements& sts (
        conn.statement_cache ().find_object<object_type> ());
      root_statements_type& rsts (sts.root_statements ());

      object_type& obj (static_cast<object_type&> (robj));

      // The same code as in object_statements::load_delayed_().
      //
      object_traits_calls<T> tc (svm);

      if (!tc.find_ (sts, &id))
        throw object_not_persistent ();

      object_traits::callback (db, obj, callback_event::pre_load);
      tc.init (obj, sts.image (), &db);
      tc.load_ (sts, obj, false); // Load containers, etc.

      rsts.load_delayed (svm);

      {
        typename root_statements_type::auto_unlock u (rsts);
        object_traits::callback (db, obj, callback_event::post_load);
      }
    }
  }
}
