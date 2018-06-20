// file      : odb/lazy-ptr.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  //
  // lazy_ptr
  //

  template <class T>
  template <class Y>
  bool lazy_ptr<T>::
  equal (const lazy_ptr<Y>& r) const
  {
    bool t1 ((p_ == 0) == loaded ());
    bool t2 ((r.p_ == 0) == r.loaded ());

    // If both are transient, then compare the underlying pointers.
    //
    if (t1 && t2)
      return p_ == r.p_;

    // If one is transient and the other is persistent, then compare
    // the underlying pointers but only if they are non NULL. Note
    // that an unloaded persistent object is always unequal to a
    // transient object.
    //
    if (t1 || t2)
      return p_ == r.p_ && p_ != 0;

    // If both objects are persistent, then we compare databases and
    // object ids.
    //
    typedef typename object_traits<T>::object_type object_type1;
    typedef typename object_traits<Y>::object_type object_type2;

    return i_.database () == r.i_.database () &&
      object_id<object_type1> () == r.template object_id<object_type2> ();
  }

#ifdef ODB_CXX11

  //
  // lazy_unique_ptr
  //

  template <class T, class D>
  template <class T1, class D1>
  bool lazy_unique_ptr<T, D>::
  equal (const lazy_unique_ptr<T1, D1>& r) const
  {
    bool t1 (!p_ == loaded ());
    bool t2 (!r.p_ == r.loaded ());

    // If both are transient, then compare the underlying pointers.
    //
    if (t1 && t2)
      return p_ == r.p_;

    // If one is transient and the other is persistent, then compare
    // the underlying pointers but only if they are non NULL. Note
    // that an unloaded persistent object is always unequal to a
    // transient object.
    //
    if (t1 || t2)
      return p_ == r.p_ && p_;

    // If both objects are persistent, then we compare databases and
    // object ids.
    //
    typedef typename object_traits<T>::object_type object_type1;
    typedef typename object_traits<T1>::object_type object_type2;

    return i_.database () == r.i_.database () &&
      object_id<object_type1> () == r.template object_id<object_type2> ();
  }

  //
  // lazy_shared_ptr
  //

  template <class T>
  template <class Y>
  bool lazy_shared_ptr<T>::
  equal (const lazy_shared_ptr<Y>& r) const
  {
    bool t1 (!p_ == loaded ());
    bool t2 (!r.p_ == r.loaded ());

    // If both are transient, then compare the underlying pointers.
    //
    if (t1 && t2)
      return p_ == r.p_;

    // If one is transient and the other is persistent, then compare
    // the underlying pointers but only if they are non NULL. Note
    // that an unloaded persistent object is always unequal to a
    // transient object.
    //
    if (t1 || t2)
      return p_ == r.p_ && p_;

    // If both objects are persistent, then we compare databases and
    // object ids.
    //
    typedef typename object_traits<T>::object_type object_type1;
    typedef typename object_traits<Y>::object_type object_type2;

    return i_.database () == r.i_.database () &&
      object_id<object_type1> () == r.template object_id<object_type2> ();
  }

  //
  // lazy_weak_ptr
  //

  template <class T>
  lazy_shared_ptr<T> lazy_weak_ptr<T>::
  lock () const
  {
    std::shared_ptr<T> sp (p_.lock ());

    if (sp)
    {
      if (database_type* db = i_.database ())
        return lazy_shared_ptr<T> (*db, sp);
      else
        return lazy_shared_ptr<T> (sp);
    }
    else
    {
      if (i_)
        return lazy_shared_ptr<T> (
          *i_.database (), i_.template object_id<T> ());
      else
        return lazy_shared_ptr<T> ();
    }
  }

#endif // ODB_CXX11

}
