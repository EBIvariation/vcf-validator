// file      : odb/query-dynamic.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_QUERY_DYNAMIC_HXX
#define ODB_QUERY_DYNAMIC_HXX

#include <odb/pre.hxx>

#include <string>
#include <vector>
#include <cstddef> // std::size_t

#include <odb/forward.hxx>
#include <odb/query.hxx>

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  struct native_column_info;

  template <typename T>
  struct val_bind
  {
    typedef const T& type;

    explicit
    val_bind (type v): val (v) {}

    type val;
  };

  // Passing arrays by value in dynamic queries is not supported.
  // Pass by reference instead.
  //
  template <typename T, std::size_t N>
  struct val_bind<T[N]>;

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

  //
  //
  struct LIBODB_EXPORT query_param: details::shared_base
  {
    virtual ~query_param ();
    query_param (const void* v): value (v) {}

    const void* value;
  };

  // For by-value parameters we have to make a copy since the original
  // can be gone by the time we translate to native query.
  //
  template <typename T>
  struct val_query_param: query_param
  {
    val_query_param (const T& v): query_param (&copy), copy (v) {}

    T copy;
  };

  //
  //
  class LIBODB_EXPORT query_base
  {
  public:
    // Internally the query clause is stored in a Reverse Polish Notation-
    // like representation which also allows us to traverse it as a syntax
    // tree.
    //
    // Let's keep this class POD so that std::vector can do more
    // efficient copying, etc.
    //
    struct clause_part
    {
      // Note that the order of enumerators is important (used as indexes).
      //
      enum kind_type
      {
        kind_column,    // native_info points to the native_column_info array.

        kind_param_val, // data points to query_param while native_info points
        kind_param_ref, // to the native_column_info array.

        kind_native,    // data is the index in the strings vector.

        kind_true,      // true literal.
        kind_false,     // false literal.

        // Operators.
        //
        // For binary operators, data is the index of the last element
        // belonging to the left hand side sub-expression.
        //
        op_add,         // +  (concatenation of two sub-expressions)

        op_and,         // &&
        op_or,          // ||
        op_not,         // !

        op_null,        // is_null ()
        op_not_null,    // is_not_null ()

        op_in,          // in(), data is the number of arguments
        op_like,        // like(pattern)
        op_like_escape, // like(pattern, escape)

        op_eq,          // ==
        op_ne,          // !=
        op_lt,          // <
        op_gt,          // >
        op_le,          // <=
        op_ge           // >=
      };

      kind_type kind;
      std::size_t data;
      const native_column_info* native_info;
    };

  public:
    ~query_base ()
    {
      clear ();
    }

    query_base () {}

    // True or false literal.
    //
    explicit
    query_base (bool v)
    {
      append (v ? clause_part::kind_true : clause_part::kind_false, 0);
    }

    explicit
    query_base (const char* native)
    {
      append (native);
    }

    explicit
    query_base (const std::string& native)
    {
      append (native);
    }

    query_base (const query_column<bool>&);

    query_base (const query_base& x)
    {
      append (x);
    }

    query_base&
    operator= (const query_base& x)
    {
      if (this != &x)
      {
        clear ();
        append (x);
      }

      return *this;
    }

  public:
    template <typename T>
    static val_bind<T>
    _val (const T& x)
    {
      return val_bind<T> (x);
    }

    template <typename T>
    static ref_bind<T>
    _ref (const T& x)
    {
      return ref_bind<T> (x);
    }

    // Some compilers (notably VC++), when deducing const T& from const
    // array do not strip const from the array type. As a result, in the
    // above signatures we get, for example, T = const char[4] instead
    // of T = char[4], which is what we want. So to "fix" such compilers,
    // we will have to provide the following specialization of the above
    // _ref() function (we don't need _val() since we don't support passing
    // arrays by value; see val_bind definition).
    //
    template <typename T, std::size_t N>
    static ref_bind<T[N]>
    _ref (const T (&x) [N])
    {
      return ref_bind<T[N]> (x);
    }

  public:
    query_base&
    operator+= (const query_base&);

    query_base&
    operator+= (const std::string& native);

  public:
    bool
    empty () const
    {
      return clause_.empty ();
    }

    bool
    const_true () const
    {
      return clause_.size () == 1 &&
        clause_.front ().kind == clause_part::kind_true;
    }

    // Implementation details.
    //
  public:
    explicit
    query_base (const native_column_info* c)
    {
      append (c);
    }

    // Native.
    //
    void
    append (const std::string&);

    // Query fragment.
    //
    void
    append (const query_base&);

    // Operator.
    //
    void
    append (clause_part::kind_type k, std::size_t data)
    {
      clause_.push_back (clause_part ());
      clause_.back ().kind = k;
      clause_.back ().data = data;
    }

    // Column.
    //
    void
    append (const native_column_info* c)
    {
      clause_.push_back (clause_part ());
      clause_.back ().kind = clause_part::kind_column;
      clause_.back ().native_info = c;
    }

    // Parameter.
    //
    void
    append_ref (const void* ref, const native_column_info*);

    template <typename T>
    void
    append_val (const T& val, const native_column_info*);

    void
    clear ();

  public:
    typedef std::vector<clause_part> clause_type;
    typedef std::vector<std::string> strings_type;

    const clause_type&
    clause () const
    {
      return clause_;
    }

    const strings_type&
    strings () const
    {
      return strings_;
    }

  private:
    clause_type clause_;
    strings_type strings_;
  };

  inline query_base
  operator+ (const query_base& x, const query_base& y)
  {
    query_base r (x);
    r += y;
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

  LIBODB_EXPORT query_base
  operator&& (const query_base&, const query_base&);

  LIBODB_EXPORT query_base
  operator|| (const query_base&, const query_base&);

  LIBODB_EXPORT query_base
  operator! (const query_base&);

  //
  //
  struct native_column_info
  {
    const void* column;
    void* param_factory;
  };

  template <typename T>
  const T&
  type_instance ();

  // This class template has to remain POD since we rely on it being
  // 0-initialized before any dynamic initialization takes place in
  // any other translation unit.
  //
  template <typename T>
  struct query_column
  {
    // Array of pointers to database-specific columns. It will be
    // automatically zero-initialized since query_column instances
    // are always static.
    //
    native_column_info native_info[database_count];

    // is_null, is_not_null
    //
  public:
    query_base
    is_null () const
    {
      query_base q (native_info);
      q.append (query_base::clause_part::op_null, 0);
      return q;
    }

    query_base
    is_not_null () const
    {
      query_base q (native_info);
      q.append (query_base::clause_part::op_not_null, 0);
      return q;
    }

    // in
    //
  public:
    query_base
    in (const T&, const T&) const;

    query_base
    in (const T&, const T&, const T&) const;

    query_base
    in (const T&, const T&, const T&, const T&) const;

    query_base
    in (const T&, const T&, const T&, const T&, const T&) const;

    template <typename I>
    query_base
    in_range (I begin, I end) const;

    // like
    //
  public:
    query_base
    like (const T& pattern) const
    {
      return like (val_bind<T> (pattern));
    }

    query_base
    like (val_bind<T> pattern) const;

    template <typename T2>
    query_base
    like (val_bind<T2> pattern) const
    {
      return like (val_bind<T> (T (pattern.val)));
    }

    query_base
    like (ref_bind<T> pattern) const;

    query_base
    like (const T& pattern, const T& escape) const
    {
      return like (val_bind<T> (pattern), escape);
    }

    query_base
    like (val_bind<T> pattern, const T& escape) const;

    template <typename T2>
    query_base
    like (val_bind<T2> pattern, const T& escape) const
    {
      return like (val_bind<T> (T (pattern.val)), escape);
    }

    query_base
    like (ref_bind<T> pattern, const T& escape) const;

    // ==
    //
  public:
    query_base
    equal (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_eq, 0);
      return q;
    }

    query_base
    equal (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_eq, 0);
      return q;
    }

    friend query_base
    operator== (const query_column& c, const T& v)
    {
      return c.equal (val_bind<T> (v));
    }

    friend query_base
    operator== (const T& v, const query_column& c)
    {
      return c.equal (val_bind<T> (v));
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
      return c.equal (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator== (val_bind<T2> v, const query_column& c)
    {
      return c.equal (val_bind<T> (T (v.val)));
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
    unequal (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_ne, 0);
      return q;
    }

    query_base
    unequal (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_ne, 0);
      return q;
    }

    friend query_base
    operator!= (const query_column& c, const T& v)
    {
      return c.unequal (val_bind<T> (v));
    }

    friend query_base
    operator!= (const T& v, const query_column& c)
    {
      return c.unequal (val_bind<T> (v));
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
      return c.unequal (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator!= (val_bind<T2> v, const query_column& c)
    {
      return c.unequal (val_bind<T> (T (v.val)));
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
    less (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_lt, 0);
      return q;
    }

    query_base
    less (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_lt, 0);
      return q;
    }

    friend query_base
    operator< (const query_column& c, const T& v)
    {
      return c.less (val_bind<T> (v));
    }

    friend query_base
    operator< (const T& v, const query_column& c)
    {
      return c.greater (val_bind<T> (v));
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
      return c.less (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator< (val_bind<T2> v, const query_column& c)
    {
      return c.greater (val_bind<T> (T (v.val)));
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
    greater (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_gt, 0);
      return q;
    }

    query_base
    greater (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_gt, 0);
      return q;
    }

    friend query_base
    operator> (const query_column& c, const T& v)
    {
      return c.greater (val_bind<T> (v));
    }

    friend query_base
    operator> (const T& v, const query_column& c)
    {
      return c.less (val_bind<T> (v));
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
      return c.greater (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator> (val_bind<T2> v, const query_column& c)
    {
      return c.less (val_bind<T> (T (v.val)));
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
    less_equal (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_le, 0);
      return q;
    }

    query_base
    less_equal (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_le, 0);
      return q;
    }

    friend query_base
    operator<= (const query_column& c, const T& v)
    {
      return c.less_equal (val_bind<T> (v));
    }

    friend query_base
    operator<= (const T& v, const query_column& c)
    {
      return c.greater_equal (val_bind<T> (v));
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
      return c.less_equal (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator<= (val_bind<T2> v, const query_column& c)
    {
      return c.greater_equal (val_bind<T> (T (v.val)));
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
    greater_equal (val_bind<T> v) const
    {
      query_base q (native_info);
      q.append_val (v.val, native_info);
      q.append (query_base::clause_part::op_ge, 0);
      return q;
    }

    query_base
    greater_equal (ref_bind<T> r) const
    {
      query_base q (native_info);
      q.append_ref (r.ptr (), native_info);
      q.append (query_base::clause_part::op_ge, 0);
      return q;
    }

    friend query_base
    operator>= (const query_column& c, const T& v)
    {
      return c.greater_equal (val_bind<T> (v));
    }

    friend query_base
    operator>= (const T& v, const query_column& c)
    {
      return c.less_equal (val_bind<T> (v));
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
      return c.greater_equal (val_bind<T> (T (v.val)));
    }

    template <typename T2>
    friend query_base
    operator>= (val_bind<T2> v, const query_column& c)
    {
      return c.less_equal (val_bind<T> (T (v.val)));
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
    template <typename T2>
    query_base
    operator== (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () == type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_eq, 0);
      return q;
    }

    template <typename T2>
    query_base
    operator!= (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () != type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_ne, 0);
      return q;
    }

    template <typename T2>
    query_base
    operator< (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () < type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_lt, 0);
      return q;
    }

    template <typename T2>
    query_base
    operator> (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () > type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_gt, 0);
      return q;
    }

    template <typename T2>
    query_base
    operator<= (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () <= type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_le, 0);
      return q;
    }

    template <typename T2>
    query_base
    operator>= (const query_column<T2>& c) const
    {
      // We can compare columns only if we can compare their C++ types.
      //
      (void) (sizeof (type_instance<T> () >= type_instance<T2> ()));

      query_base q (native_info);
      q.append (c.native_info);
      q.append (query_base::clause_part::op_ge, 0);
      return q;
    }
  };

  // Provide operator+() for using columns to construct native
  // query fragments (e.g., ORDER BY).
  //
  template <typename T>
  inline query_base
  operator+ (const query_column<T>& c, const std::string& s)
  {
    query_base q (c.native_info);
    q.append (s);
    q.append (query_base::clause_part::op_add, 0);
    return q;
  }

  template <typename T>
  inline query_base
  operator+ (const std::string& s, const query_column<T>& c)
  {
    query_base q (s);
    q.append (c.native_info);
    q.append (query_base::clause_part::op_add, 0);
    return q;
  }

  template <typename T>
  inline query_base
  operator+ (const query_column<T>& c, const query_base& q)
  {
    query_base r (c.native_info);
    r.append (q);
    r.append (query_base::clause_part::op_add, 0);
    return r;
  }

  template <typename T>
  inline query_base
  operator+ (const query_base& q, const query_column<T>& c)
  {
    query_base r (q);
    r.append (c.native_info);
    r.append (query_base::clause_part::op_add, q.clause ().size () - 1);
    return r;
  }

  //
  //
  template <typename T>
  class query<T, query_base>: public query_base,
                              public query_selector<T, id_common>::columns_type
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

    query (const query_base& q)
        : query_base (q)
    {
    }

    query (const query_column<bool>& qc)
        : query_base (qc)
    {
    }
  };
}

#include <odb/query-dynamic.ixx>
#include <odb/query-dynamic.txx>

#include <odb/post.hxx>

#endif // ODB_QUERY_DYNAMIC_HXX
