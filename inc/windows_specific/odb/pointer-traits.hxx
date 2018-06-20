// file      : odb/pointer-traits.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_POINTER_TRAITS_HXX
#define ODB_POINTER_TRAITS_HXX

#include <odb/pre.hxx>

#include <new>     // operators new/delete
#include <memory>  // std::auto_ptr, std::unique_ptr, std::shared_ptr/weak_ptr
#include <cstddef> // std::size_t

#include <odb/details/config.hxx>            // ODB_CXX11
#include <odb/details/meta/remove-const.hxx>

namespace odb
{
  enum pointer_kind
  {
    pk_raw,    // Raw pointer or equivalent (i.e., unmanaged).
    pk_unique, // Smart pointer that doesn't support sharing.
    pk_shared, // Smart pointer that supports sharing.
    pk_weak    // Weak counterpart for shared pointer.
  };

  template <typename P>
  class pointer_traits;

  //
  // Standard pointer guards.
  //

  // Raw pointer guard.
  //
  template <typename P>
  class raw_ptr_guard
  {
  public:
    ~raw_ptr_guard () {delete p_;}
    raw_ptr_guard (): p_ (0) {}

    explicit
    raw_ptr_guard (P p): p_ (p) {}

    void
    release () {p_ = 0;}

    void
    reset (P p = 0) {delete p_; p_ = p;}

  private:
    P p_;
  };

  // No-op pointer guard for smart pointers.
  //
  template <typename P>
  class smart_ptr_guard
  {
  public:
    smart_ptr_guard () {}

    explicit
    smart_ptr_guard (const P&) {}

    void
    release () {}

    void
    reset () {}

    void
    reset (const P&) {}
  };

  // Specialization for raw pointers.
  //
  template <typename T>
  class pointer_traits<T*>
  {
  public:
    static const pointer_kind kind = pk_raw;
    static const bool lazy = false;

    typedef T element_type;
    typedef T* pointer_type;
    typedef const T* const_pointer_type;
    typedef typename odb::details::meta::remove_const<T>::result*
    unrestricted_pointer_type;
    typedef raw_ptr_guard<pointer_type> guard;

    // Return raw pointer to the pointed-to element, including NULL.
    //
    static element_type*
    get_ptr (pointer_type p)
    {
      return p;
    }

    // Return reference to the pointed-to element.
    //
    static element_type&
    get_ref (pointer_type p)
    {
      return *p;
    }

    // Return true if the pointer is NULL.
    //
    static bool
    null_ptr (pointer_type p)
    {
      return p == 0;
    }

    // Casts.
    //
    static unrestricted_pointer_type
    const_pointer_cast (pointer_type p)
    {
      return const_cast<unrestricted_pointer_type> (p);
    }

    template <typename T1>
    static T1*
    static_pointer_cast (pointer_type p)
    {
      return static_cast<T1*> (p);
    }

    template <typename T1>
    static T1*
    dynamic_pointer_cast (pointer_type p)
    {
      return dynamic_cast<T1*> (p);
    }

  public:
    // Allocate memory for an element that will be managed by this
    // pointer.
    //
    static void*
    allocate (std::size_t n)
    {
      return operator new (n);
    }

    // Free memory allocated for an element. This functions is only
    // called if the constructor of the element being created fails.
    // Otherwise, the pointer (or guard) is used to delete the object
    // and free the memory. This behavior is identical to the one
    // used by operator delete overloading.
    //
    static void
    free (void* p)
    {
      operator delete (p);
    }
  };

  // Specialization for std::auto_ptr.
  //
  template <typename T>
  class pointer_traits< std::auto_ptr<T> >
  {
  public:
    static const pointer_kind kind = pk_unique;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::auto_ptr<element_type> pointer_type;
    typedef std::auto_ptr<const element_type> const_pointer_type;
    typedef smart_ptr_guard<pointer_type> guard;

    static element_type*
    get_ptr (const pointer_type& p)
    {
      return p.get ();
    }

    static element_type&
    get_ref (const pointer_type& p)
    {
      return *p;
    }

    static bool
    null_ptr (const pointer_type& p)
    {
      return p.get () == 0;
    }

    // const_pointer_cast() is not provided.
    //

    // Note: transfers ownership.
    //
    template <typename T1>
    static std::auto_ptr<T1>
    static_pointer_cast (pointer_type& p)
    {
      return std::auto_ptr<T1> (static_cast<T1*> (p.release ()));
    }

    // Note: transfers ownership if successful.
    //
    template <typename T1>
    static std::auto_ptr<T1>
    dynamic_pointer_cast (pointer_type& p)
    {
      T1* p1 (dynamic_cast<T1*> (p.get ()));

      if (p1 != 0)
        p.release ();

      return std::auto_ptr<T1> (p1);
    }

  public:
    static void*
    allocate (std::size_t n)
    {
      return operator new (n);
    }

    static void
    free (void* p)
    {
      operator delete (p);
    }
  };

#ifdef ODB_CXX11

  // Specialization for C++11 std::unique_ptr.
  //
  template <typename T, typename D>
  class pointer_traits<std::unique_ptr<T, D>>
  {
  public:
    static const pointer_kind kind = pk_unique;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::unique_ptr<element_type, D> pointer_type;
    typedef std::unique_ptr<const element_type, D> const_pointer_type;
    typedef smart_ptr_guard<pointer_type> guard;

    static element_type*
    get_ptr (const pointer_type& p)
    {
      return p.get ();
    }

    static element_type&
    get_ref (const pointer_type& p)
    {
      return *p;
    }

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    // const_pointer_cast() is not provided.
    //

    // Note: transfers ownership.
    //
    template <typename T1>
    static std::unique_ptr<T1>
    static_pointer_cast (pointer_type& p)
    {
      return std::unique_ptr<T1> (static_cast<T1*> (p.release ()));
    }

    // Note: transfers ownership if successful.
    //
    template <typename T1>
    static std::unique_ptr<T1>
    dynamic_pointer_cast (pointer_type& p)
    {
      T1* p1 (dynamic_cast<T1*> (p.get ()));

      if (p1 != 0)
        p.release ();

      return std::unique_ptr<T1> (p1);
    }

  public:
    static void*
    allocate (std::size_t n)
    {
      return operator new (n);
    }

    static void
    free (void* p)
    {
      operator delete (p);
    }
  };

  // Specialization for C++11 std::shared_ptr.
  //
  template <typename T>
  class pointer_traits<std::shared_ptr<T>>
  {
  public:
    static const pointer_kind kind = pk_shared;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::shared_ptr<element_type> pointer_type;
    typedef std::shared_ptr<const element_type> const_pointer_type;
    typedef typename odb::details::meta::remove_const<element_type>::result
    unrestricted_element_type;
    typedef std::shared_ptr<unrestricted_element_type>
    unrestricted_pointer_type;
    typedef smart_ptr_guard<pointer_type> guard;

    static element_type*
    get_ptr (const pointer_type& p)
    {
      return p.get ();
    }

    static element_type&
    get_ref (const pointer_type& p)
    {
      return *p;
    }

    static bool
    null_ptr (const pointer_type& p)
    {
      return !p;
    }

    static unrestricted_pointer_type
    const_pointer_cast (const pointer_type& p)
    {
      return std::const_pointer_cast<unrestricted_element_type> (p);
    }

    template <typename T1>
    static std::shared_ptr<T1>
    static_pointer_cast (const pointer_type& p)
    {
      return std::static_pointer_cast<T1> (p);
    }

    template <typename T1>
    static std::shared_ptr<T1>
    dynamic_pointer_cast (const pointer_type& p)
    {
      return std::dynamic_pointer_cast<T1> (p);
    }

  public:
    static void*
    allocate (std::size_t n)
    {
      return operator new (n);
    }

    static void
    free (void* p)
    {
      operator delete (p);
    }
  };

  // Specialization for C++11 std::weak_ptr.
  //
  template <typename T>
  class pointer_traits<std::weak_ptr<T>>
  {
  public:
    static const pointer_kind kind = pk_weak;
    static const bool lazy = false;

    typedef T element_type;
    typedef std::weak_ptr<element_type> pointer_type;
    typedef std::shared_ptr<element_type> strong_pointer_type;

    static strong_pointer_type
    lock (const pointer_type& p)
    {
      return p.lock ();
    }
  };

#endif // ODB_CXX11

}

#include <odb/post.hxx>

#endif // ODB_POINTER_TRAITS_HXX
