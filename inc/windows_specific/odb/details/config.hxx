// file      : odb/details/config.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_CONFIG_HXX
#define ODB_DETAILS_CONFIG_HXX

// no pre

#ifdef _MSC_VER
#  include <odb/details/config-vc.h>
#elif defined(ODB_COMPILER)
#  define ODB_THREADS_NONE
#  define LIBODB_STATIC_LIB
#  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
#    define ODB_CXX11
#    if (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || __GNUC__ > 4
#      define ODB_CXX11_NULLPTR
#    endif
#    define ODB_CXX11_DELETED_FUNCTION
#    define ODB_CXX11_EXPLICIT_CONVERSION_OPERATOR
#    define ODB_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGUMENT
#    define ODB_CXX11_VARIADIC_TEMPLATE
#    define ODB_CXX11_INITIALIZER_LIST
#  endif
#else
#  include <odb/details/config.h>
#  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
#    define ODB_CXX11
#    ifdef __GNUC__
#      if (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || __GNUC__ > 4
#        define ODB_CXX11_NULLPTR
#      endif
#    else
#      define ODB_CXX11_NULLPTR
#    endif
#    define ODB_CXX11_DELETED_FUNCTION
#    define ODB_CXX11_EXPLICIT_CONVERSION_OPERATOR
#    define ODB_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGUMENT
#    define ODB_CXX11_VARIADIC_TEMPLATE
#    define ODB_CXX11_INITIALIZER_LIST
// GCC supports strongly typed enums from 4.4 (forward -- 4.6),
// Clang -- 2.9 (3.1).
//
#    define ODB_CXX11_ENUM
#  endif
#endif

// no post

#endif // ODB_DETAILS_CONFIG_HXX
