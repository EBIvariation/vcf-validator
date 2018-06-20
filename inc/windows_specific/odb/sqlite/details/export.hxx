// file      : odb/sqlite/details/export.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_DETAILS_EXPORT_HXX
#define ODB_SQLITE_DETAILS_EXPORT_HXX

#include <odb/pre.hxx>

#include <odb/sqlite/details/config.hxx>

#ifdef LIBODB_SQLITE_STATIC_LIB
#  define LIBODB_SQLITE_EXPORT
#else
#  ifdef _WIN32
#    ifdef _MSC_VER
#      ifdef LIBODB_SQLITE_DYNAMIC_LIB
#        define LIBODB_SQLITE_EXPORT __declspec(dllexport)
#      else
#        define LIBODB_SQLITE_EXPORT __declspec(dllimport)
#      endif
#    else
#      ifdef LIBODB_SQLITE_DYNAMIC_LIB
#        ifdef DLL_EXPORT
#          define LIBODB_SQLITE_EXPORT __declspec(dllexport)
#        else
#          define LIBODB_SQLITE_EXPORT
#        endif
#      else
#        define LIBODB_SQLITE_EXPORT __declspec(dllimport)
#      endif
#    endif
#  else
#    define LIBODB_SQLITE_EXPORT
#  endif
#endif

#include <odb/post.hxx>

#endif // ODB_SQLITE_DETAILS_EXPORT_HXX
