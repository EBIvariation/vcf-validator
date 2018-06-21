// file      : odb/sqlite/version.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_VERSION_HXX
#define ODB_SQLITE_VERSION_HXX

#include <odb/pre.hxx>

#include <odb/version.hxx>

// Version format is AABBCCDD where
//
// AA - major version number
// BB - minor version number
// CC - bugfix version number
// DD - alpha / beta (DD + 50) version number
//
// When DD is not 00, 1 is subtracted from AABBCC. For example:
//
// Version     AABBCCDD
// 2.0.0       02000000
// 2.1.0       02010000
// 2.1.1       02010100
// 2.2.0.a1    02019901
// 3.0.0.b2    02999952
//

// Check that we have compatible ODB version.
//
#if ODB_VERSION != 20400
#  error incompatible odb interface version detected
#endif

// libodb-sqlite version: odb interface version plus the bugfix
// version.
//
#define LIBODB_SQLITE_VERSION     2040000
#define LIBODB_SQLITE_VERSION_STR "2.4.0"

#include <odb/post.hxx>

#endif // ODB_SQLITE_VERSION_HXX
