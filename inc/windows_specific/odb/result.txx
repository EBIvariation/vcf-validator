// file      : odb/result.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cassert>

namespace odb
{
  template <typename T>
  typename object_traits<T>::pointer_type result<T>::
  one ()
  {
    typedef typename object_traits<T>::pointer_type pointer_type;

    iterator i (begin ());

    if (i != end ())
    {
      pointer_type o (i.load ());
      assert (++i == end ()); // More than one element in query_one() result.
      return o;
    }

    return pointer_type ();
  }

  template <typename T>
  bool result<T>::
  one (T& o)
  {
    iterator i (begin ());

    if (i != end ())
    {
      i.load (o);
      assert (++i == end ()); // More than one element in query_one() result.
      return true;
    }

    return false;
  }

  template <typename T>
  void result<T>::
  value (T& o)
  {
    iterator i (begin ());
    assert (i != end ()); // Zero elements in query_value() result.
    i.load (o);
    assert (++i == end ()); // More than one element in query_value() result.
  }
}
