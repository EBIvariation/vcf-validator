// file      : odb/tr1/lazy-ptr.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TR1_LAZY_PTR_HXX
#define ODB_TR1_LAZY_PTR_HXX

#include <odb/pre.hxx>

//
// This header assumes that the necessary TR1 header has already
// been included.
//

#include <memory> // std::auto_ptr

#include <odb/forward.hxx> // odb::database
#include <odb/traits.hxx>
#include <odb/lazy-ptr-impl.hxx>
#include <odb/details/config.hxx> // ODB_CXX11

namespace odb
{
  namespace tr1
  {
    template <class T>
    class lazy_weak_ptr;

    //
    //
    template <class T>
    class lazy_shared_ptr
    {
      // The standard shared_ptr interface.
      //
    public:
      typedef T element_type;

      lazy_shared_ptr ();
      template <class Y> explicit lazy_shared_ptr (Y*);
      template <class Y, class D> lazy_shared_ptr (Y*, D);

      lazy_shared_ptr (const lazy_shared_ptr&);
      template <class Y> lazy_shared_ptr (const lazy_shared_ptr<Y>&);
      template <class Y> explicit lazy_shared_ptr (const lazy_weak_ptr<Y>&);
      template <class Y> explicit lazy_shared_ptr (std::auto_ptr<Y>&);

      ~lazy_shared_ptr ();

      lazy_shared_ptr& operator= (const lazy_shared_ptr&);
      template <class Y> lazy_shared_ptr& operator= (const lazy_shared_ptr<Y>&);
      template <class Y> lazy_shared_ptr& operator= (std::auto_ptr<Y>&);

      void swap (lazy_shared_ptr&);
      void reset ();
      template <class Y> void reset (Y*);
      template <class Y, class D> void reset (Y*, D);

      T& operator* () const;
      T* operator-> () const;
      T* get () const;

      bool unique () const;
      long use_count () const;

      typedef std::tr1::shared_ptr<T> lazy_shared_ptr::*unspecified_bool_type;
      operator unspecified_bool_type () const
      {
        return (p_ || i_) ? &lazy_shared_ptr::p_ : 0;
      }

      // Initialization/assignment from shared_ptr and weak_ptr.
      //
    public:
      template <class Y> lazy_shared_ptr (const std::tr1::shared_ptr<Y>&);
      template <class Y> explicit lazy_shared_ptr (const std::tr1::weak_ptr<Y>&);

      template <class Y> lazy_shared_ptr& operator= (const std::tr1::shared_ptr<Y>&);

      // Lazy loading interface.
      //
    public:
      typedef odb::database database_type;

      //  NULL      loaded()
      //
      //  true       true      NULL pointer to transient object
      //  false      true      valid pointer to persistent object
      //  true       false     unloaded pointer to persistent object
      //  false      false     valid pointer to transient object
      //
      bool loaded () const;

      std::tr1::shared_ptr<T> load () const;

      // Unload the pointer. For transient objects this function is
      // equivalent to reset().
      //
      void unload () const;

      // Get the underlying eager pointer. If this is an unloaded pointer
      // to a persistent object, then the returned pointer will be NULL.
      //
      std::tr1::shared_ptr<T> get_eager () const;

      template <class DB, class ID> lazy_shared_ptr (DB&, const ID&);
      template <class DB, class Y> lazy_shared_ptr (DB&, Y*);
      template <class DB, class Y, class D> lazy_shared_ptr (DB&, Y*, D);
      template <class DB, class Y> lazy_shared_ptr (DB&, std::auto_ptr<Y>&);
      template <class DB, class Y> lazy_shared_ptr (DB&, const std::tr1::shared_ptr<Y>&);
      template <class DB, class Y> lazy_shared_ptr (DB&, const std::tr1::weak_ptr<Y>&);

      template <class DB, class ID> void reset (DB&, const ID&);
      template <class DB, class Y> void reset (DB&, Y*);
      template <class DB, class Y, class D> void reset (DB&, Y*, D);
      template <class DB, class Y> void reset (DB&, std::auto_ptr<Y>&);
      template <class DB, class Y> void reset (DB&, const std::tr1::shared_ptr<Y>&);

#ifdef ODB_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGUMENT
      template <class O = T>
#else
      template <class O /*= T*/>
#endif
      typename object_traits<O>::id_type object_id () const;

      database_type& database () const;

      // Helpers.
      //
    public:
      template <class Y> bool equal (const lazy_shared_ptr<Y>&) const;

    private:
      template <class Y> friend class lazy_shared_ptr;
      template <class Y> friend class lazy_weak_ptr;

      mutable std::tr1::shared_ptr<T> p_;
      mutable lazy_ptr_impl<T> i_;
    };

    // operator< and operator<< are not provided.
    //
    template<class T, class Y>
    bool operator== (const lazy_shared_ptr<T>&, const lazy_shared_ptr<Y>&);

    template<class T, class Y>
    bool operator!= (const lazy_shared_ptr<T>&, const lazy_shared_ptr<Y>&);

    template<class T> void swap (lazy_shared_ptr<T>&, lazy_shared_ptr<T>&);

    template<class D, class T>
    D* get_deleter (const lazy_shared_ptr<T>&);

    //
    //
    template <class T>
    class lazy_weak_ptr
    {
      // The standard weak_ptr interface.
      //
    public:
      typedef T element_type;

      lazy_weak_ptr ();
      template <class Y> lazy_weak_ptr (const lazy_shared_ptr<Y>&);
      lazy_weak_ptr (const lazy_weak_ptr&);
      template <class Y> lazy_weak_ptr (const lazy_weak_ptr<Y>&);

      ~lazy_weak_ptr ();

      lazy_weak_ptr& operator= (const lazy_weak_ptr&);
      template <class Y> lazy_weak_ptr& operator= (const lazy_weak_ptr<Y>&);
      template <class Y> lazy_weak_ptr& operator= (const lazy_shared_ptr<Y>&);

      void swap (lazy_weak_ptr<T>&);
      void reset ();

      long use_count () const;
      bool expired () const;

      lazy_shared_ptr<T> lock () const;

      // Initialization/assignment from shared_ptr and weak_ptr.
      //
    public:
      template <class Y> lazy_weak_ptr (const std::tr1::weak_ptr<Y>&);
      template <class Y> lazy_weak_ptr (const std::tr1::shared_ptr<Y>&);

      template <class Y> lazy_weak_ptr& operator= (const std::tr1::weak_ptr<Y>&);
      template <class Y> lazy_weak_ptr& operator= (const std::tr1::shared_ptr<Y>&);

      // Lazy loading interface.
      //
    public:
      typedef odb::database database_type;

      // expired()  loaded()
      //
      //  true       true      expired pointer to transient object
      //  false      true      valid pointer to persistent object
      //  true       false     expired pointer to persistent object
      //  false      false     valid pointer to transient object
      //
      bool loaded () const;

      // Performs both lock and load.
      //
      std::tr1::shared_ptr<T> load () const;

      // Unload the pointer. For transient objects this function is
      // equivalent to reset().
      //
      void unload () const;

      // Get the underlying eager pointer. If this is an unloaded pointer
      // to a persistent object, then the returned pointer will be NULL.
      //
      std::tr1::weak_ptr<T> get_eager () const;

      template <class DB, class ID> lazy_weak_ptr (DB&, const ID&);
      template <class DB, class Y> lazy_weak_ptr (DB&, const std::tr1::shared_ptr<Y>&);
      template <class DB, class Y> lazy_weak_ptr (DB&, const std::tr1::weak_ptr<Y>&);

      template <class DB, class ID> void reset (DB&, const ID&);
      template <class DB, class Y> void reset (DB&, const std::tr1::shared_ptr<Y>&);
      template <class DB, class Y> void reset (DB&, const std::tr1::weak_ptr<Y>&);

      // The object_id() function can only be called when the object is
      // persistent, or: expired() XOR loaded() (can use != for XOR).
      //
#ifdef ODB_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGUMENT
      template <class O = T>
#else
      template <class O /* = T */>
#endif
      typename object_traits<O>::id_type object_id () const;

      database_type& database () const;

    private:
      template <class Y> friend class lazy_shared_ptr;
      template <class Y> friend class lazy_weak_ptr;

      mutable std::tr1::weak_ptr<T> p_;
      mutable lazy_ptr_impl<T> i_;
    };

    // operator< is not provided.
    //
    template<class T> void swap (lazy_weak_ptr<T>&, lazy_weak_ptr<T>&);
  }
}

#include <odb/tr1/lazy-ptr.ixx>
#include <odb/tr1/lazy-ptr.txx>

#include <odb/tr1/lazy-pointer-traits.hxx>

#include <odb/post.hxx>

#endif // ODB_TR1_LAZY_PTR_HXX
