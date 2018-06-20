// file      : odb/details/posix/thread.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/details/unique-ptr.hxx>
#include <odb/details/posix/thread.hxx>
#include <odb/details/posix/exceptions.hxx>

typedef void* (*thread_func) (void*);

struct thread_data
{
  thread_func func;
  void* arg;
};

extern "C" void*
odb_thread_thunk (void* arg)
{
  thread_data* data (static_cast<thread_data*> (arg));
  thread_func func = data->func;
  arg = data->arg;
  delete data;
  return func (arg);
}

namespace odb
{
  namespace details
  {
    thread::
    thread (void* (*func) (void*), void* arg)
        : detached_ (false)
    {
      unique_ptr<thread_data> data (new thread_data);
      data->func = func;
      data->arg = arg;

      if (int e = pthread_create (&id_, 0, &odb_thread_thunk, data.get ()))
        throw posix_exception (e);

      data.release (); // Thread thunk will free this.
    }
  }
}
