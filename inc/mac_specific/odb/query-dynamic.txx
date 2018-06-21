// file      : odb/query-dynamic.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  //
  // query_base
  //

  template <typename T>
  void query_base::
  append_val (const T& val, const native_column_info* c)
  {
    clause_.push_back (clause_part ());
    clause_part& p (clause_.back ());

    p.kind = clause_part::kind_param_val;
    p.data = 0; // In case new below throws.
    p.native_info = c;

    query_param* qp (new (details::shared) val_query_param<T> (val));
    p.data = reinterpret_cast<std::size_t> (qp);
  }

  //
  // query_column
  //

  // in
  //
  template <typename T>
  query_base query_column<T>::
  in (const T& v1, const T& v2) const
  {
    query_base q (native_info);
    q.append_val (v1, native_info);
    q.append_val (v2, native_info);
    q.append (query_base::clause_part::op_in, 2);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  in (const T& v1, const T& v2, const T& v3) const
  {
    query_base q (native_info);
    q.append_val (v1, native_info);
    q.append_val (v2, native_info);
    q.append_val (v3, native_info);
    q.append (query_base::clause_part::op_in, 3);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  in (const T& v1, const T& v2, const T& v3, const T& v4) const
  {
    query_base q (native_info);
    q.append_val (v1, native_info);
    q.append_val (v2, native_info);
    q.append_val (v3, native_info);
    q.append_val (v4, native_info);
    q.append (query_base::clause_part::op_in, 4);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  in (const T& v1, const T& v2, const T& v3, const T& v4, const T& v5) const
  {
    query_base q (native_info);
    q.append_val (v1, native_info);
    q.append_val (v2, native_info);
    q.append_val (v3, native_info);
    q.append_val (v4, native_info);
    q.append_val (v5, native_info);
    q.append (query_base::clause_part::op_in, 5);
    return q;
  }

  template <typename T>
  template <typename I>
  query_base query_column<T>::
  in_range (I i, I end) const
  {
    query_base q (native_info);

    std::size_t n (0);
    for (; i != end; ++i, ++n)
      q.append_val<T> (*i, native_info); // Force implicit conversion.

    q.append (query_base::clause_part::op_in, n);
    return q;
  }

  // like
  //
  template <typename T>
  query_base query_column<T>::
  like (val_bind<T> p) const
  {
    query_base q (native_info);
    q.append_val (p.val, native_info);
    q.append (query_base::clause_part::op_like, 0);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  like (ref_bind<T> p) const
  {
    query_base q (native_info);
    q.append_ref (p.ptr (), native_info);
    q.append (query_base::clause_part::op_like, 0);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  like (val_bind<T> p, const T& e) const
  {
    query_base q (native_info);
    q.append_val (p.val, native_info);
    q.append_val (e, native_info);
    q.append (query_base::clause_part::op_like_escape, 0);
    return q;
  }

  template <typename T>
  query_base query_column<T>::
  like (ref_bind<T> p, const T& e) const
  {
    query_base q (native_info);
    q.append_ref (p.ptr (), native_info);
    q.append_val (e, native_info);
    q.append (query_base::clause_part::op_like_escape, 0);
    return q;
  }
}
