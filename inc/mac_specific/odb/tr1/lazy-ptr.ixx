// file      : odb/tr1/lazy-ptr.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace tr1
  {
    //
    // lazy_shared_ptr
    //

    template <class T>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr () {}

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (Y* p): p_ (p) {}

    template <class T>
    template <class Y, class D>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (Y* p, D d): p_ (p, d) {}

    template <class T>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (const lazy_shared_ptr& r): p_ (r.p_), i_ (r.i_) {}

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (const lazy_shared_ptr<Y>& r): p_ (r.p_), i_ (r.i_) {}

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (const lazy_weak_ptr<Y>& r): i_ (r.i_)
    {
      // If the pointer has expired but can be re-loaded, then don't throw.
      //
      p_ = r.lock ();

      if (!p_ && !i_)
        throw std::tr1::bad_weak_ptr ();
    }

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (std::auto_ptr<Y>& r): p_ (r) {}

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
    template <class Y>
    inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
    operator= (std::auto_ptr<Y>& r)
    {
      p_ = r;
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

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (const std::tr1::shared_ptr<Y>& r): p_ (r) {}

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (const std::tr1::weak_ptr<Y>& r): p_ (r) {}

    template <class T>
    template <class Y>
    inline lazy_shared_ptr<T>& lazy_shared_ptr<T>::
    operator= (const std::tr1::shared_ptr<Y>& r)
    {
      p_ = r;
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
    inline std::tr1::shared_ptr<T> lazy_shared_ptr<T>::
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
    inline std::tr1::shared_ptr<T> lazy_shared_ptr<T>::
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
    template <class DB, class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (DB& db, std::auto_ptr<Y>& r)
        : p_ (r)
    {
      if (p_)
        i_.reset_db (db);
    }

    template <class T>
    template <class DB, class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (DB& db, const std::tr1::shared_ptr<Y>& r)
        : p_ (r)
    {
      if (p_)
        i_.reset_db (db);
    }

    template <class T>
    template <class DB, class Y>
    inline lazy_shared_ptr<T>::
    lazy_shared_ptr (DB& db, const std::tr1::weak_ptr<Y>& r)
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
    template <class DB, class Y>
    inline void lazy_shared_ptr<T>::
    reset (DB& db, std::auto_ptr<Y>& r)
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
    reset (DB& db, const std::tr1::shared_ptr<Y>& r)
    {
      p_ = r;

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

    template<class T, class Y>
    inline bool
    operator== (const lazy_shared_ptr<T>& a, const lazy_shared_ptr<Y>& b)
    {
      return a.equal (b);
    }

    template<class T, class Y>
    inline bool
    operator!= (const lazy_shared_ptr<T>& a, const lazy_shared_ptr<Y>& b)
    {
      return !a.equal (b);
    }

    template<class T>
    inline void
    swap (lazy_shared_ptr<T>& a, lazy_shared_ptr<T>& b)
    {
      a.swap (b);
    }

    template<class D, class T>
    inline D*
    get_deleter (const lazy_shared_ptr<T>& p)
    {
      return std::tr1::get_deleter<D> (p.p_);
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
    lazy_weak_ptr (const std::tr1::weak_ptr<Y>& r): p_ (r) {}

    template <class T>
    template <class Y>
    inline lazy_weak_ptr<T>::
    lazy_weak_ptr (const std::tr1::shared_ptr<Y>& r): p_ (r) {}

    template <class T>
    template <class Y>
    inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
    operator= (const std::tr1::weak_ptr<Y>& r)
    {
      p_ = r;
      i_.reset ();
      return *this;
    }

    template <class T>
    template <class Y>
    inline lazy_weak_ptr<T>& lazy_weak_ptr<T>::
    operator= (const std::tr1::shared_ptr<Y>& r)
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
    inline std::tr1::shared_ptr<T> lazy_weak_ptr<T>::
    load () const
    {
      std::tr1::shared_ptr<T> r (p_.lock ());

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
    inline std::tr1::weak_ptr<T> lazy_weak_ptr<T>::
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
    lazy_weak_ptr (DB& db, const std::tr1::shared_ptr<Y>& r)
        : p_ (r)
    {
      typedef typename object_traits<T>::object_type object_type;

      if (r)
        i_.reset (db, object_traits<object_type>::id (*r));
    }

    template <class T>
    template <class DB, class Y>
    inline lazy_weak_ptr<T>::
    lazy_weak_ptr (DB& db, const std::tr1::weak_ptr<Y>& r)
        : p_ (r)
    {
      typedef typename object_traits<T>::object_type object_type;

      std::tr1::shared_ptr<T> sp (p_.lock ());

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
    reset (DB& db, const std::tr1::shared_ptr<Y>& r)
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
    reset (DB& db, const std::tr1::weak_ptr<Y>& r)
    {
      typedef typename object_traits<T>::object_type object_type;

      p_ = r;
      std::tr1::shared_ptr<T> sp (p_.lock ());

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

      std::tr1::shared_ptr<T> sp (p_.lock ());
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

    template<class T>
    inline void
    swap (lazy_weak_ptr<T>& a, lazy_weak_ptr<T>& b)
    {
      a.swap (b);
    }
  }
}
