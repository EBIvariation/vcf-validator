# file      : odb/sqlite/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

lib_LTLIBRARIES = libodb-sqlite.la
libodb_sqlite_la_SOURCES = connection.cxx connection-factory.cxx database.cxx error.cxx exceptions.cxx prepared-query.cxx query.cxx query-dynamic.cxx query-const-expr.cxx simple-object-statements.cxx statement.cxx statements-base.cxx statement-cache.cxx tracer.cxx traits.cxx transaction.cxx transaction-impl.cxx details/options.cxx

odbsqliteincludedir = $(includedir)/odb/sqlite/
nobase_odbsqliteinclude_HEADERS = auto-handle.hxx binding.hxx connection-factory.hxx connection.hxx connection.ixx container-statements.hxx container-statements.txx database.hxx database.ixx details/config.hxx details/conversion.hxx details/export.hxx details/options.hxx details/options.ixx error.hxx exceptions.hxx forward.hxx no-id-object-result.hxx no-id-object-result.txx no-id-object-statements.hxx no-id-object-statements.txx polymorphic-object-result.hxx polymorphic-object-result.txx polymorphic-object-statements.hxx polymorphic-object-statements.txx prepared-query.hxx query-dynamic.hxx query-dynamic.ixx query-dynamic.txx query.hxx query.ixx query.txx section-statements.hxx section-statements.txx simple-object-result.hxx simple-object-result.txx simple-object-statements.hxx simple-object-statements.ixx simple-object-statements.txx sqlite-types.hxx statement-cache.hxx statement-cache.txx statement.hxx statements-base.hxx tracer.hxx traits-calls.hxx traits.hxx transaction-impl.hxx transaction-impl.ixx transaction.hxx transaction.ixx version.hxx view-result.hxx view-result.txx view-statements.hxx view-statements.txx
nobase_nodist_odbsqliteinclude_HEADERS = details/config.h

EXTRA_DIST = details/options.cli details/config.h.in libodb-sqlite-vc8.vcproj libodb-sqlite-vc9.vcproj libodb-sqlite-vc10.vcxproj libodb-sqlite-vc10.vcxproj.filters libodb-sqlite-vc11.vcxproj libodb-sqlite-vc11.vcxproj.filters libodb-sqlite-vc12.vcxproj libodb-sqlite-vc12.vcxproj.filters

AM_CPPFLAGS= -I'$(top_builddir)' -I'$(top_srcdir)' -DLIBODB_SQLITE_DYNAMIC_LIB
AM_LDFLAGS = -release 2.4 -no-undefined
