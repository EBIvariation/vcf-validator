// file      : odb/lazy-ptr-impl.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_LAZY_PTR_IMPL_HXX
#define ODB_LAZY_PTR_IMPL_HXX

#include <odb/pre.hxx>

#include <utility> // std::move

#include <odb/forward.hxx> // odb::database
#include <odb/traits.hxx>

#include <odb/details/config.hxx> // ODB_CXX11
#include <odb/details/export.hxx>

namespace odb
{
  struct LIBODB_EXPORT lazy_ptr_impl_ref
  {
    void* id_;
    database* db_;
    void* loader_;
    void (*free_) (void*);
    void* (*copy_) (const void*);
  };

  class LIBODB_EXPORT lazy_ptr_base
  {
  public:
    typedef odb::database database_type;

    ~lazy_ptr_base ();
    lazy_ptr_base ();
    lazy_ptr_base (const lazy_ptr_base&);
    lazy_ptr_base (const lazy_ptr_impl_ref&);

    lazy_ptr_base&
    operator= (const lazy_ptr_base&);

    lazy_ptr_base&
    operator= (const lazy_ptr_impl_ref&);

    // C++11 support.
    //
  public:
#ifdef ODB_CXX11
    lazy_ptr_base (lazy_ptr_base&&);

    lazy_ptr_base&
    operator= (lazy_ptr_base&&);
#endif

  public:
    // Reset both the id and database.
    //
    void
    reset ();

    // Reset the id.
    //
    void
    reset_id ();

    void
    swap (lazy_ptr_base&);

    database_type*
    database () const;

    typedef void* lazy_ptr_base::*unspecified_bool_type;
    operator unspecified_bool_type () const
    {
      return db_ != 0 ? &lazy_ptr_base::id_ : 0;
    }

    operator lazy_ptr_impl_ref ();

  protected:
    typedef void (*free_func) (void*);
    typedef void* (*copy_func) (const void*);

    // Makes a copy of id.
    //
    void
    reset_ (database_type*,
            void* loader,
            const void* id,
            free_func, copy_func);

    template <typename T>
    static void
    free (void*);

    template <typename T>
    static void*
    copy (const void*);

    template <typename T, typename DB>
    static typename object_traits<T>::pointer_type
    loader (database_type&, const typename object_traits<T>::id_type&);

  protected:
    void* id_;
    database_type* db_;
    void* loader_;

  private:
    free_func free_;
    copy_func copy_;
  };

  template <typename T>
  class lazy_ptr_impl: public lazy_ptr_base
  {
  public:
    lazy_ptr_impl ();

    template <typename DB, typename ID>
    lazy_ptr_impl (DB&, const ID&);

    lazy_ptr_impl (const lazy_ptr_impl&);

    template <typename Y>
    lazy_ptr_impl (const lazy_ptr_impl<Y>&);

    lazy_ptr_impl (const lazy_ptr_impl_ref&);

    lazy_ptr_impl&
    operator= (const lazy_ptr_impl&);

    template <typename Y>
    lazy_ptr_impl&
    operator= (const lazy_ptr_impl<Y>&);

    lazy_ptr_impl&
    operator= (const lazy_ptr_impl_ref&);

    // C++11 support.
    //
  public:
#ifdef ODB_CXX11
    lazy_ptr_impl (lazy_ptr_impl&&);

    template <typename Y>
    lazy_ptr_impl (lazy_ptr_impl<Y>&&);

    lazy_ptr_impl&
    operator= (lazy_ptr_impl&&);

    template <typename Y>
    lazy_ptr_impl&
    operator= (lazy_ptr_impl<Y>&&);
#endif

  public:
    using lazy_ptr_base::reset;
    using lazy_ptr_base::reset_id;

    template <typename DB, typename ID>
    void
    reset (DB&, const ID&);

    // Reset the id and set the database to the new value.
    //
    template <typename DB>
    void
    reset_db (DB&);

    template <typename ID>
    void
    reset_id (const ID&);

    template <typename O /* = T */>
    typename object_traits<O>::pointer_type
    load (bool reset_id);

    template <typename O /* = T */>
    typename object_traits<O>::id_type
    object_id () const;
  };
}

#include <odb/lazy-ptr-impl.ixx>
#include <odb/lazy-ptr-impl.txx>

#include <odb/post.hxx>

#endif // ODB_LAZY_PTR_IMPL_HXX
