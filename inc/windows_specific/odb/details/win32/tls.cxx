// file      : odb/details/win32/tls.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/windows.hxx>
#include <winerror.h> // ERROR_INVALID_INDEX

#include <new>
#include <cstddef> // std::size_t

#include <odb/details/win32/lock.hxx>
#include <odb/details/win32/tls.hxx>
#include <odb/details/win32/tls-init.hxx>
#include <odb/details/win32/exceptions.hxx>

#ifdef _MSC_VER
#  pragma warning (disable:4200) // zero-sized array in struct
#endif

using namespace std;

namespace odb
{
  namespace details
  {
    typedef void (*dtor_func) (void*);

    struct entry
    {
      void* value;
      dtor_func dtor;
    };

    struct thread_data
    {
      size_t size;
      size_t capacity;
      entry entries[0];
    };

    struct process_data
    {
      size_t size;
      size_t capacity;
      dtor_func dtors[0];
    };

    static DWORD index_ = TLS_OUT_OF_INDEXES;
    static CRITICAL_SECTION cs_;
    static process_data* proc_data_;

    const size_t init_capacity = 4;

    void
    tls_process_start ()
    {
      index_ = TlsAlloc ();

      if (index_ == TLS_OUT_OF_INDEXES)
        throw win32_exception ();

      InitializeCriticalSection (&cs_);

      process_data* pd (
        static_cast<process_data*> (
          operator new (
            sizeof (process_data) + sizeof (dtor_func) * init_capacity)));

      pd->size = 0;
      pd->capacity = init_capacity;
      memset (pd->dtors, 0, sizeof (dtor_func) * init_capacity);

      proc_data_ = pd;
    }

    void
    tls_process_end (bool)
    {
      operator delete (proc_data_);
      DeleteCriticalSection (&cs_);

      if (index_ != TLS_OUT_OF_INDEXES)
      {
        if (!TlsFree (index_))
          throw win32_exception ();
      }
    }

    void
    tls_thread_end ()
    {
      if (thread_data* d = static_cast<thread_data*> (TlsGetValue (index_)))
      {
        // Call destructors. Implement the pthread semantics in that the
        // destructors are called until all the values become 0.
        //
        for (bool pass (true); pass;)
        {
          pass = false;

          for (size_t i (0); i < d->size; ++i)
          {
            if (d->entries[i].dtor != 0 && d->entries[i].value != 0)
            {
              pass = true;
              void* tmp (d->entries[i].value);
              d->entries[i].value = 0;
              d->entries[i].dtor (tmp);
            }
          }
        }

        operator delete (d);
      }
    }

    //
    // tls_common
    //

    std::size_t tls_common::
    _allocate (dtor_func dtor)
    {
      win32_lock l (cs_);

      size_t n (proc_data_->size);
      size_t c (proc_data_->capacity);

      if (n == c)
      {
        c *= 2;

        // Try to do "atomic" switch-over so that proc_data_ always points
        // to memory that can be freed even if this thread is killed in the
        // middle.
        //
        process_data* pd (
          static_cast<process_data*> (
            operator new (sizeof (process_data) + sizeof (dtor_func) * c)));

        memcpy (pd->dtors, proc_data_->dtors, n * sizeof (dtor_func));
        memset (pd->dtors + n, 0, sizeof (dtor_func) * (c - n));

        pd->size = n;
        pd->capacity = c;

        process_data* old (proc_data_);
        proc_data_ = pd;
        operator delete (old);
      }

      proc_data_->dtors[n] = dtor;
      return proc_data_->size++;
    }

    void* tls_common::
    _get (std::size_t key)
    {
      if (thread_data* d = static_cast<thread_data*> (TlsGetValue (index_)))
      {
        if (key < d->size)
          return d->entries[key].value;
      }

      // Check if this key is valid.
      //
      win32_lock l (cs_);

      if (key < proc_data_->size)
        return 0;

      throw win32_exception (ERROR_INVALID_INDEX);
    }

    void tls_common::
    _set (std::size_t key, void* value)
    {
      thread_data* d (static_cast<thread_data*> (TlsGetValue (index_)));

      if (d != 0 && key < d->capacity)
      {
        if (key >= d->size)
        {
          // Check if this key is valid. If so then we need to copy
          // dtors for new slots.
          //
          win32_lock l (cs_);

          size_t n (proc_data_->size);

          if (key >= n)
            throw win32_exception (ERROR_INVALID_INDEX);

          for (size_t i (d->size); i < n; ++i)
            d->entries[i].dtor = proc_data_->dtors[i];

          d->size = n;
        }

        d->entries[key].value = value;
      }
      else
      {
        // Check if this key is valid. If so then we need to (re)-allocate
        // our storage.
        //
        win32_lock l (cs_);

        size_t n (proc_data_->size);

        if (key >= n)
          throw win32_exception (ERROR_INVALID_INDEX);

        size_t c (proc_data_->capacity);

        thread_data* nd (
          static_cast<thread_data*> (
            operator new (sizeof (thread_data) + sizeof (entry) * c)));

        size_t on (d == 0 ? 0 : d->size);

        // Copy over the data.
        //
        if (on != 0)
          memcpy (nd->entries, d->entries, sizeof (entry) * on);

        // Zero out the rest.
        //
        memset (nd->entries + on, 0, sizeof (entry) * (c - on));

        // Assign destructors to new slots [on, n).
        //
        for (size_t i (on); i < n; ++i)
          nd->entries[i].dtor = proc_data_->dtors[i];

        nd->size = n;
        nd->capacity = c;

        operator delete (d);
        TlsSetValue (index_, nd);

        nd->entries[key].value = value;
      }
    }
  }
}
