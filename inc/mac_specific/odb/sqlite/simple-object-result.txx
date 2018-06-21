// file      : odb/sqlite/simple-object-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cassert>

#include <odb/callback.hxx>
#include <odb/exceptions.hxx> // result_not_cached

#include <odb/sqlite/simple-object-statements.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    object_result_impl<T>::
    ~object_result_impl ()
    {
      if (!this->end_)
        statement_->free_result ();
    }

    template <typename T>
    void object_result_impl<T>::
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
    object_result_impl<T>::
    object_result_impl (const query_base& q,
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
    void object_result_impl<T>::
    load (object_type& obj, bool fetch)
    {
      if (fetch)
        load_image ();

      // This is a top-level call so the statements cannot be locked.
      //
      assert (!statements_.locked ());
      typename statements_type::auto_lock l (statements_);

      object_traits::callback (this->db_, obj, callback_event::pre_load);

      typename object_traits::image_type& i (statements_.image ());
      tc_.init (obj, i, &this->db_);

      // Initialize the id image and binding and load the rest of the object
      // (containers, etc).
      //
      typename object_traits::id_image_type& idi (statements_.id_image ());
      object_traits::init (idi, object_traits::id (i));

      binding& idb (statements_.id_image_binding ());
      if (idi.version != statements_.id_image_version () || idb.version == 0)
      {
        object_traits::bind (idb.bind, idi);
        statements_.id_image_version (idi.version);
        idb.version++;
      }

      tc_.load_ (statements_, obj, false);
      statements_.load_delayed (tc_.version ());
      l.unlock ();
      object_traits::callback (this->db_, obj, callback_event::post_load);
    }

    template <typename T>
    typename object_result_impl<T>::id_type
    object_result_impl<T>::
    load_id ()
    {
      load_image ();
      return object_traits::id (statements_.image ());
    }

    template <typename T>
    void object_result_impl<T>::
    next ()
    {
      this->current (pointer_type ());

      if (!statement_->next ())
      {
        statement_->free_result ();
        this->end_ = true;
      }
    }

    template <typename T>
    void object_result_impl<T>::
    load_image ()
    {
      // The image can grow between calls to load() as a result of other
      // statements execution.
      //
      typename object_traits::image_type& im (statements_.image ());

      if (im.version != statements_.select_image_version ())
      {
        binding& b (statements_.select_image_binding ());
        tc_.bind (b.bind, im, statement_select);
        statements_.select_image_version (im.version);
        b.version++;
      }

      select_statement::result r (statement_->load ());

      if (r == select_statement::truncated)
      {
        if (tc_.grow (im, statements_.select_image_truncated ()))
          im.version++;

        if (im.version != statements_.select_image_version ())
        {
          binding& b (statements_.select_image_binding ());
          tc_.bind (b.bind, im, statement_select);
          statements_.select_image_version (im.version);
          b.version++;
          statement_->reload ();
        }
      }
    }

    template <typename T>
    void object_result_impl<T>::
    cache ()
    {
    }

    template <typename T>
    std::size_t object_result_impl<T>::
    size ()
    {
      throw result_not_cached ();
    }
  }
}
