// file      : odb/details/win32/windows.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_WINDOWS_HXX
#define ODB_DETAILS_WIN32_WINDOWS_HXX

#include <odb/pre.hxx>

// Try to include <windows.h> so that it doesn't mess other things up.
//
#ifndef WIN32_LEAN_AND_MEAN
#  define WIN32_LEAN_AND_MEAN
#  ifndef NOMINMAX // No min and max macros.
#    define NOMINMAX
#    include <windows.h>
#    undef NOMINMAX
#  else
#    include <windows.h>
#  endif
#  undef WIN32_LEAN_AND_MEAN
#else
#  ifndef NOMINMAX
#    define NOMINMAX
#    include <windows.h>
#    undef NOMINMAX
#  else
#    include <windows.h>
#  endif
#endif

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_WINDOWS_HXX
