// file      : odb/sqlite/view-result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/callback.hxx>
#include <odb/exceptions.hxx>

#include <odb/sqlite/view-statements.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    view_result_impl<T>::
    ~view_result_impl ()
    {
      if (!this->end_)
        statement_->free_result ();
    }

    template <typename T>
    void view_result_impl<T>::
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
    view_result_impl<T>::
    view_result_impl (const query_base& q,
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
    void view_result_impl<T>::
    load (view_type& view)
    {
      // The image can grow between calls to load() as a result of other
      // statements execution.
      //
      typename view_traits::image_type& im (statements_.image ());

      if (im.version != statements_.image_version ())
      {
        binding& b (statements_.image_binding ());
        tc_.bind (b.bind, im);
        statements_.image_version (im.version);
        b.version++;
      }

      select_statement::result r (statement_->load ());

      if (r == select_statement::truncated)
      {
        if (tc_.grow (im, statements_.image_truncated ()))
          im.version++;

        if (im.version != statements_.image_version ())
        {
          binding& b (statements_.image_binding ());
          tc_.bind (b.bind, im);
          statements_.image_version (im.version);
          b.version++;
          statement_->reload ();
        }
      }

      view_traits::callback (this->db_, view, callback_event::pre_load);
      tc_.init (view, im, &this->db_);
      view_traits::callback (this->db_, view, callback_event::post_load);
    }

    template <typename T>
    void view_result_impl<T>::
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
    void view_result_impl<T>::
    cache ()
    {
    }

    template <typename T>
    std::size_t view_result_impl<T>::
    size ()
    {
      throw result_not_cached ();
    }
  }
}
