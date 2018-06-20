// file      : odb/sqlite/polymorphic-object-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cassert>

#include <odb/callback.hxx>
#include <odb/exceptions.hxx> // result_not_cached

#include <odb/sqlite/polymorphic-object-statements.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    polymorphic_object_result_impl<T>::
    ~polymorphic_object_result_impl ()
    {
      if (!this->end_)
        statement_->free_result ();
    }

    template <typename T>
    void polymorphic_object_result_impl<T>::
    invalidate ()
    {
      if (!this->end_)
      {
        statement_->free_result ();
        this->end_ = true;
      }

      params_.reset ();
      statement_.reset ();
    }

    template <typename T>
    polymorphic_object_result_impl<T>::
    polymorphic_object_result_impl (
      const query_base& q,
      const details::shared_ptr<select_statement>& s,
      statements_type& sts,
      const schema_version_migration* svm)
        : base_type (sts.connection ()),
          params_ (q.parameters ()),
          statement_ (s),
          statements_ (sts),
          tc_ (svm)
    {
    }

    template <typename T>
    void polymorphic_object_result_impl<T>::
    load (object_type* pobj, bool fetch)
    {
      if (fetch)
        load_image ();

      typename statements_type::root_statements_type& rsts (
        statements_.root_statements ());

      // This is a top-level call so the statements cannot be locked.
      //
      assert (!rsts.locked ());
      typename statements_type::auto_lock l (rsts);

      typename object_traits::image_type& i (statements_.image ());
      typename root_traits::image_type& ri (rsts.image ());

      id_type id (root_traits::id (ri));

      // Determine this object's dynamic type.
      //
      typedef typename root_traits::info_type info_type;
      discriminator_type d (root_traits::discriminator (ri));
      discriminator_type disc (d);

      // Use the polymorphic_info() helper to get concrete_info if
      // object_type is concrete and NULL if it is abstract.
      //
      const info_type* spi (polymorphic_info (object_traits::info));
      const info_type& pi (
        spi != 0 && spi->discriminator == d
        ? *spi
        : root_traits::map->find (d));

      typedef typename root_traits::pointer_type root_pointer_type;
      typedef typename root_traits::pointer_traits root_pointer_traits;

      typename object_traits::pointer_cache_traits::insert_guard ig;

      if (pobj == 0)
      {
        // Need to create a new instance of the dynamic type.
        //
        root_pointer_type rp (pi.create ());
        pointer_type p (
          root_pointer_traits::template static_pointer_cast<object_type> (rp));

        // Insert it as a root pointer (for non-unique pointers, rp should
        // still be valid and for unique pointers this is a no-op).
        //
        ig.reset (
          object_traits::pointer_cache_traits::insert (this->db_, id, rp));

        pobj = &pointer_traits::get_ref (p);
        current (p);
      }
      else
      {
        // We are loading into an existing instance. If the static and
        // dynamic types differ, then make sure the instance is at least
        // of the dynamic type.
        //
        if (&pi != &object_traits::info)
        {
          const info_type& dpi (root_traits::map->find (typeid (*pobj)));

          if (&dpi != &pi && dpi.derived (pi))
            throw object_not_persistent (); // @@ type_mismatch ?
        }
      }

      callback_event ce (callback_event::pre_load);
      pi.dispatch (info_type::call_callback, this->db_, pobj, &ce);

      tc_.init (*pobj, i, &this->db_);

      // Initialize the id image and binding and load the rest of the object
      // (containers, dynamic part, etc).
      //
      typename object_traits::id_image_type& idi (statements_.id_image ());
      root_traits::init (idi, id);

      binding& idb (statements_.id_image_binding ());
      if (idi.version != statements_.id_image_version () || idb.version == 0)
      {
        object_traits::bind (idb.bind, idi);
        statements_.id_image_version (idi.version);
        idb.version++;
      }

      tc_.load_ (statements_, *pobj, false);

      // Load the dynamic part of the object unless static and dynamic
      // types are the same.
      //
      if (&pi != &object_traits::info)
      {
        std::size_t d (object_traits::depth);
        pi.dispatch (info_type::call_load, this->db_, pobj, &d);
      };

      rsts.load_delayed (tc_.version ());
      l.unlock ();

      ce = callback_event::post_load;
      pi.dispatch (info_type::call_callback, this->db_, pobj, &ce);
      object_traits::pointer_cache_traits::load (ig.position ());
      ig.release ();
    }

    template <typename T>
    typename polymorphic_object_result_impl<T>::id_type
    polymorphic_object_result_impl<T>::
    load_id ()
    {
      load_image ();
      return root_traits::id (statements_.root_statements ().image ());
    }

    template <typename T>
    typename polymorphic_object_result_impl<T>::discriminator_type
    polymorphic_object_result_impl<T>::
    load_discriminator ()
    {
      load_image ();
      return root_traits::discriminator (
        statements_.root_statements ().image ());
    }

    template <typename T>
    void polymorphic_object_result_impl<T>::
    next ()
    {
      this->current (pointer_type ());

      if (!statement_->next ())
      {
        statement_->free_result ();
        this->end_ = true;
      }
    }

    template <typename T, typename R>
    struct polymorphic_image_rebind
    {
      // Derived type version.
      //
      typedef object_traits_impl<T, id_sqlite> traits;

      static bool
      rebind (typename traits::statements_type& sts,
              const schema_version_migration* svm)
      {
        typename traits::image_type& im (sts.image ());

        if (traits::check_version (sts.select_image_versions (), im))
        {
          binding& b (sts.select_image_binding (traits::depth));
          object_traits_calls<T> tc (svm);
          tc.bind (b.bind, 0, 0, im, statement_select);
          traits::update_version (
            sts.select_image_versions (), im, sts.select_image_bindings ());
          return true;
        }

        return false;
      }
    };

    template <typename R>
    struct polymorphic_image_rebind<R, R>
    {
      // Root type version.
      //
      typedef object_traits_impl<R, id_sqlite> traits;

      static bool
      rebind (typename traits::statements_type& sts,
              const schema_version_migration* svm)
      {
        typename traits::image_type& im (sts.image ());

        if (im.version != sts.select_image_version ())
        {
          binding& b (sts.select_image_binding ());
          object_traits_calls<R> tc (svm);
          tc.bind (b.bind, im, statement_select);
          sts.select_image_version (im.version);
          b.version++;
          return true;
        }

        return false;
      }
    };

    template <typename T>
    void polymorphic_object_result_impl<T>::
    load_image ()
    {
      typedef polymorphic_image_rebind<object_type, root_type> image_rebind;

      // The image can grow between calls to load() as a result of other
      // statements execution.
      //
      image_rebind::rebind (statements_, tc_.version ());

      select_statement::result r (statement_->load ());

      if (r == select_statement::truncated)
      {
        typename object_traits::image_type& im (statements_.image ());

        if (tc_.grow (im, statements_.select_image_truncated ()))
          im.version++;

        if (image_rebind::rebind (statements_, tc_.version ()))
          statement_->reload ();
      }
    }

    template <typename T>
    void polymorphic_object_result_impl<T>::
    cache ()
    {
    }

    template <typename T>
    std::size_t polymorphic_object_result_impl<T>::
    size ()
    {
      throw result_not_cached ();
    }
  }
}
