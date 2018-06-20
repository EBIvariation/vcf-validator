// file      : odb/sqlite/query.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_QUERY_HXX
#define ODB_SQLITE_QUERY_HXX

#include <odb/pre.hxx>

#include <string>
#include <vector>
#include <cstddef> // std::size_t

#include <odb/forward.hxx>            // odb::query_column
#include <odb/query.hxx>
#include <odb/details/buffer.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/binding.hxx>

#include <odb/sqlite/details/export.hxx>
#include <odb/sqlite/details/conversion.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    struct val_bind
    {
      typedef const T& type;

      explicit
      val_bind (type v): val (v) {}

      type val;
    };

    template <typename T, std::size_t N>
    struct val_bind<T[N]>
    {
      typedef const T* type;

      explicit
      val_bind (type v): val (v) {}

      type val;
    };

    template <typename T>
    struct ref_bind
    {
      typedef const T& type;

      explicit
      ref_bind (type r): ref (r) {}

      const void*
      ptr () const {return &ref;}

      type ref;
    };

    template <typename T, std::size_t N>
    struct ref_bind<T[N]>
    {
      typedef const T* type;

      explicit
      ref_bind (type r): ref (r) {}

      // Allow implicit conversion from decayed ref_bind's.
      //
      ref_bind (ref_bind<T*> r): ref (r.ref) {}
      ref_bind (ref_bind<const T*> r): ref (r.ref) {}

      const void*
      ptr () const {return ref;}

      type ref;
    };

    template <typename T, database_type_id ID>
    struct val_bind_typed: val_bind<T>
    {
      explicit
      val_bind_typed (typename val_bind<T>::type v): val_bind<T> (v) {}
    };

    template <typename T, database_type_id ID>
    struct ref_bind_typed: ref_bind<T>
    {
      explicit
      ref_bind_typed (typename ref_bind<T>::type r): ref_bind<T> (r) {}
    };

    struct LIBODB_SQLITE_EXPORT query_param: details::shared_base
    {
      virtual
      ~query_param ();

      bool
      reference () const
      {
        return value_ != 0;
      }

      virtual bool
      init () = 0;

      virtual void
      bind (sqlite::bind*) = 0;

    protected:
      query_param (const void* value)
          : value_ (value)
      {
      }

    protected:
      const void* value_;
    };

    class query_base;

    class LIBODB_SQLITE_EXPORT query_params: public details::shared_base
    {
    public:
      typedef sqlite::binding binding_type;

      void
      init ();

      binding_type&
      binding () {return binding_;}

    private:
      friend class query_base;

      query_params (): binding_ (0, 0) {}
      query_params (const query_params&);

      query_params&
      operator= (const query_params&);

      query_params&
      operator+= (const query_params&);

      void
      add (details::shared_ptr<query_param>);

    private:
      typedef std::vector<details::shared_ptr<query_param> > params;

      params params_;
      std::vector<sqlite::bind> bind_;
      binding_type binding_;
    };

    //
    //
    template <typename T, database_type_id ID>
    struct query_column;

    class LIBODB_SQLITE_EXPORT query_base
    {
    public:
      struct clause_part
      {
        enum kind_type
        {
          kind_column,
          kind_param,
          kind_native,
          kind_bool
        };

        clause_part (kind_type k): kind (k) {}
        clause_part (kind_type k, const std::string& p): kind (k), part (p) {}
        clause_part (bool p): kind (kind_bool), bool_part (p) {}

        kind_type kind;
        std::string part; // If kind is param, then part is conversion expr.
        bool bool_part;
      };

      query_base ()
        : parameters_ (new (details::shared) query_params)
      {
      }

      // True or false literal.
      //
      explicit
      query_base (bool v)
        : parameters_ (new (details::shared) query_params)
      {
        append (v);
      }

      explicit
      query_base (const char* native)
        : parameters_ (new (details::shared) query_params)
      {
        clause_.push_back (clause_part (clause_part::kind_native, native));
      }

      explicit
      query_base (const std::string& native)
        : parameters_ (new (details::shared) query_params)
      {
        clause_.push_back (clause_part (clause_part::kind_native, native));
      }

      query_base (const char* table, const char* column)
        : parameters_ (new (details::shared) query_params)
      {
        append (table, column);
      }

      template <typename T>
      explicit
      query_base (val_bind<T> v)
        : parameters_ (new (details::shared) query_params)
      {
        *this += v;
      }

      template <typename T, database_type_id ID>
      explicit
      query_base (val_bind_typed<T, ID> v)
        : parameters_ (new (details::shared) query_params)
      {
        *this += v;
      }

      template <typename T>
      explicit
      query_base (ref_bind<T> r)
        : parameters_ (new (details::shared) query_params)
      {
        *this += r;
      }

      template <typename T, database_type_id ID>
      explicit
      query_base (ref_bind_typed<T, ID> r)
        : parameters_ (new (details::shared) query_params)
      {
        *this += r;
      }

      template <database_type_id ID>
      query_base (const query_column<bool, ID>&);

      // Translate common query representation to SQLite native. Defined
      // in query-dynamic.cxx
      //
      query_base (const odb::query_base&);

      // Copy c-tor and assignment.
      //
      query_base (const query_base&);

      query_base&
      operator= (const query_base&);

    public:
      std::string
      clause () const;

      const char*
      clause_prefix () const;

      // Initialize the by-reference parameters from bound variables.
      //
      void
      init_parameters () const;

      binding&
      parameters_binding () const;

      const details::shared_ptr<query_params>&
      parameters () const;

    public:
      bool
      empty () const
      {
        return clause_.empty ();
      }

      static const query_base true_expr;

      bool
      const_true () const
      {
        return clause_.size () == 1 &&
          clause_.front ().kind == clause_part::kind_bool &&
          clause_.front ().bool_part;
      }

      void
      optimize ();

    public:
      template <typename T>
      static val_bind<T>
      _val (const T& x)
      {
        return val_bind<T> (x);
      }

      template <database_type_id ID, typename T>
      static val_bind_typed<T, ID>
      _val (const T& x)
      {
        return val_bind_typed<T, ID> (x);
      }

      template <typename T>
      static ref_bind<T>
      _ref (const T& x)
      {
        return ref_bind<T> (x);
      }

      template <database_type_id ID, typename T>
      static ref_bind_typed<T, ID>
      _ref (const T& x)
      {
        return ref_bind_typed<T, ID> (x);
      }

      // Some compilers (notably VC++), when deducing const T& from const
      // array do not strip const from the array type. As a result, in the
      // above signatures we get, for example, T = const char[4] instead
      // of T = char[4], which is what we want. So to "fix" such compilers,
      // we will have to provide the following specializations of the above
      // functions.
      //
      template <typename T, std::size_t N>
      static val_bind<T[N]>
      _val (const T (&x) [N])
      {
        return val_bind<T[N]> (x);
      }

      template <database_type_id ID, typename T, std::size_t N>
      static val_bind_typed<T[N], ID>
      _val (const T (&x) [N])
      {
        return val_bind_typed<T[N], ID> (x);
      }

      template <typename T, std::size_t N>
      static ref_bind<T[N]>
      _ref (const T (&x) [N])
      {
        return ref_bind<T[N]> (x);
      }

      template <database_type_id ID, typename T, std::size_t N>
      static ref_bind_typed<T[N], ID>
      _ref (const T (&x) [N])
      {
        return ref_bind_typed<T[N], ID> (x);
      }

    public:
      query_base&
      operator+= (const query_base&);

      query_base&
      operator+= (const std::string& q)
      {
        append (q);
        return *this;
      }

      template <typename T>
      query_base&
      operator+= (val_bind<T> v)
      {
        append<T, type_traits<T>::db_type_id> (
          v, details::conversion<T>::to ());
        return *this;
      }

      template <typename T, database_type_id ID>
      query_base&
      operator+= (val_bind_typed<T, ID> v)
      {
        // We are not using default type_traits so no default conversion
        // either.
        //
        append<T, ID> (v, 0);
        return *this;
      }

      template <typename T>
      query_base&
      operator+= (ref_bind<T> r)
      {
        append<T, type_traits<T>::db_type_id> (
          r, details::conversion<T>::to ());
        return *this;
      }

      template <typename T, database_type_id ID>
      query_base&
      operator+= (ref_bind_typed<T, ID> r)
      {
        // We are not using default type_traits so no default conversion
        // either.
        //
        append<T, ID> (r, 0);
        return *this;
      }

      // Implementation details.
      //
    public:
      template <typename T, database_type_id ID>
      void
      append (val_bind<T>, const char* conv);

      template <typename T, database_type_id ID>
      void
      append (ref_bind<T>, const char* conv);

      void
      append (details::shared_ptr<query_param>, const char* conv);

      void
      append (bool v)
      {
        clause_.push_back (clause_part (v));
      }

      void
      append (const std::string& native);

      void
      append (const char* native) // Clashes with append(bool).
      {
        append (std::string (native));
      }

      void
      append (const char* table, const char* column);

    private:
      typedef std::vector<clause_part> clause_type;

      clause_type clause_;
      details::shared_ptr<query_params> parameters_;
    };

    inline query_base
    operator+ (const query_base& x, const query_base& y)
    {
      query_base r (x);
      r += y;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (const query_base& q, val_bind<T> b)
    {
      query_base r (q);
      r += b;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (val_bind<T> b, const query_base& q)
    {
      query_base r;
      r += b;
      r += q;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const query_base& q, val_bind_typed<T, ID> b)
    {
      query_base r (q);
      r += b;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (val_bind_typed<T, ID> b, const query_base& q)
    {
      query_base r;
      r += b;
      r += q;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (const query_base& q, ref_bind<T> b)
    {
      query_base r (q);
      r += b;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (ref_bind<T> b, const query_base& q)
    {
      query_base r;
      r += b;
      r += q;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const query_base& q, ref_bind_typed<T, ID> b)
    {
      query_base r (q);
      r += b;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (ref_bind_typed<T, ID> b, const query_base& q)
    {
      query_base r;
      r += b;
      r += q;
      return r;
    }

    inline query_base
    operator+ (const query_base& q, const std::string& s)
    {
      query_base r (q);
      r += s;
      return r;
    }

    inline query_base
    operator+ (const std::string& s, const query_base& q)
    {
      query_base r (s);
      r += q;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (const std::string& s, val_bind<T> b)
    {
      query_base r (s);
      r += b;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (val_bind<T> b, const std::string& s)
    {
      query_base r;
      r += b;
      r += s;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const std::string& s, val_bind_typed<T, ID> b)
    {
      query_base r (s);
      r += b;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (val_bind_typed<T, ID> b, const std::string& s)
    {
      query_base r;
      r += b;
      r += s;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (const std::string& s, ref_bind<T> b)
    {
      query_base r (s);
      r += b;
      return r;
    }

    template <typename T>
    inline query_base
    operator+ (ref_bind<T> b, const std::string& s)
    {
      query_base r;
      r += b;
      r += s;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const std::string& s, ref_bind_typed<T, ID> b)
    {
      query_base r (s);
      r += b;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (ref_bind_typed<T, ID> b, const std::string& s)
    {
      query_base r;
      r += b;
      r += s;
      return r;
    }

    LIBODB_SQLITE_EXPORT query_base
    operator&& (const query_base&, const query_base&);

    LIBODB_SQLITE_EXPORT query_base
    operator|| (const query_base&, const query_base&);

    LIBODB_SQLITE_EXPORT query_base
    operator! (const query_base&);

    // query_column
    //
    struct LIBODB_SQLITE_EXPORT query_column_base
    {
      // Note that we keep shallow copies of the table, column, and conversion
      // expression. The latter can be NULL.
      //
      query_column_base (const char* table,
                         const char* column,
                         const char* conv)
          : table_ (table), column_ (column), conversion_ (conv)
      {
      }

      const char*
      table () const
      {
        return table_;
      }

      const char*
      column () const
      {
        return column_;
      }

      // Can be NULL.
      //
      const char*
      conversion () const
      {
        return conversion_;
      }

    protected:
      const char* table_;
      const char* column_;
      const char* conversion_;
    };

    template <typename T, database_type_id ID>
    struct query_column: query_column_base
    {
      typedef typename decay_traits<T>::type decayed_type;

      // Note that we keep shallow copies of the table, column, and conversion
      // expression. The latter can be NULL.
      //
      query_column (const char* table, const char* column, const char* conv)
          : query_column_base (table, column, conv) {}

      // Implementation is in query-dynamic.ixx.
      //
      query_column (odb::query_column<T>&,
                    const char* table, const char* column, const char* conv);

      // is_null, is_not_null
      //
    public:
      query_base
      is_null () const
      {
        query_base q (table_, column_);
        q += "IS NULL";
        return q;
      }

      query_base
      is_not_null () const
      {
        query_base q (table_, column_);
        q += "IS NOT NULL";
        return q;
      }

      // in
      //
    public:
      query_base
      in (decayed_type, decayed_type) const;

      query_base
      in (decayed_type, decayed_type, decayed_type) const;

      query_base
      in (decayed_type, decayed_type, decayed_type, decayed_type) const;

      query_base
      in (decayed_type, decayed_type, decayed_type, decayed_type,
          decayed_type) const;

      template <typename I>
      query_base
      in_range (I begin, I end) const;

      // like
      //
    public:
      query_base
      like (decayed_type pattern) const
      {
        return like (val_bind<T> (pattern));
      }

      query_base
      like (val_bind<T> pattern) const;

      template <typename T2>
      query_base
      like (val_bind<T2> pattern) const
      {
        return like (val_bind<T> (decayed_type (pattern.val)));
      }

      query_base
      like (ref_bind<T> pattern) const;

      query_base
      like (decayed_type pattern, decayed_type escape) const
      {
        return like (val_bind<T> (pattern), escape);
      }

      query_base
      like (val_bind<T> pattern, decayed_type escape) const;

      template <typename T2>
      query_base
      like (val_bind<T2> pattern, decayed_type escape) const
      {
        return like (val_bind<T> (decayed_type (pattern.val)), escape);
      }

      query_base
      like (ref_bind<T> pattern, decayed_type escape) const;

      // =
      //
    public:
      query_base
      equal (decayed_type v) const
      {
        return equal (val_bind<T> (v));
      }

      query_base
      equal (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += "=";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      equal (val_bind<T2> v) const
      {
        return equal (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      equal (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += "=";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator== (const query_column& c, decayed_type v)
      {
        return c.equal (v);
      }

      friend query_base
      operator== (decayed_type v, const query_column& c)
      {
        return c.equal (v);
      }

      friend query_base
      operator== (const query_column& c, val_bind<T> v)
      {
        return c.equal (v);
      }

      friend query_base
      operator== (val_bind<T> v, const query_column& c)
      {
        return c.equal (v);
      }

      template <typename T2>
      friend query_base
      operator== (const query_column& c, val_bind<T2> v)
      {
        return c.equal (v);
      }

      template <typename T2>
      friend query_base
      operator== (val_bind<T2> v, const query_column& c)
      {
        return c.equal (v);
      }

      friend query_base
      operator== (const query_column& c, ref_bind<T> r)
      {
        return c.equal (r);
      }

      friend query_base
      operator== (ref_bind<T> r, const query_column& c)
      {
        return c.equal (r);
      }

      // !=
      //
    public:
      query_base
      unequal (decayed_type v) const
      {
        return unequal (val_bind<T> (v));
      }

      query_base
      unequal (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += "!=";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      unequal (val_bind<T2> v) const
      {
        return unequal (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      unequal (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += "!=";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator!= (const query_column& c, decayed_type v)
      {
        return c.unequal (v);
      }

      friend query_base
      operator!= (decayed_type v, const query_column& c)
      {
        return c.unequal (v);
      }

      friend query_base
      operator!= (const query_column& c, val_bind<T> v)
      {
        return c.unequal (v);
      }

      friend query_base
      operator!= (val_bind<T> v, const query_column& c)
      {
        return c.unequal (v);
      }

      template <typename T2>
      friend query_base
      operator!= (const query_column& c, val_bind<T2> v)
      {
        return c.unequal (v);
      }

      template <typename T2>
      friend query_base
      operator!= (val_bind<T2> v, const query_column& c)
      {
        return c.unequal (v);
      }

      friend query_base
      operator!= (const query_column& c, ref_bind<T> r)
      {
        return c.unequal (r);
      }

      friend query_base
      operator!= (ref_bind<T> r, const query_column& c)
      {
        return c.unequal (r);
      }

      // <
      //
    public:
      query_base
      less (decayed_type v) const
      {
        return less (val_bind<T> (v));
      }

      query_base
      less (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += "<";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      less (val_bind<T2> v) const
      {
        return less (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      less (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += "<";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator< (const query_column& c, decayed_type v)
      {
        return c.less (v);
      }

      friend query_base
      operator< (decayed_type v, const query_column& c)
      {
        return c.greater (v);
      }

      friend query_base
      operator< (const query_column& c, val_bind<T> v)
      {
        return c.less (v);
      }

      friend query_base
      operator< (val_bind<T> v, const query_column& c)
      {
        return c.greater (v);
      }

      template <typename T2>
      friend query_base
      operator< (const query_column& c, val_bind<T2> v)
      {
        return c.less (v);
      }

      template <typename T2>
      friend query_base
      operator< (val_bind<T2> v, const query_column& c)
      {
        return c.greater (v);
      }

      friend query_base
      operator< (const query_column& c, ref_bind<T> r)
      {
        return c.less (r);
      }

      friend query_base
      operator< (ref_bind<T> r, const query_column& c)
      {
        return c.greater (r);
      }

      // >
      //
    public:
      query_base
      greater (decayed_type v) const
      {
        return greater (val_bind<T> (v));
      }

      query_base
      greater (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += ">";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      greater (val_bind<T2> v) const
      {
        return greater (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      greater (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += ">";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator> (const query_column& c, decayed_type v)
      {
        return c.greater (v);
      }

      friend query_base
      operator> (decayed_type v, const query_column& c)
      {
        return c.less (v);
      }

      friend query_base
      operator> (const query_column& c, val_bind<T> v)
      {
        return c.greater (v);
      }

      friend query_base
      operator> (val_bind<T> v, const query_column& c)
      {
        return c.less (v);
      }

      template <typename T2>
      friend query_base
      operator> (const query_column& c, val_bind<T2> v)
      {
        return c.greater (v);
      }

      template <typename T2>
      friend query_base
      operator> (val_bind<T2> v, const query_column& c)
      {
        return c.less (v);
      }

      friend query_base
      operator> (const query_column& c, ref_bind<T> r)
      {
        return c.greater (r);
      }

      friend query_base
      operator> (ref_bind<T> r, const query_column& c)
      {
        return c.less (r);
      }

      // <=
      //
    public:
      query_base
      less_equal (decayed_type v) const
      {
        return less_equal (val_bind<T> (v));
      }

      query_base
      less_equal (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += "<=";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      less_equal (val_bind<T2> v) const
      {
        return less_equal (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      less_equal (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += "<=";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator<= (const query_column& c, decayed_type v)
      {
        return c.less_equal (v);
      }

      friend query_base
      operator<= (decayed_type v, const query_column& c)
      {
        return c.greater_equal (v);
      }

      friend query_base
      operator<= (const query_column& c, val_bind<T> v)
      {
        return c.less_equal (v);
      }

      friend query_base
      operator<= (val_bind<T> v, const query_column& c)
      {
        return c.greater_equal (v);
      }

      template <typename T2>
      friend query_base
      operator<= (const query_column& c, val_bind<T2> v)
      {
        return c.less_equal (v);
      }

      template <typename T2>
      friend query_base
      operator<= (val_bind<T2> v, const query_column& c)
      {
        return c.greater_equal (v);
      }

      friend query_base
      operator<= (const query_column& c, ref_bind<T> r)
      {
        return c.less_equal (r);
      }

      friend query_base
      operator<= (ref_bind<T> r, const query_column& c)
      {
        return c.greater_equal (r);
      }

      // >=
      //
    public:
      query_base
      greater_equal (decayed_type v) const
      {
        return greater_equal (val_bind<T> (v));
      }

      query_base
      greater_equal (val_bind<T> v) const
      {
        query_base q (table_, column_);
        q += ">=";
        q.append<T, ID> (v, conversion_);
        return q;
      }

      template <typename T2>
      query_base
      greater_equal (val_bind<T2> v) const
      {
        return greater_equal (val_bind<T> (decayed_type (v.val)));
      }

      query_base
      greater_equal (ref_bind<T> r) const
      {
        query_base q (table_, column_);
        q += ">=";
        q.append<T, ID> (r, conversion_);
        return q;
      }

      friend query_base
      operator>= (const query_column& c, decayed_type v)
      {
        return c.greater_equal (v);
      }

      friend query_base
      operator>= (decayed_type v, const query_column& c)
      {
        return c.less_equal (v);
      }

      friend query_base
      operator>= (const query_column& c, val_bind<T> v)
      {
        return c.greater_equal (v);
      }

      friend query_base
      operator>= (val_bind<T> v, const query_column& c)
      {
        return c.less_equal (v);
      }

      template <typename T2>
      friend query_base
      operator>= (const query_column& c, val_bind<T2> v)
      {
        return c.greater_equal (v);
      }

      template <typename T2>
      friend query_base
      operator>= (val_bind<T2> v, const query_column& c)
      {
        return c.less_equal (v);
      }

      friend query_base
      operator>= (const query_column& c, ref_bind<T> r)
      {
        return c.greater_equal (r);
      }

      friend query_base
      operator>= (ref_bind<T> r, const query_column& c)
      {
        return c.less_equal (r);
      }

      // Column comparison.
      //
    public:
      template <typename T2, database_type_id ID2>
      query_base
      operator== (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () ==
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += "=";
        q.append (c.table (), c.column ());
        return q;
      }

      template <typename T2, database_type_id ID2>
      query_base
      operator!= (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () !=
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += "!=";
        q.append (c.table (), c.column ());
        return q;
      }

      template <typename T2, database_type_id ID2>
      query_base
      operator< (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () <
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += "<";
        q.append (c.table (), c.column ());
        return q;
      }

      template <typename T2, database_type_id ID2>
      query_base
      operator> (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () >
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += ">";
        q.append (c.table (), c.column ());
        return q;
      }

      template <typename T2, database_type_id ID2>
      query_base
      operator<= (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () <=
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += "<=";
        q.append (c.table (), c.column ());
        return q;
      }

      template <typename T2, database_type_id ID2>
      query_base
      operator>= (const query_column<T2, ID2>& c) const
      {
        // We can compare columns only if we can compare their C++ types.
        //
        (void) (sizeof (decay_traits<T>::instance () >=
                        decay_traits<T2>::instance ()));

        query_base q (table_, column_);
        q += ">=";
        q.append (c.table (), c.column ());
        return q;
      }
    };

    // Provide operator+() for using columns to construct native
    // query fragments (e.g., ORDER BY).
    //
    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const query_column<T, ID>& c, const std::string& s)
    {
      query_base q (c.table (), c.column ());
      q += s;
      return q;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const std::string& s, const query_column<T, ID>& c)
    {
      query_base q (s);
      q.append (c.table (), c.column ());
      return q;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const query_column<T, ID>& c, const query_base& q)
    {
      query_base r (c.table (), c.column ());
      r += q;
      return r;
    }

    template <typename T, database_type_id ID>
    inline query_base
    operator+ (const query_base& q, const query_column<T, ID>& c)
    {
      query_base r (q);
      r.append (c.table (), c.column ());
      return r;
    }

    //
    //
    template <typename T, database_type_id>
    struct query_param_impl;

    // INTEGER
    //
    template <typename T>
    struct query_param_impl<T, id_integer>: query_param
    {
      query_param_impl (ref_bind<T> r) : query_param (r.ptr ()) {}
      query_param_impl (val_bind<T> v) : query_param (0) {init (v.val);}

      virtual bool
      init ()
      {
        init (*static_cast<const T*> (value_));
        return false;
      }

      virtual void
      bind (sqlite::bind* b)
      {
        b->type = sqlite::bind::integer;
        b->buffer = &image_;
      }

    private:
      void
      init (typename decay_traits<T>::type v)
      {
        bool is_null (false); // Can't be NULL.
        value_traits<T, id_integer>::set_image (image_, is_null, v);
      }

    private:
      long long image_;
    };

    // REAL
    //
    template <typename T>
    struct query_param_impl<T, id_real>: query_param
    {
      query_param_impl (ref_bind<T> r) : query_param (r.ptr ()) {}
      query_param_impl (val_bind<T> v) : query_param (0) {init (v.val);}

      virtual bool
      init ()
      {
        init (*static_cast<const T*> (value_));
        return false;
      }

      virtual void
      bind (sqlite::bind* b)
      {
        b->type = sqlite::bind::real;
        b->buffer = &image_;
      }

    private:
      void
      init (typename decay_traits<T>::type v)
      {
        bool is_null (false); // Can't be NULL.
        value_traits<T, id_real>::set_image (image_, is_null, v);
      }

    private:
      double image_;
    };

    // TEXT
    //
    template <typename T>
    struct query_param_impl<T, id_text>: query_param
    {
      query_param_impl (ref_bind<T> r) : query_param (r.ptr ()) {}
      query_param_impl (val_bind<T> v) : query_param (0) {init (v.val);}

      virtual bool
      init ()
      {
        return init (*static_cast<const T*> (value_));
      }

      virtual void
      bind (sqlite::bind* b)
      {
        b->type = image_traits<T, id_text>::bind_value;
        b->buffer = buffer_.data ();
        b->size = &size_;
      }

    private:
      bool
      init (typename decay_traits<T>::type v)
      {
        bool is_null (false); // Can't be NULL.
        std::size_t cap (buffer_.capacity ());
        value_traits<T, id_text>::set_image (buffer_, size_, is_null, v);
        return cap != buffer_.capacity ();
      }

    private:
      details::buffer buffer_;
      std::size_t size_;
    };

    // BLOB
    //
    template <typename T>
    struct query_param_impl<T, id_blob>: query_param
    {
      query_param_impl (ref_bind<T> r) : query_param (r.ptr ()) {}
      query_param_impl (val_bind<T> v) : query_param (0) {init (v.val);}

      virtual bool
      init ()
      {
        return init (*static_cast<const T*> (value_));
      }

      virtual void
      bind (sqlite::bind* b)
      {
        b->type = sqlite::bind::blob;
        b->buffer = buffer_.data ();
        b->size = &size_;
      }

    private:
      bool
      init (typename decay_traits<T>::type v)
      {
        bool is_null (false); // Can't be NULL.
        std::size_t cap (buffer_.capacity ());
        value_traits<T, id_blob>::set_image (buffer_, size_, is_null, v);
        return cap != buffer_.capacity ();
      }

    private:
      details::buffer buffer_;
      std::size_t size_;
    };
  }
}

// odb::sqlite::query and odb::query specialization for SQLite.
//
namespace odb
{
  namespace sqlite
  {
    template <typename T>
    class query: public query_base,
                 public query_selector<T, id_sqlite>::columns_type
    {
    public:
      // We don't define any typedefs here since they may clash with
      // column names defined by our base type.
      //

      query ()
      {
      }

      explicit
      query (bool v)
          : query_base (v)
      {
      }

      explicit
      query (const char* q)
          : query_base (q)
      {
      }

      explicit
      query (const std::string& q)
          : query_base (q)
      {
      }

      template <typename T2>
      explicit
      query (val_bind<T2> v)
          : query_base (v)
      {
      }

      template <typename T2>
      explicit
      query (ref_bind<T2> r)
          : query_base (r)
      {
      }

      query (const query_base& q)
          : query_base (q)
      {
      }

      template <database_type_id ID>
      query (const query_column<bool, ID>& qc)
          : query_base (qc)
      {
      }

      query (const odb::query_base& q)
          : query_base (q)
      {
      }
    };

    namespace core
    {
      using sqlite::query;
    }
  }

  // Derive odb::query from odb::sqlite::query so that it can be
  // implicitly converted in sqlite::database::query() calls.
  //
  template <typename T>
  class query<T, sqlite::query_base>: public sqlite::query<T>
  {
  public:
    // We don't define any typedefs here since they may clash with
    // column names defined by our base type.
    //

    query ()
    {
    }

    explicit
    query (bool v)
        : sqlite::query<T> (v)
    {
    }

    explicit
    query (const char* q)
        : sqlite::query<T> (q)
    {
    }

    explicit
    query (const std::string& q)
        : sqlite::query<T> (q)
    {
    }

    template <typename T2>
    explicit
    query (sqlite::val_bind<T2> v)
        : sqlite::query<T> (v)
    {
    }

    template <typename T2>
    explicit
    query (sqlite::ref_bind<T2> r)
        : sqlite::query<T> (r)
    {
    }

    query (const sqlite::query_base& q)
        : sqlite::query<T> (q)
    {
    }

    template <sqlite::database_type_id ID>
    query (const sqlite::query_column<bool, ID>& qc)
        : sqlite::query<T> (qc)
    {
    }
  };
}

#include <odb/sqlite/query.ixx>
#include <odb/sqlite/query.txx>

#include <odb/post.hxx>

#endif // ODB_SQLITE_QUERY_HXX
