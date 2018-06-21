// file      : odb/details/win32/thread.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/win32/windows.hxx>
#include <process.h> // _beginthreadex, _endthreadex

#include <odb/details/unique-ptr.hxx>
#include <odb/details/win32/thread.hxx>
#include <odb/details/win32/exceptions.hxx>

unsigned int __stdcall
odb_thread_thunk (void* arg)
{
  odb::details::thread::thread_thunk (arg);
  _endthreadex (0);
  return 0;
}

namespace odb
{
  namespace details
  {
    void thread::
    thread_thunk (void* arg)
    {
      data* d (static_cast<data*> (arg));
      d->ret = d->func (d->arg);
      d->mutex.lock ();
      unsigned char count = --d->count;
      d->mutex.unlock ();

      if (count == 0)
        delete d;
    }

    thread::
    ~thread ()
    {
      if (handle_ != 0)
      {
        CloseHandle (handle_);

        // Win32 mutex implementation does not throw.
        //
        data_->mutex.lock ();
        unsigned char count = --data_->count;
        data_->mutex.unlock ();

        if (count == 0)
          delete data_;
      }
    }

    thread::
    thread (void* (*func) (void*), void* arg)
    {
      unique_ptr<data> d (new data);
      d->func = func;
      d->arg = arg;
      d->count = 2; // One for the thread and one for us.

      handle_ = (HANDLE)_beginthreadex (
        0, 0, &odb_thread_thunk, d.get (), 0, 0);

      if (handle_ == 0)
        throw win32_exception ();

      data_ = d.release ();
    }

    void* thread::
    join ()
    {
      void* r;

      if (WaitForSingleObject (handle_, INFINITE) != 0)
        throw win32_exception ();

      r = data_->ret;

      CloseHandle (handle_);
      delete data_;
      handle_ = 0;
      data_ = 0;
       return r;
    }
  }
}
