// file      : odb/query-dynamic.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/query-dynamic.hxx>

using namespace std;

namespace odb
{
  // query_param
  //
  query_param::
  ~query_param ()
  {
  }

  // query_base
  //
  void query_base::
  clear ()
  {
    for (clause_type::iterator i (clause_.begin ()); i != clause_.end (); ++i)
    {
      if (i->kind == clause_part::kind_param_val ||
          i->kind == clause_part::kind_param_ref)
      {
        query_param* qp (reinterpret_cast<query_param*> (i->data));

        if (qp != 0 && qp->_dec_ref ())
          delete qp;
      }
    }

    clause_.clear ();
    strings_.clear ();
  }

  void query_base::
  append (const string& native)
  {
    strings_.push_back (native);
    clause_.push_back (clause_part ());
    clause_.back ().kind = clause_part::kind_native;
    clause_.back ().data = strings_.size () - 1;
  }

  void query_base::
  append (const query_base& x)
  {
    size_t i (clause_.size ()), delta (i);
    size_t n (i + x.clause_.size ());
    clause_.resize (n);

    for (size_t j (0); i < n; ++i, ++j)
    {
      const clause_part& s (x.clause_[j]);
      clause_part& d (clause_[i]);

      d = s;

      // We need to increment the param references, update pointers
      // to strings and update argument positions.
      //
      switch (s.kind)
      {
      case clause_part::kind_param_val:
      case clause_part::kind_param_ref:
        {
          reinterpret_cast<query_param*> (d.data)->_inc_ref ();
          break;
        }
      case clause_part::kind_native:
        {
          strings_.push_back (x.strings_[s.data]);
          d.data = strings_.size () - 1;
          break;
        }
      case clause_part::op_add:

      case clause_part::op_and:
      case clause_part::op_or:

      case clause_part::op_eq:
      case clause_part::op_ne:
      case clause_part::op_lt:
      case clause_part::op_gt:
      case clause_part::op_le:
      case clause_part::op_ge:
        {
          d.data += delta;
          break;
        }
        // Do not use default here to remember to handle new op codes.
        //
      case clause_part::kind_column:
      case clause_part::kind_true:
      case clause_part::kind_false:
      case clause_part::op_not:
      case clause_part::op_null:
      case clause_part::op_not_null:
      case clause_part::op_in:
      case clause_part::op_like:
      case clause_part::op_like_escape:
        break;
      }
    }
  }

  void query_base::
  append_ref (const void* ref, const native_column_info* c)
  {
    clause_.push_back (clause_part ());
    clause_part& p (clause_.back ());

    p.kind = clause_part::kind_param_ref;
    p.data = 0; // In case new below throws.
    p.native_info = c;

    p.data = reinterpret_cast<std::size_t> (
      new (details::shared) query_param (ref));
  }

  query_base& query_base::
  operator+= (const std::string& native)
  {
    if (!native.empty ())
    {
      size_t p (clause_.size ());
      append (native);

      if (p != 0)
        append (clause_part::op_add, p - 1);
    }

    return *this;
  }

  query_base& query_base::
  operator+= (const query_base& x)
  {
    if (!x.empty ())
    {
      size_t p (clause_.size ());
      append (x);

      if (p != 0)
        append (clause_part::op_add, p - 1);
    }

    return *this;
  }

  query_base
  operator&& (const query_base& x, const query_base& y)
  {
    // Optimize cases where one or both sides are constant truth.
    //
    bool xt (x.const_true ()), yt (y.const_true ());

    if (xt && yt)
      return x;

    if (xt || x.empty ())
      return y;

    if (yt || y.empty ())
      return x;

    query_base r (x);
    r.append (y);
    r.append (query_base::clause_part::op_and, x.clause ().size () - 1);
    return r;
  }

  query_base
  operator|| (const query_base& x, const query_base& y)
  {
    if (x.empty ())
      return y;

    if (y.empty ())
      return x;

    query_base r (x);
    r.append (y);
    r.append (query_base::clause_part::op_or, x.clause ().size () - 1);
    return r;
  }

  query_base
  operator! (const query_base& x)
  {
    if (x.empty ())
      return x;

    query_base r (x);
    r.append (query_base::clause_part::op_not, 0);
    return r;
  }
}
