// file      : odb/sqlite/simple-object-statements.ixx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace sqlite
  {
    //
    // auto_unlock
    //
    inline object_statements_base::auto_unlock::
    auto_unlock (object_statements_base& s)
        : s_ (s)
    {
      s_.unlock ();
    }

    inline object_statements_base::auto_unlock::
    ~auto_unlock ()
    {
      s_.lock ();
    }

    //
    // auto_lock
    //
    template <typename T>
    inline object_statements<T>::auto_lock::
    auto_lock (object_statements& s)
        : s_ (s)
    {
      if (!s_.locked ())
      {
        s_.lock ();
        locked_ = true;
      }
      else
        locked_ = false;
    }

    template <typename T>
    inline object_statements<T>::auto_lock::
    ~auto_lock ()
    {
      if (locked_)
      {
        s_.unlock ();
        s_.clear_delayed ();
      }
    }

    template <typename T>
    inline bool object_statements<T>::auto_lock::
    locked () const
    {
      return locked_;
    }

    template <typename T>
    inline void object_statements<T>::auto_lock::
    unlock ()
    {
      assert (locked_);
      s_.unlock ();
      locked_ = false;
    }
  }
}
