// file      : odb/sqlite/no-id-object-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/callback.hxx>
#include <odb/exceptions.hxx> // result_not_cached

#include <odb/sqlite/no-id-object-statements.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    no_id_object_result_impl<T>::
    ~no_id_object_result_impl ()
    {
      if (!this->end_)
        statement_->free_result ();
    }

    template <typename T>
    void no_id_object_result_impl<T>::
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
    no_id_object_result_impl<T>::
    no_id_object_result_impl (const query_base& q,
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
    void no_id_object_result_impl<T>::
    load (object_type& obj)
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

      object_traits::callback (this->db_, obj, callback_event::pre_load);
      tc_.init (obj, im, &this->db_);
      object_traits::callback (this->db_, obj, callback_event::post_load);
    }

    template <typename T>
    void no_id_object_result_impl<T>::
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
    void no_id_object_result_impl<T>::
    cache ()
    {
    }

    template <typename T>
    std::size_t no_id_object_result_impl<T>::
    size ()
    {
      throw result_not_cached ();
    }
  }
}
