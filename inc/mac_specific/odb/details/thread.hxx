// file      : odb/details/thread.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_THREAD_HXX
#define ODB_DETAILS_THREAD_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx>

#ifdef ODB_THREADS_NONE
# error no thread support available
#elif defined(ODB_THREADS_POSIX)
#include <odb/details/posix/thread.hxx>
#elif defined(ODB_THREADS_WIN32)
#include <odb/details/win32/thread.hxx>
#else
# error unknown threading model
#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_THREAD_HXX
