// file      : odb/sqlite/details/config.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_DETAILS_CONFIG_HXX
#define ODB_SQLITE_DETAILS_CONFIG_HXX

// no pre

#ifdef _MSC_VER
#elif defined(ODB_COMPILER)
#  error libodb-sqlite header included in odb-compiled header
#else
#  include <odb/sqlite/details/config.h>
#endif

// no post

#endif // ODB_SQLITE_DETAILS_CONFIG_HXX
