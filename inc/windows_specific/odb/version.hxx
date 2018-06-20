// file      : odb/version.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VERSION_HXX
#define ODB_VERSION_HXX

#include <odb/pre.hxx>

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

// ODB interface version: minor, major, and alpha/beta versions.
//
#define ODB_VERSION     20400
#define ODB_VERSION_STR "2.4"

// libodb version: interface version plus the bugfix version.
//
#define LIBODB_VERSION     2040000
#define LIBODB_VERSION_STR "2.4.0"

#include <odb/post.hxx>

#endif // ODB_VERSION_HXX
