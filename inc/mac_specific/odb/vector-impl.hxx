// file      : odb/vector-impl.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VECTOR_IMPL_HXX
#define ODB_VECTOR_IMPL_HXX

#include <odb/pre.hxx>
#include <odb/details/config.hxx> // ODB_CXX11

#include <new>
#include <cstddef> // std::size_t

#include <odb/transaction.hxx>
#include <odb/details/export.hxx>

namespace odb
{
  // Change tracking vector implementation details.
  //
  class LIBODB_EXPORT vector_impl
  {
  public:
    enum element_state_type
    {
      state_unchanged,
      state_inserted,
      state_updated,
      state_erased
    };

    enum container_state_type
    {
      state_tracking,
      state_not_tracking,
      state_changed       // Container has changed but individual changes
                          // were not tracked.
    };

    vector_impl ();
    ~vector_impl ();

    // The copy constructor will copy the state. The idea is that the
    // copy keeps tracking changes, just like the original.
    //
    vector_impl (const vector_impl&);

#ifdef ODB_CXX11
    vector_impl (vector_impl&&);
#endif

    void
    swap (vector_impl& x);

    // Allocate enough memory to store the specified number of
    // elements.
    //
    void
    reserve (std::size_t);

    // Reduce capacity to size.
    //
    void
    shrink_to_fit ();

    // Capacity (each entry takes 2 bits).
    //
    std::size_t
    capacity () const;

    // (Re)start tracking changes for a vector with n elements.
    //
    void
    start (std::size_t);

    // Stop tracking changes.
    //
    void
    stop ();

    // Mark the container as changed without tracking the changes.
    // This state is useful as a fallback mechnism for situations
    // where the change information has been discarded (e.g., after
    // its state has been updated in the database) but the container
    // should remain changed (e.g., after the transaction is rolled
    // back).
    //
    void
    change ();

    // Get the state of the container.
    //
    container_state_type
    state () const;

    // Shortcut for state() == state_tracking.
    //
    bool
    tracking () const;

    // Note that the returned size can be greater than the actual,
    // parallel vector size. In this case the difference is the
    // erased elements at the back.
    //
    std::size_t
    size () const;

    // Get the change state of the specified element.
    //
    element_state_type
    state (std::size_t) const;

    // Change notifications.
    //
    void
    push_back (std::size_t n = 1);

    void
    pop_back (std::size_t n = 1);

    void
    insert (std::size_t, std::size_t n = 1);

    void
    erase (std::size_t, std::size_t n = 1);

    void
    modify (std::size_t, std::size_t n = 1);

    void
    clear ();

    void
    assign (std::size_t n);

    void
    resize (std::size_t n);

  private:
    // Assignment does not make sense (it is changing of the content).
    //
    vector_impl& operator= (const vector_impl&);

  private:
    void
    realloc (std::size_t);

    void
    set (std::size_t, element_state_type);

    static const unsigned char mask_[4];
    static const unsigned char shift_[4];

    container_state_type state_;

    // Size, tail, and capacity are in 2-bit blocks. Size is the number
    // of elements we have in data. Tail is the position of the first
    // erased element at the back. If there are no erased elements, then
    // tail is equal size. Capacity is the number of elements we can
    // store in data.
    //
    std::size_t size_;
    std::size_t tail_;
    std::size_t capacity_;
    unsigned char* data_;
  };

  // Base class that provides a change tracking interface and
  // handles the rollback callback. The only function that's
  // missing is _start() which needs to know the number of
  // elements currently in the vector.
  //
  class LIBODB_EXPORT vector_base
  {
  public:
    void
    _stop () const;

    bool
    _tracking () const;

    void
    _arm (transaction& t) const;

    vector_impl&
    _impl () const {return impl_;}

  private:
    // Assignment is changing of the content.
    //
    vector_base& operator= (const vector_base&);

  protected:
    ~vector_base ();
    vector_base ();
    vector_base (const vector_base&);

#ifdef ODB_CXX11
    vector_base (vector_base&&);
#endif

    void
    swap (vector_base&);

    static void
    rollback (unsigned short, void* key, unsigned long long);

  private:
    void
    swap_tran (vector_base&);

  protected:
    mutable vector_impl impl_;
    mutable transaction* tran_;
  };
}

#include <odb/vector-impl.ixx>

#include <odb/post.hxx>

#endif // ODB_VECTOR_IMPL_HXX
