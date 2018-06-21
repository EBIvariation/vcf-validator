// file      : odb/details/win32/thread.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_THREAD_HXX
#define ODB_DETAILS_WIN32_THREAD_HXX

#include <odb/pre.hxx>

#include <odb/details/win32/windows.hxx>
#include <odb/details/export.hxx>
#include <odb/details/win32/mutex.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT thread
    {
    public:
      ~thread ();
      thread (void* (*thread_func) (void*), void* arg = 0);

      void*
      join ();

    private:
      thread (const thread&);
      thread& operator= (const thread&);

    private:
      typedef void* (*thread_func) (void*);

      struct data
      {
        thread_func func;
        void* arg;
        void* ret;

        // Thread-safe reference counter.
        //
        details::mutex mutex;
        unsigned char count;
      };


    public:
      static void
      thread_thunk (void*);

    private:
      HANDLE handle_;
      data* data_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_THREAD_HXX
