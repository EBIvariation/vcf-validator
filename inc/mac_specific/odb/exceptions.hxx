// file      : odb/exceptions.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_EXCEPTIONS_HXX
#define ODB_EXCEPTIONS_HXX

#include <odb/pre.hxx>

#include <set>
#include <string>
#include <cstddef>  // std::size_t
#include <typeinfo>

#include <odb/forward.hxx>    // schema_version, odb::core
#include <odb/exception.hxx>

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  struct LIBODB_EXPORT null_pointer: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual null_pointer*
    clone () const;
  };

  // Transaction exceptions.
  //
  struct LIBODB_EXPORT already_in_transaction: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual already_in_transaction*
    clone () const;
  };

  struct LIBODB_EXPORT not_in_transaction: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual not_in_transaction*
    clone () const;
  };

  struct LIBODB_EXPORT transaction_already_finalized: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual transaction_already_finalized*
    clone () const;
  };

  // Session exceptions.
  //
  struct LIBODB_EXPORT already_in_session: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual already_in_session*
    clone () const;
  };

  struct LIBODB_EXPORT not_in_session: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual not_in_session*
    clone () const;
  };

  struct LIBODB_EXPORT session_required: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual session_required*
    clone () const;
  };

  // Database operations exceptions.
  //
  struct LIBODB_EXPORT recoverable: odb::exception
  {
    // Abstract.
  };

  struct LIBODB_EXPORT connection_lost: recoverable
  {
    virtual const char*
    what () const throw ();

    virtual connection_lost*
    clone () const;
  };

  struct LIBODB_EXPORT timeout: recoverable
  {
    virtual const char*
    what () const throw ();

    virtual timeout*
    clone () const;
  };

  struct LIBODB_EXPORT deadlock: recoverable
  {
    virtual const char*
    what () const throw ();

    virtual deadlock*
    clone () const;
  };

  struct LIBODB_EXPORT object_not_persistent: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual object_not_persistent*
    clone () const;
  };

  struct LIBODB_EXPORT object_already_persistent: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual object_already_persistent*
    clone () const;
  };

  struct LIBODB_EXPORT object_changed: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual object_changed*
    clone () const;
  };

  struct LIBODB_EXPORT result_not_cached: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual result_not_cached*
    clone () const;
  };

  struct LIBODB_EXPORT database_exception: odb::exception
  {
    // Abstract.
  };

  // Polymorphism support exceptions.
  //
  struct LIBODB_EXPORT abstract_class: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual abstract_class*
    clone () const;
  };

  struct LIBODB_EXPORT no_type_info: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual no_type_info*
    clone () const;
  };

  // Prepared query support exceptions.
  //
  struct LIBODB_EXPORT prepared_already_cached: odb::exception
  {
    prepared_already_cached (const char* name);
    ~prepared_already_cached () throw ();

    const char*
    name () const
    {
      return name_;
    }

    virtual const char*
    what () const throw ();

    virtual prepared_already_cached*
    clone () const;

  private:
    const char* name_;
    std::string what_;
  };

  struct LIBODB_EXPORT prepared_type_mismatch: odb::exception
  {
    prepared_type_mismatch (const char* name);
    ~prepared_type_mismatch () throw ();

    const char*
    name () const {return name_;}

    virtual const char*
    what () const throw ();

    virtual prepared_type_mismatch*
    clone () const;

  private:
    const char* name_;
    std::string what_;
  };

  // Schema catalog exceptions.
  //
  struct LIBODB_EXPORT unknown_schema: odb::exception
  {
    unknown_schema (const std::string& name);
    ~unknown_schema () throw ();

    const std::string&
    name () const {return name_;}

    virtual const char*
    what () const throw ();

    virtual unknown_schema*
    clone () const;

  private:
    std::string name_;
    std::string what_;
  };

  struct LIBODB_EXPORT unknown_schema_version: odb::exception
  {
    unknown_schema_version (schema_version);
    ~unknown_schema_version () throw ();

    schema_version
    version () const {return version_;}

    virtual const char*
    what () const throw ();

    virtual unknown_schema_version*
    clone () const;

  private:
    schema_version version_;
    std::string what_;
  };

  // Section exceptions.
  //
  struct LIBODB_EXPORT section_not_loaded: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual section_not_loaded*
    clone () const;
  };

  struct LIBODB_EXPORT section_not_in_object: odb::exception
  {
    virtual const char*
    what () const throw ();

    virtual section_not_in_object*
    clone () const;
  };

  // Bulk operation exceptions.
  //
  struct LIBODB_EXPORT multiple_exceptions: odb::exception
  {
    struct LIBODB_EXPORT value_type
    {
      std::size_t
      position () const {return p_;}

      // If true, then this means that some positions in the batch have
      // triggered the exception but it is not possible, due to the
      // limitations of the underlying database API, to discern exactly
      // which ones. As a result, all the positions in the batch are
      // marked as "maybe failed".
      //
      bool
      maybe () const {return m_;}

      const odb::exception&
      exception () const {return *e_;}

      // Implementation details.
      //
    public:
      value_type (std::size_t p,
                  bool maybe,
                  details::shared_ptr<odb::exception> e)
          : m_ (maybe), p_ (p), e_ (e) {}

      value_type (std::size_t p): p_ (p) {} // "Key" for set lookup.

    private:
      bool m_;
      std::size_t p_;
      details::shared_ptr<odb::exception> e_;
    };

    struct LIBODB_EXPORT comparator_type
    {
      bool
      operator() (const value_type& x, const value_type& y) const
      {
        return x.position () < y.position ();
      }
    };

    typedef std::set<value_type, comparator_type> set_type;

    // Iteration.
    //
  public:
    typedef set_type::const_iterator iterator;
    typedef set_type::const_iterator const_iterator; // For pedantic types.

    iterator
    begin () const {return set_.begin ();}

    iterator
    end () const {return set_.end ();}

    // Lookup.
    //
  public:
    // Return NULL if the element at this position has no exception. Note
    // that the returned value is value_type* and not odb::exception* in
    // order to provide access to maybe(); see value_type::maybe() for
    // details.
    //
    const value_type*
    operator[] (std::size_t p) const
    {
      return set_.empty () ? 0 : lookup (p);
    }

    // Severity, failed and attempt counts.
    //
  public:
    // Return the number of elements for which the operation has been
    // attempted.
    //
    std::size_t
    attempted () const {return attempted_;}

    // Return the number of positions for which the operation has failed.
    // Note that this count includes the maybe failed positions.
    //
    std::size_t
    failed () const {return set_.size ();}

    // If fatal() returns true, then (some of) the exceptions were fatal.
    // In this case, even for elements that were processed but did not
    // cause the exception, no attempts were made to complete the bulk
    // operation and the transaction must be aborted.
    //
    // If fatal() returns false, then the operation on the elements that
    // don't have an exception has succeeded. The application can try to
    // correct the errors and re-attempt the operation on the elements
    // that did cause an exception. In either case, the transaction can
    // be committed.
    //
    bool
    fatal () const {return fatal_;}

    // Normally you shouldn't need to do this explicitly but you can
    // "upgrade" an exception to fatal, for example, for specific
    // database error codes.
    //
    void
    fatal (bool f) {fatal_ = fatal_ || f;}

    // odb::exception interface.
    //
  public:
    virtual const char*
    what () const throw ();

    virtual multiple_exceptions*
    clone () const;

    // Direct set access.
    //
  public:
    const set_type&
    set () const {return set_;}

    // Implementation details.
    //
  public:
    ~multiple_exceptions () throw ();

    // All instances of the common exception must be equal since we are
    // going to create and share just one.
    //
    multiple_exceptions (const std::type_info& common_exception_ti)
        : common_exception_ti_ (common_exception_ti),
          fatal_ (false),
          delta_ (0),
          current_ (0) {}

    // Set the attempted count as (delta + n).
    //
    void
    attempted (std::size_t n) {attempted_ = delta_ + n;}

    // Increment the position of the current batch. Also resets the
    // current position in the batch.
    //
    void
    delta (std::size_t d) {delta_ += d; current_ = 0;}

    // Current position in the batch.
    //
    std::size_t
    current () const {return current_;}

    void
    current (std::size_t c) {current_ = c;}

    void
    insert (std::size_t p,
            bool maybe,
            const odb::exception& e,
            bool fatal = false);

    void
    insert (std::size_t p, const odb::exception& e, bool fatal = false)
    {
      insert (p, false, e, fatal);
    }

    void
    insert (const odb::exception& e, bool fatal = false)
    {
      insert (current_, e, fatal);
    }

    bool
    empty () const {return set_.empty ();}

    void
    prepare ();

  private:
    const value_type*
    lookup (std::size_t p) const;

  private:
    const std::type_info& common_exception_ti_;
    details::shared_ptr<odb::exception> common_exception_;

    set_type set_;
    bool fatal_;
    std::size_t attempted_;
    std::size_t delta_;     // Position of the batch.
    std::size_t current_;   // Position in the batch.
    std::string what_;
  };

  namespace common
  {
    using odb::null_pointer;

    using odb::already_in_transaction;
    using odb::not_in_transaction;
    using odb::transaction_already_finalized;

    using odb::already_in_session;
    using odb::not_in_session;
    using odb::session_required;

    using odb::recoverable;
    using odb::deadlock;
    using odb::connection_lost;
    using odb::timeout;
    using odb::object_not_persistent;
    using odb::object_already_persistent;
    using odb::object_changed;
    using odb::result_not_cached;
    using odb::database_exception;

    using odb::abstract_class;
    using odb::no_type_info;

    using odb::unknown_schema;
    using odb::unknown_schema_version;

    using odb::section_not_loaded;
    using odb::section_not_in_object;

    using odb::multiple_exceptions;
  }
}

#include <odb/post.hxx>

#endif // ODB_EXCEPTIONS_HXX
