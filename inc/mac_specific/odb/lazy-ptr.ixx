// file      : odb/lazy-ptr.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  //
  // lazy_ptr
  //

  template <class T>
  inline lazy_ptr<T>::
  lazy_ptr (): p_ (0) {}

  template <class T>
  template <class Y>
  inline lazy_ptr<T>::
  lazy_ptr (Y* p): p_ (p) {}

  template <class T>
  inline lazy_ptr<T>::
  lazy_ptr (const lazy_ptr& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  template <class Y>
  inline lazy_ptr<T>::
  lazy_ptr (const lazy_ptr<Y>& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  inline lazy_ptr<T>& lazy_ptr<T>::
  operator= (const lazy_ptr& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_ptr<T>& lazy_ptr<T>::
  operator= (Y* r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_ptr<T>& lazy_ptr<T>::
  operator= (const lazy_ptr<Y>& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  inline void lazy_ptr<T>::
  swap (lazy_ptr& b)
  {
    T* p (p_);
    p_ = b.p_;
    b.p_ = p;
    i_.swap (b.i_);
  }

  template <class T>
  inline void lazy_ptr<T>::
  reset ()
  {
    p_ = 0;
    i_.reset ();
  }

  template <class T>
  template <class Y>
  inline void lazy_ptr<T>::
  reset (Y* p)
  {
    p_ = p;
    i_.reset ();
  }

  template <class T>
  inline T& lazy_ptr<T>::
  operator* () const
  {
    return *p_;
  }

  template <class T>
  inline T* lazy_ptr<T>::
  operator-> () const
  {
    return p_;
  }

  template <class T>
  inline T* lazy_ptr<T>::
  get () const
  {
    return p_;
  }

  template <class T>
  inline bool lazy_ptr<T>::
  loaded () const
  {
    bool i (i_);
    return (p_ == 0) != i; // !p_ XOR i
  }

  template <class T>
  inline T* lazy_ptr<T>::
  load () const
  {
    if (p_ == 0 && i_)
      p_ = i_.template load<T> (true); // Reset id.

    return p_;
  }

  template <class T>
  inline void lazy_ptr<T>::
  unload () const
  {
    typedef typename object_traits<T>::object_type object_type;

    if (p_)
    {
      if (i_.database () != 0)
        i_.reset_id (object_traits<object_type>::id (*p_));

      p_ = 0;
    }
  }

  template <class T>
  inline T* lazy_ptr<T>::
  get_eager () const
  {
    return p_;
  }

  template <class T>
  template <class DB, class ID>
  inline lazy_ptr<T>::
  lazy_ptr (DB& db, const ID& id): p_ (0), i_ (db, id) {}

  template <class T>
  template <class DB, class Y>
  inline lazy_ptr<T>::
  lazy_ptr (DB& db, Y* r)
      : p_ (r)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class ID>
  inline void lazy_ptr<T>::
  reset (DB& db, const ID& id)
  {
    p_ = 0;
    i_.reset (db, id);
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_ptr<T>::
  reset (DB& db, Y* r)
  {
    p_ = r;

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class O>
  inline typename object_traits<O>::id_type lazy_ptr<T>::
  object_id () const
  {
    typedef typename object_traits<T>::object_type object_type;

    return p_
      ? object_traits<object_type>::id (*p_)
      : i_.template object_id<O> ();
  }

  template <class T>
  inline typename lazy_ptr<T>::database_type& lazy_ptr<T>::
  database () const
  {
    return *i_.database ();
  }

  template <class T, class Y>
  inline bool
  operator== (const lazy_ptr<T>& a, const lazy_ptr<Y>& b)
  {
    return a.equal (b);
  }

  template <class T, class Y>
  inline bool
  operator!= (const lazy_ptr<T>& a, const lazy_ptr<Y>& b)
  {
    return !a.equal (b);
  }

  template <class T>
  inline void
  swap (lazy_ptr<T>& a, lazy_ptr<T>& b)
  {
    a.swap (b);
  }

  //
  // lazy_auto_ptr_ref
  //

  template <class T>
  inline lazy_auto_ptr_ref<T>::
  lazy_auto_ptr_ref (T* p, const lazy_ptr_impl_ref& i): p_ (p), i_ (i) {}

  //
  // lazy_auto_ptr
  //

  template <class T>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (T* p): p_ (p) {}

  template <class T>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (lazy_auto_ptr& r)
      : p_ (r.p_), i_ (static_cast<lazy_ptr_impl_ref> (r.i_))
  {
  }

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (lazy_auto_ptr<Y>& r)
      : p_ (r.p_), i_ (static_cast<lazy_ptr_impl_ref> (r.i_))
  {
  }

  template <class T>
  inline lazy_auto_ptr<T>& lazy_auto_ptr<T>::
  operator= (lazy_auto_ptr& r)
  {
    p_ = r.p_;
    i_ = static_cast<lazy_ptr_impl_ref> (r.i_);
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>& lazy_auto_ptr<T>::
  operator= (lazy_auto_ptr<Y>& r)
  {
    p_ = r.p_;
    i_ = static_cast<lazy_ptr_impl_ref> (r.i_);
    return *this;
  }

  template <class T>
  inline T& lazy_auto_ptr<T>::
  operator* () const
  {
    return *p_;
  }

  template <class T>
  inline T* lazy_auto_ptr<T>::
  operator-> () const
  {
    return p_.operator-> ();
  }

  template <class T>
  inline T* lazy_auto_ptr<T>::
  get () const
  {
    return p_.get ();
  }

  template <class T>
  inline T* lazy_auto_ptr<T>::
  release ()
  {
    i_.reset ();
    return p_.release ();
  }

  template <class T>
  inline void lazy_auto_ptr<T>::
  reset (T* p)
  {
    i_.reset ();
    p_.reset (p);
  }

  template <class T>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (const lazy_auto_ptr_ref<T>& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  inline lazy_auto_ptr<T>& lazy_auto_ptr<T>::
  operator= (const lazy_auto_ptr_ref<T>& r)
  {
    if (p_.get () != r.p_)
      p_.reset (r.p_);

    i_ = r.i_;
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>::
  operator lazy_auto_ptr_ref<Y> ()
  {
    return lazy_auto_ptr_ref<Y> (p_.release (), i_);
  }

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>::
  operator lazy_auto_ptr<Y> ()
  {
    return lazy_auto_ptr<Y> (*this);
  }

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (std::auto_ptr<Y>& r): p_ (r) {}

  template <class T>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (std::auto_ptr_ref<T> r): p_ (r) {}

  template <class T>
  template <class Y>
  inline lazy_auto_ptr<T>& lazy_auto_ptr<T>::
  operator= (std::auto_ptr<Y>& r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  inline lazy_auto_ptr<T>& lazy_auto_ptr<T>::
  operator= (std::auto_ptr_ref<T> r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  inline bool lazy_auto_ptr<T>::
  loaded () const
  {
    bool i (i_);
    return (p_.get () == 0) != i; // XOR
  }

  template <class T>
  inline std::auto_ptr<T>& lazy_auto_ptr<T>::
  load () const
  {
    if (p_.get () == 0 && i_)
    {
      std::auto_ptr<T> tmp (i_.template load<T> (true)); // Reset id.
      p_ = tmp;
    }

    return p_;
  }

  template <class T>
  inline void lazy_auto_ptr<T>::
  unload () const
  {
    typedef typename object_traits<T>::object_type object_type;

    if (p_.get () != 0)
    {
      if (i_.database () != 0)
        i_.reset_id (object_traits<object_type>::id (*p_));

      p_.reset ();
    }
  }

  template <class T>
  inline std::auto_ptr<T>& lazy_auto_ptr<T>::
  get_eager () const
  {
    return p_;
  }

  template <class T>
  template <class DB, class ID>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (DB& db, const ID& id): i_ (db, id) {}

  template <class T>
  template <class DB>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (DB& db, T* p)
      : p_ (p)
  {
    if (p)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_auto_ptr<T>::
  lazy_auto_ptr (DB& db, std::auto_ptr<Y>& p)
      : p_ (p)
  {
    if (p_.get () != 0)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class ID>
  inline void lazy_auto_ptr<T>::
  reset (DB& db, const ID& id)
  {
    p_.reset ();
    i_.reset (db, id);
  }

  template <class T>
  template <class DB>
  inline void lazy_auto_ptr<T>::
  reset (DB& db, T* p)
  {
    p_.reset (p);

    if (p)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_auto_ptr<T>::
  reset (DB& db, std::auto_ptr<Y>& p)
  {
    p_ = p;

    if (p_.get () != 0)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class O>
  inline typename object_traits<O>::id_type lazy_auto_ptr<T>::
  object_id () const
  {
    typedef typename object_traits<T>::object_type object_type;

    return p_.get () != 0
      ? object_traits<object_type>::id (*p_)
      : i_.template object_id<O> ();
  }

  template <class T>
  inline typename lazy_auto_ptr<T>::database_type& lazy_auto_ptr<T>::
  database () const
  {
    return *i_.database ();
  }

#ifdef ODB_CXX11

  //
  // lazy_unique_ptr
  //

  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr () {}

#ifdef ODB_CXX11_NULLPTR
  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (std::nullptr_t) {}
#endif

  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (pointer p): p_ (p) {}

  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (pointer p, const deleter_type& d): p_ (p, d) {}

  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (pointer p, deleter_type&& d): p_ (p, std::move (d)) {}

  template <class T, class D>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (lazy_unique_ptr&& r)
      : p_ (std::move (r.p_)), i_ (std::move (r.i_)) {}

  template <class T, class D>
  template <class T1, class D1>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (lazy_unique_ptr<T1, D1>&& r)
      : p_ (std::move (r.p_)), i_ (std::move (r.i_)) {}

  template <class T, class D>
  template <class T1>
  lazy_unique_ptr<T, D>::
  lazy_unique_ptr (std::auto_ptr<T1>&& r): p_ (std::move (r)) {}

#ifdef ODB_CXX11_NULLPTR
  template <class T, class D>
  lazy_unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  operator= (std::nullptr_t)
  {
    reset ();
    return *this;
  }
#endif

  template <class T, class D>
  lazy_unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  operator= (lazy_unique_ptr&& r)
  {
    p_ = std::move (r.p_);
    i_ = std::move (r.i_);
    return *this;
  }

  template <class T, class D>
  template <class T1, class D1>
  lazy_unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  operator= (lazy_unique_ptr<T1, D1>&& r)
  {
    p_ = std::move (r.p_);
    i_ = std::move (r.i_);
    return *this;
  }

  template <class T, class D>
  T& lazy_unique_ptr<T, D>::
  operator* () const
  {
    return *p_;
  }

  template <class T, class D>
  typename lazy_unique_ptr<T, D>::pointer lazy_unique_ptr<T, D>::
  operator-> () const
  {
    return p_.operator-> ();
  }

  template <class T, class D>
  typename lazy_unique_ptr<T, D>::pointer lazy_unique_ptr<T, D>::
  get () const
  {
    return p_.get ();
  }

#ifdef ODB_CXX11_EXPLICIT_CONVERSION_OPERATOR
  template <class T, class D>
  lazy_unique_ptr<T, D>::
  operator bool() const
  {
    return p_ || i_;
  }
#endif

  template <class T, class D>
  typename lazy_unique_ptr<T, D>::pointer lazy_unique_ptr<T, D>::
  release ()
  {
    i_.reset ();
    return p_.release ();
  }

  template <class T, class D>
  void lazy_unique_ptr<T, D>::
  reset (pointer p)
  {
    p_.reset (p);
    i_.reset ();
  }

  template <class T, class D>
  void lazy_unique_ptr<T, D>::
  swap (lazy_unique_ptr& b)
  {
    p_.swap (b.p_);
    i_.swap (b.i_);
  }

  template <class T, class D>
  typename lazy_unique_ptr<T, D>::deleter_type& lazy_unique_ptr<T, D>::
  get_deleter ()
  {
    return p_.get_deleter ();
  }

  template <class T, class D>
  const typename lazy_unique_ptr<T, D>::deleter_type& lazy_unique_ptr<T, D>::
  get_deleter () const
  {
    return p_.get_deleter ();
  }

  template <class T, class D>
  template <class T1, class D1>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (std::unique_ptr<T1, D1>&& p)
      : p_ (std::move (p))
  {
  }

  template <class T, class D>
  template <class T1, class D1>
  inline lazy_unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  operator= (std::unique_ptr<T1, D1>&& p)
  {
    p_ = std::move (p);
    i_.reset ();
    return *this;
  }

  template <class T, class D>
  inline bool lazy_unique_ptr<T, D>::
  loaded () const
  {
    bool i (i_);
    return !p_ != i; // !p_ XOR i_
  }

  template <class T, class D>
  inline std::unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  load () const
  {
    if (!p_ && i_)
      p_ = std::unique_ptr<T, D> (i_.template load<T> (true)); // Reset id.

    return p_;
  }

  template <class T, class D>
  inline void lazy_unique_ptr<T, D>::
  unload () const
  {
    typedef typename object_traits<T>::object_type object_type;

    if (p_)
    {
      if (i_.database () != 0)
        i_.reset_id (object_traits<object_type>::id (*p_));

      p_.reset ();
    }
  }

  template <class T, class D>
  inline std::unique_ptr<T, D>& lazy_unique_ptr<T, D>::
  get_eager () const
  {
    return p_;
  }

  template <class T, class D>
  template <class DB, class ID>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, const ID& id): i_ (db, id) {}

  template <class T, class D>
  template <class DB>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, T* p)
      : p_ (p)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T, class D>
  template <class DB>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, T* p, const deleter_type& d)
      : p_ (p, d)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T, class D>
  template <class DB>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, T* p, deleter_type&& d)
      : p_ (p, std::move (d))
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T, class D>
  template <class DB, class T1, class D1>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, std::unique_ptr<T1, D1>&& p)
      : p_ (std::move (p))
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T, class D>
  template <class DB, class T1>
  inline lazy_unique_ptr<T, D>::
  lazy_unique_ptr (DB& db, std::auto_ptr<T1>&& p)
      : p_ (std::move (p))
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T, class D>
  template <class DB, class ID>
  inline void lazy_unique_ptr<T, D>::
  reset (DB& db, const ID& id)
  {
    p_.reset ();
    i_.reset (db, id);
  }

  template <class T, class D>
  template <class DB>
  inline void lazy_unique_ptr<T, D>::
  reset (DB& db, T* p)
  {
    p_.reset (p);

    if (p)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T, class D>
  template <class DB, class T1, class D1>
  inline void lazy_unique_ptr<T, D>::
  reset (DB& db, std::unique_ptr<T1, D1>&& p)
  {
    p_ = std::move (p);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T, class D>
  template <class DB, class T1>
  inline void lazy_unique_ptr<T, D>::
  reset (DB& db, std::auto_ptr<T1>&& p)
  {
    p_ = std::unique_ptr<T, D> (std::move (p));

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T, class D>
  template <class O>
  inline typename object_traits<O>::id_type lazy_unique_ptr<T, D>::
  object_id () const
  {
    typedef typename object_traits<T>::object_type object_type;

    return p_
      ? object_traits<object_type>::id (*p_)
      : i_.template object_id<O> ();
  }

  template <class T, class D>
  inline typename lazy_unique_ptr<T, D>::database_type& lazy_unique_ptr<T, D>::
  database () const
  {
    return *i_.database ();
  }

  template <class T>
  inline void
  swap (lazy_unique_ptr<T>& a, lazy_unique_ptr<T>& b)
  {
    a.swap (b);
  }

  template <class T1, class D1, class T2, class D2>
  inline bool
  operator== (const lazy_unique_ptr<T1, D1>& a,
              const lazy_unique_ptr<T2, D2>& b)
  {
    return a.equal (b);
  }

  template <class T1, class D1, class T2, class D2>
  inline bool
  operator!= (const lazy_unique_ptr<T1, D1>& a,
              const lazy_unique_ptr<T2, D2>& b)
  {
    return !a.equal (b);
  }

#ifdef ODB_CXX11_NULLPTR
  template <class T, class D>
  inline bool
  operator== (const lazy_unique_ptr<T, D>& a, std::nullptr_t)
  {
    return !a;
  }

  template <class T, class D>
  inline bool
  operator== (std::nullptr_t, const lazy_unique_ptr<T, D>& b)
  {
    return !b;
  }

  template <class T, class D>
  inline bool
  operator!= (const lazy_unique_ptr<T, D>& a, std::nullptr_t)
  {
    return a;
  }

  template <class T, class D>
  inline bool
  operator!= (std::nullptr_t, const lazy_unique_ptr<T, D>& b)
  {
    return b;
  }
#endif

  //
  // lazy_shared_ptr
  //

  template <class T>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr () {}

#ifdef ODB_CXX11_NULLPTR
  template <class T>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::nullptr_t) {}
#endif

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (Y* p): p_ (p) {}

  template <class T>
  template <class Y, class D>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (Y* p, D d): p_ (p, d) {}

  template <class T>
  template <class Y, class D, class A>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (Y* p, D d, A a): p_ (p, d, a) {}

#ifdef ODB_CXX11_NULLPTR
  template <class T>
  template <class D>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::nullptr_t p, D d): p_ (p, d) {}

  template <class T>
  template <class D, class A>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::nullptr_t p, D d, A a): p_ (p, d, a) {}
#endif

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const lazy_shared_ptr<Y>& r, T* p)
      // r.p_ has to be loaded
      : p_ (r.p_, p) {}

  template <class T>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const lazy_shared_ptr& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const lazy_shared_ptr<Y>& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (lazy_shared_ptr&& r)
      : p_ (std::move (r.p_)), i_ (std::move (r.i_)) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (lazy_shared_ptr<Y>&& r)
      : p_ (std::move (r.p_)), i_ (std::move (r.i_)) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const lazy_weak_ptr<Y>& r): i_ (r.i_)
  {
    // If the pointer has expired but can be re-loaded, then don't throw.
    //
    p_ = r.lock ();

    if (!p_ && !i_)
      throw std::bad_weak_ptr ();
  }

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::auto_ptr<Y>&& r): p_ (std::move (r)) {}

  template <class T>
  template <class Y, class D>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::unique_ptr<Y, D>&& r): p_ (std::move (r)) {}

  template <class T>
  inline lazy_shared_ptr<T>::
  ~lazy_shared_ptr () {}

  template <class T>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (const lazy_shared_ptr& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (const lazy_shared_ptr<Y>& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (lazy_shared_ptr&& r)
  {
    p_ = std::move (r.p_);
    i_ = std::move (r.i_);
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (lazy_shared_ptr<Y>&& r)
  {
    p_ = std::move (r.p_);
    i_ = std::move (r.i_);
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (std::auto_ptr<Y>&& r)
  {
    p_ = std::move (r);
    i_.reset ();
    return *this;
  }

  template <class T>
  template <class Y, class D>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (std::unique_ptr<Y, D>&& r)
  {
    p_ = std::move (r);
    i_.reset ();
    return *this;
  }

  template <class T>
  inline void lazy_shared_ptr<T>::
  swap (lazy_shared_ptr& b)
  {
    p_.swap (b.p_);
    i_.swap (b.i_);
  }

  template <class T>
  inline void lazy_shared_ptr<T>::
  reset ()
  {
    p_.reset ();
    i_.reset ();
  }

  template <class T>
  template <class Y>
  inline void lazy_shared_ptr<T>::
  reset (Y* p)
  {
    p_.reset (p);
    i_.reset ();
  }

  template <class T>
  template <class Y, class D>
  inline void lazy_shared_ptr<T>::
  reset (Y* p, D d)
  {
    p_.reset (p, d);
    i_.reset ();
  }

  template <class T>
  template <class Y, class D, class A>
  inline void lazy_shared_ptr<T>::
  reset (Y* p, D d, A a)
  {
    p_.reset (p, d, a);
    i_.reset ();
  }

  template <class T>
  inline T& lazy_shared_ptr<T>::
  operator* () const
  {
    return *p_;
  }

  template <class T>
  inline T* lazy_shared_ptr<T>::
  operator-> () const
  {
    return p_.operator-> ();
  }

  template <class T>
  inline T* lazy_shared_ptr<T>::
  get () const
  {
    return p_.get ();
  }

  template <class T>
  inline bool lazy_shared_ptr<T>::
  unique () const
  {
    return p_.unique ();
  }

  template <class T>
  inline long lazy_shared_ptr<T>::
  use_count () const
  {
    return p_.use_count ();
  }

#ifdef ODB_CXX11_EXPLICIT_CONVERSION_OPERATOR
  template <class T>
  inline lazy_shared_ptr<T>::
  operator bool () const
  {
    return p_ || i_;
  }
#endif

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const std::shared_ptr<Y>& r): p_ (r) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (std::shared_ptr<Y>&& r): p_ (std::move (r)) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (const std::weak_ptr<Y>& r): p_ (r) {}

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (const std::shared_ptr<Y>& r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
  operator= (std::shared_ptr<Y>&& r)
  {
    p_ = std::move (r);
    i_.reset ();
    return *this;
  }

  template <class T>
  inline bool lazy_shared_ptr<T>::
  loaded () const
  {
    bool i (i_);
    return !p_ != i; // !p_ XOR i_
  }

  template <class T>
  inline std::shared_ptr<T> lazy_shared_ptr<T>::
  load () const
  {
    if (!p_ && i_)
      p_ = i_.template load<T> (true); // Reset id.

    return p_;
  }

  template <class T>
  inline void lazy_shared_ptr<T>::
  unload () const
  {
    typedef typename object_traits<T>::object_type object_type;

    if (p_)
    {
      if (i_.database () != 0)
        i_.reset_id (object_traits<object_type>::id (*p_));

      p_.reset ();
    }
  }

  template <class T>
  inline std::shared_ptr<T> lazy_shared_ptr<T>::
  get_eager () const
  {
    return p_;
  }

  template <class T>
  template <class DB, class ID>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, const ID& id): i_ (db, id) {}

  template <class T>
  template <class DB, class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, Y* p)
      : p_ (p)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y, class D>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, Y* p, D d)
      : p_ (p, d)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y, class D, class A>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, Y* p, D d, A a)
      : p_ (p, d, a)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, std::auto_ptr<Y>&& r)
      : p_ (std::move (r))
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, const std::shared_ptr<Y>& r)
      : p_ (r)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, std::shared_ptr<Y>&& r)
      : p_ (std::move (r))
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_shared_ptr<T>::
  lazy_shared_ptr (DB& db, const std::weak_ptr<Y>& r)
      : p_ (r)
  {
    if (p_)
      i_.reset_db (db);
  }

  template <class T>
  template <class DB, class ID>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, const ID& id)
  {
    p_.reset ();
    i_.reset (db, id);
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, Y* p)
  {
    p_.reset (p);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y, class D>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, Y* p, D d)
  {
    p_.reset (p, d);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y, class D, class A>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, Y* p, D d, A a)
  {
    p_.reset (p, d, a);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, std::auto_ptr<Y>&& r)
  {
    p_ = std::move (r);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, const std::shared_ptr<Y>& r)
  {
    p_ = r;

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_shared_ptr<T>::
  reset (DB& db, std::shared_ptr<Y>&& r)
  {
    p_ = std::move (r);

    if (p_)
      i_.reset_db (db);
    else
      i_.reset ();
  }

  template <class T>
  template <class O>
  inline typename object_traits<O>::id_type lazy_shared_ptr<T>::
  object_id () const
  {
    typedef typename object_traits<T>::object_type object_type;

    return p_
      ? object_traits<object_type>::id (*p_)
      : i_.template object_id<O> ();
  }

  template <class T>
  inline typename lazy_shared_ptr<T>::database_type& lazy_shared_ptr<T>::
  database () const
  {
    return *i_.database ();
  }

  template <class T, class Y>
  inline bool
  operator== (const lazy_shared_ptr<T>& a, const lazy_shared_ptr<Y>& b)
  {
    return a.equal (b);
  }

  template <class T, class Y>
  inline bool
  operator!= (const lazy_shared_ptr<T>& a, const lazy_shared_ptr<Y>& b)
  {
    return !a.equal (b);
  }

#ifdef ODB_CXX11_NULLPTR
  template <class T>
  inline bool
  operator== (const lazy_shared_ptr<T>& p, std::nullptr_t)
  {
    return !p;
  }

  template <class T>
  inline bool
  operator== (std::nullptr_t, const lazy_shared_ptr<T>& p)
  {
    return !p;
  }

  template <class T>
  inline bool
  operator!= (const lazy_shared_ptr<T>& p, std::nullptr_t)
  {
    return p;
  }

  template <class T>
  inline bool
  operator!= (std::nullptr_t, const lazy_shared_ptr<T>& p)
  {
    return p;
  }
#endif

  template <class T>
  inline void
  swap (lazy_shared_ptr<T>& a, lazy_shared_ptr<T>& b)
  {
    a.swap (b);
  }

  template <class D, class T>
  inline D*
  get_deleter (const lazy_shared_ptr<T>& p)
  {
    return std::get_deleter<D> (p.p_);
  }

  //
  // lazy_weak_ptr
  //

  template <class T>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr () {}

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (const lazy_shared_ptr<Y>& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (const lazy_weak_ptr& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (const lazy_weak_ptr<Y>& r): p_ (r.p_), i_ (r.i_) {}

  template <class T>
  inline lazy_weak_ptr<T>::
  ~lazy_weak_ptr () {}

  template <class T>
  inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
  operator= (const lazy_weak_ptr& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
  operator= (const lazy_weak_ptr<Y>& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
  operator= (const lazy_shared_ptr<Y>& r)
  {
    p_ = r.p_;
    i_ = r.i_;
    return *this;
  }

  template <class T>
  inline void lazy_weak_ptr<T>::
  swap (lazy_weak_ptr<T>& r)
  {
    p_.swap (r.p_);
    i_.swap (r.i_);
  }

  template <class T>
  inline void lazy_weak_ptr<T>::
  reset ()
  {
    p_.reset ();
    i_.reset ();
  }

  template <class T>
  inline long lazy_weak_ptr<T>::
  use_count () const
  {
    return p_.use_count ();
  }

  template <class T>
  inline bool lazy_weak_ptr<T>::
  expired () const
  {
    return p_.expired ();
  }

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (const std::weak_ptr<Y>& r): p_ (r) {}

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (const std::shared_ptr<Y>& r): p_ (r) {}

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
  operator= (const std::weak_ptr<Y>& r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  template <class Y>
  inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
  operator= (const std::shared_ptr<Y>& r)
  {
    p_ = r;
    i_.reset ();
    return *this;
  }

  template <class T>
  inline bool lazy_weak_ptr<T>::
  loaded () const
  {
    bool i (i_);
    return expired () != i; // expired () XOR i_
  }

  template <class T>
  inline std::shared_ptr<T> lazy_weak_ptr<T>::
  load () const
  {
    std::shared_ptr<T> r (p_.lock ());

    if (!r && i_)
    {
      r = i_.template load<T> (false); // Keep id.
      p_ = r;
    }

    return r;
  }

  template <class T>
  inline void lazy_weak_ptr<T>::
  unload () const
  {
    // With weak pointer we always keep i_ up to date.
    //
    p_.reset ();
  }

  template <class T>
  inline std::weak_ptr<T> lazy_weak_ptr<T>::
  get_eager () const
  {
    return p_;
  }

  template <class T>
  template <class DB, class ID>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (DB& db, const ID& id): i_ (db, id) {}

  template <class T>
  template <class DB, class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (DB& db, const std::shared_ptr<Y>& r)
      : p_ (r)
  {
    typedef typename object_traits<T>::object_type object_type;

    if (r)
      i_.reset (db, object_traits<object_type>::id (*r));
  }

  template <class T>
  template <class DB, class Y>
  inline lazy_weak_ptr<T>::
  lazy_weak_ptr (DB& db, const std::weak_ptr<Y>& r)
      : p_ (r)
  {
    typedef typename object_traits<T>::object_type object_type;

    std::shared_ptr<T> sp (p_.lock ());

    if (sp)
      i_.reset (db, object_traits<object_type>::id (*sp));
  }

  template <class T>
  template <class DB, class ID>
  inline void lazy_weak_ptr<T>::
  reset (DB& db, const ID& id)
  {
    p_.reset ();
    i_.reset (db, id);
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_weak_ptr<T>::
  reset (DB& db, const std::shared_ptr<Y>& r)
  {
    typedef typename object_traits<T>::object_type object_type;

    p_ = r;

    if (r)
      i_.reset (db, object_traits<object_type>::id (*r));
    else
      i_.reset ();
  }

  template <class T>
  template <class DB, class Y>
  inline void lazy_weak_ptr<T>::
  reset (DB& db, const std::weak_ptr<Y>& r)
  {
    typedef typename object_traits<T>::object_type object_type;

    p_ = r;
    std::shared_ptr<T> sp (p_.lock ());

    if (sp)
      i_.reset (db, object_traits<object_type>::id (*sp));
    else
      i_.reset ();
  }

  template <class T>
  template <class O>
  inline typename object_traits<O>::id_type lazy_weak_ptr<T>::
  object_id () const
  {
    typedef typename object_traits<T>::object_type object_type;

    std::shared_ptr<T> sp (p_.lock ());
    return sp
      ? object_traits<object_type>::id (*sp)
      : i_.template object_id<O> ();
  }

  template <class T>
  inline typename lazy_weak_ptr<T>::database_type& lazy_weak_ptr<T>::
  database () const
  {
    return *i_.database ();
  }

  template <class T>
  inline void
  swap (lazy_weak_ptr<T>& a, lazy_weak_ptr<T>& b)
  {
    a.swap (b);
  }

#endif // ODB_CXX11

}
