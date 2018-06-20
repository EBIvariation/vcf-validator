// file      : odb/prepared-query.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_PREPARED_QUERY_HXX
#define ODB_PREPARED_QUERY_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx> // odb::core
#include <odb/traits.hxx>
#include <odb/result.hxx>
#include <odb/statement.hxx>

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  class LIBODB_EXPORT prepared_query_impl: public details::shared_base
  {
  public:
    virtual
    ~prepared_query_impl ();

    prepared_query_impl (connection&);

    bool cached;
    connection& conn;
    const char* name;
    details::shared_ptr<statement> stmt;
    details::shared_ptr<result_impl> (*execute) (prepared_query_impl&);

  private:
    prepared_query_impl (const prepared_query_impl&);
    prepared_query_impl& operator= (const prepared_query_impl&);

    // Doubly-linked list of results.
    //
    // prev_ ==    0 means we are the first element.
    // next_ ==    0 means we are the last element.
    // next_ == this means we are not on the list.
    //
  protected:
    friend class connection;

    void
    list_remove ();

    prepared_query_impl* prev_;
    prepared_query_impl* next_;
  };

  template <typename T>
  struct prepared_query
  {
    // Cached version.
    //
    explicit
    prepared_query (prepared_query_impl* impl = 0): impl_ (impl) {}

    // Uncached version.
    //
    explicit
    prepared_query (const details::shared_ptr<prepared_query_impl>& impl)
        : impl_ (impl.get ())
    {
      impl_->_inc_ref ();
    }

    result<T>
    execute (bool cache = true)
    {
      typedef
      typename result_base<T, class_traits<T>::kind>::result_impl_type
      derived_type;

      details::shared_ptr<result_impl> ri (impl_->execute (*impl_));
      result<T> r (
        details::shared_ptr<derived_type> (
          static_cast<derived_type*> (ri.release ())));

      if (cache)
        r.cache ();

      return r;
    }

    typename object_traits<T>::pointer_type
    execute_one ()
    {
      return execute (false).one ();
    }

    bool
    execute_one (T& object)
    {
      return execute (false).one (object);
    }

    T
    execute_value ()
    {
      // Compiler error pointing here? The object must be default-
      // constructible in order to use the return-by-value API.
      //
      T o;
      execute (false).value (o);
      return o;
    }

    const char*
    name () const
    {
      return impl_->name;
    }

    typedef odb::statement statement_type;

    statement_type&
    statement () const
    {
      return *impl_->stmt;
    }

    typedef prepared_query_impl* prepared_query::*unspecified_bool_type;
    operator unspecified_bool_type () const
    {
      return impl_ ? &prepared_query::impl_ : 0;
    }

  public:
    ~prepared_query ()
    {
      if (impl_ != 0 && !impl_->cached && impl_->_dec_ref ())
        delete impl_;
    }

    prepared_query (const prepared_query& x)
        : impl_ (x.impl_)
    {
      if (!impl_->cached)
        impl_->_inc_ref ();
    }

    prepared_query&
    operator= (const prepared_query& x)
    {
      if (impl_ != x.impl_)
      {
        if (impl_ != 0 && !impl_->cached && impl_->_dec_ref ())
          delete impl_;

        impl_ = x.impl_;

        if (!impl_->cached)
          impl_->_inc_ref ();
      }

      return *this;
    }

  private:
    // Ideally, we would just use shared_ptr to manage the impl object.
    // However, there is a problem if the prepared query is cached on
    // the connection and the connection is released early when the
    // transaction is committed or rolled back. In this case, the
    // prepared_query object might still be around pointing to impl. If
    // this connection and the prepared query are then used by another
    // thread while we release the impl object, then we have a race
    // condition.
    //
    // To work around this problem we will simply "reference" the impl
    // object without counting if the prepared query is cached. For
    // transition from pointer to reference, see cache_query_() in
    // connection.cxx.
    //
    // You may also observe that in order to know whether this is a
    // cached prepared query or not, we have to read the cached data
    // member in the impl object. This does not cause a race because,
    // unlike the reference count, this member is immutable once set
    // to true.
    //
    friend class connection;
    prepared_query_impl* impl_;
  };

  namespace common
  {
    using odb::prepared_query;
  }
}

#include <odb/post.hxx>

#endif // ODB_PREPARED_QUERY_HXX
