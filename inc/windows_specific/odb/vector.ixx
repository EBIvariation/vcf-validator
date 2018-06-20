// file      : odb/vector.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  // construct/copy/destroy:
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline vector<T, A LIBODB_VECTOR_ARG_USE>&
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  operator= (const vector& x)
  {
    v_ = x.v_;
    if (_tracking ())
      impl_.assign (v_.size ());
    return *this;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  template <class I>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  assign (I f, I l)
  {
    v_.assign (f, l);
    if (_tracking ())
      impl_.assign (v_.size ());
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  assign (size_type n, const T& u)
  {
    v_.assign (n, u);
    if (_tracking ())
      impl_.assign (n);
  }

#ifdef ODB_CXX11
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline vector<T, A LIBODB_VECTOR_ARG_USE>&
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  operator=(vector&& x)
  {
    v_ = std::move (x.v_);
    if (_tracking ())
      impl_.assign (v_.size ());
    return *this;
  }

#ifdef ODB_CXX11_INITIALIZER_LIST
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline vector<T, A LIBODB_VECTOR_ARG_USE>&
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  operator= (std::initializer_list<T> il)
  {
    v_ = il;
    if (_tracking ())
      impl_.assign (v_.size ());
    return *this;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  assign (std::initializer_list<T> il)
  {
    v_.assign (il);
    if (_tracking ())
      impl_.assign (v_.size ());
  }
#endif
#endif

  // iterators:
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::base_iterator_type
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  mbegin ()
  {
    if (_tracking ())
      impl_.modify (0, v_.size ());
    return v_.begin ();
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline
  typename vector<T, A LIBODB_VECTOR_ARG_USE>::base_reverse_iterator_type
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  mrbegin ()
  {
    if (_tracking ())
      impl_.modify (0, v_.size ());
    return v_.rbegin ();
  }

  // capacity:
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  resize (size_type n)
  {
    v_.resize (n);
    if (_tracking ())
      impl_.resize (n);
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  resize (size_type n, const T& c)
  {
    v_.resize (n, c);
    if (_tracking ())
      impl_.resize (n);
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  reserve (size_type n)
  {
    v_.reserve (n);
    if (_tracking ())
      impl_.reserve (n);
  }

#ifdef ODB_CXX11
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  shrink_to_fit ()
  {
    v_.shrink_to_fit ();
    impl_.shrink_to_fit ();
  }
#endif

  // element access:
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::reference
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  modify (size_type n)
  {
    reference r (v_[n]);
    if (_tracking ())
      impl_.modify (n);
    return r;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::reference
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  modify_at (size_type n)
  {
    reference r (v_.at (n));
    if (_tracking ())
      impl_.modify (n);
    return r;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::reference
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  modify_front ()
  {
    reference r (v_.front ());
    if (_tracking ())
      impl_.modify (0);
    return r;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::reference
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  modify_back ()
  {
    reference r (v_.back ());
    if (_tracking ())
      impl_.modify (v_.size () - 1);
    return r;
  }

#ifdef ODB_CXX11
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline T* vector<T, A LIBODB_VECTOR_ARG_USE>::
  modify_data() /*noexcept*/
  {
    if (_tracking ())
      impl_.modify (0, v_.size ());
    return v_.data ();
  }
#endif

  // modifiers:
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  push_back (const T& x)
  {
    v_.push_back (x);
    if (_tracking ())
      impl_.push_back ();
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  pop_back ()
  {
    v_.pop_back ();
    if (_tracking ())
      impl_.pop_back ();
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::iterator
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  insert (iterator p, const T& x)
  {
    if (_tracking ())
      impl_.insert (static_cast<size_type> (p.base () - v_.begin ()));
    return iterator (this, v_.insert (p.base (), x));
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  insert (iterator p, size_type n, const T& x)
  {
    if (_tracking ())
      impl_.insert (static_cast<size_type> (p.base () - v_.begin ()), n);
    v_.insert (p.base (), n, x);
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  template <class I>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  insert (iterator p, I f, I l)
  {
    size_type i, n;
    if (_tracking ())
    {
      i = static_cast<size_type> (p.base () - v_.begin ());
      n = v_.size ();
    }

    v_.insert (p.base (), f, l);

    if (_tracking ())
      impl_.insert (i, v_.size () - n);
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::iterator
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  erase (iterator p)
  {
    if (_tracking ())
      impl_.erase (static_cast<size_type> (p.base () - v_.begin ()));
    return iterator (this, v_.erase (p.base ()));
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::iterator
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  erase (iterator f, iterator l)
  {
    if (_tracking ())
      impl_.erase (static_cast<size_type> (f.base () - v_.begin ()),
                   static_cast<size_type> (l - f));
    return iterator (this, v_.erase (f.base (), l.base ()));
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  swap (vector& x)
  {
    v_.swap (x.v_);
    vector_base::swap (x);
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  clear ()
  {
    v_.clear ();
    if (_tracking ())
      impl_.clear ();
  }

#ifdef ODB_CXX11
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  push_back(T&& x)
  {
    v_.push_back (std::move (x));
    if (_tracking ())
      impl_.push_back ();
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::iterator
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  insert (iterator p, T&& x)
  {
    base_iterator_type r (v_.insert (p.base (), std::move (x)));
    if (_tracking ())
      impl_.insert (static_cast<size_type> (r - v_.begin ()));
    return iterator (this, r);
  }

#ifdef ODB_CXX11_VARIADIC_TEMPLATE
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  template <class... Args>
  inline void vector<T, A LIBODB_VECTOR_ARG_USE>::
  emplace_back (Args&&... args)
  {
    v_.push_back (std::forward<Args> (args)...);
    if (_tracking ())
      impl_.push_back ();
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  template <class... Args>
  inline typename vector<T, A LIBODB_VECTOR_ARG_USE>::iterator
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  emplace (iterator p, Args&&... args)
  {
    base_iterator_type r (
      v_.emplace (p.base (), std::forward<Args> (args)...));
    if (_tracking ())
      impl_.insert (static_cast<size_type> (r - v_.begin ()));
    return iterator (this, r);
  }
#endif
#endif

  // Interfacing with base vector.
  //
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline vector<T, A LIBODB_VECTOR_ARG_USE>&
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  operator= (const base_vector_type& x)
  {
    v_ = x;
    if (_tracking ())
      impl_.assign (v_.size ());
    return *this;
  }

#ifdef ODB_CXX11
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline vector<T, A LIBODB_VECTOR_ARG_USE>&
  vector<T, A LIBODB_VECTOR_ARG_USE>::
  operator= (base_vector_type&& x)
  {
    v_ = std::move (x);
    if (_tracking ())
      impl_.assign (v_.size ());
    return *this;
  }
#endif
}
