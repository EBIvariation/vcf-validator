/* file      : odb/details/config-vc.h
 * copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
 * license   : GNU GPL v2; see accompanying LICENSE file
 */

/* Configuration file for Windows/VC++. */

#ifndef ODB_DETAILS_CONFIG_VC_H
#define ODB_DETAILS_CONFIG_VC_H

#define ODB_THREADS_WIN32
#define ODB_THREADS_TLS_DECLSPEC

/* VC++10 and later have C++11 always enabled.
 */
#if _MSC_VER >= 1600
#  define ODB_CXX11
#  define ODB_CXX11_NULLPTR
#  if _MSC_VER >= 1700
#    define ODB_CXX11_ENUM
#    if _MSC_VER >= 1800
#      define ODB_CXX11_DELETED_FUNCTION
#      define ODB_CXX11_EXPLICIT_CONVERSION_OPERATOR
#      define ODB_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGUMENT
#      define ODB_CXX11_VARIADIC_TEMPLATE
#      define ODB_CXX11_INITIALIZER_LIST
#    endif
#  endif
#endif

#endif /* ODB_DETAILS_CONFIG_VC_H */
