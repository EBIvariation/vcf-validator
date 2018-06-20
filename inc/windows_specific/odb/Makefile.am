# file      : odb/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

lib_LTLIBRARIES = libodb.la
libodb_la_SOURCES = callback.cxx exceptions.cxx database.cxx vector-impl.cxx connection.cxx lazy-ptr-impl.cxx prepared-query.cxx query-dynamic.cxx result.cxx schema-catalog.cxx section.cxx session.cxx statement.cxx statement-processing.cxx tracer.cxx transaction.cxx details/buffer.cxx details/condition.cxx details/lock.cxx details/mutex.cxx details/shared-ptr/base.cxx

odbincludedir = $(includedir)/odb
nobase_odbinclude_HEADERS = std-unordered-map-traits.hxx query-dynamic.txx traits.hxx schema-catalog-impl.hxx version.hxx polymorphic-map.hxx result.hxx lazy-ptr-impl.txx schema-catalog.hxx pointer-traits.hxx std-list-traits.hxx compilers/vc/post.hxx compilers/vc/pre.hxx query-dynamic.hxx statement.hxx vector-traits.hxx object-result.hxx std-set-traits.hxx lazy-ptr.hxx vector.hxx prepared-query.hxx exception.hxx vector-impl.ixx vector.ixx std-array-traits.hxx no-op-cache-traits.hxx section.hxx no-id-object-result.txx lazy-ptr-impl.hxx container-traits.hxx view-result.hxx transaction.hxx polymorphic-object-result.txx view-image.hxx connection.ixx connection.txx std-vector-traits.hxx view-result.txx tracer.hxx database.ixx post.hxx schema-version.hxx vector-traits.txx session.ixx forward.hxx polymorphic-map.txx function-table.hxx session.hxx connection.hxx std-unordered-set-traits.hxx details/lock.hxx details/thread.hxx details/shared-ptr-fwd.hxx details/tls.hxx details/wrapper-p.hxx details/shared-ptr/base.txx details/shared-ptr/exception.hxx details/shared-ptr/counter-type.hxx details/shared-ptr/base.ixx details/shared-ptr/base.hxx details/exception.hxx details/type-info.hxx details/function-wrapper.hxx details/function-wrapper.txx details/meta/remove-volatile.hxx details/meta/class-p.hxx details/meta/remove-const.hxx details/meta/static-assert.hxx details/meta/remove-const-volatile.hxx details/meta/polymorphic-p.hxx details/meta/answer.hxx details/meta/remove-pointer.hxx details/condition.hxx details/buffer.hxx details/shared-ptr.hxx details/transfer-ptr.hxx details/mutex.hxx details/c-string.hxx details/export.hxx details/function-wrapper.ixx details/unused.hxx details/config.hxx details/unique-ptr.hxx polymorphic-map.ixx cache-traits.hxx simple-object-result.txx std-map-traits.hxx lazy-pointer-traits.hxx std-forward-list-traits.hxx lazy-ptr-impl.ixx core.hxx simple-object-result.hxx result.txx polymorphic-info.hxx database.txx tr1/pointer-traits.hxx tr1/lazy-ptr.hxx tr1/memory.hxx tr1/lazy-pointer-traits.hxx tr1/lazy-ptr.ixx tr1/wrapper-traits.hxx tr1/lazy-ptr.txx pre.hxx query-dynamic.ixx query.hxx transaction.ixx callback.hxx lazy-ptr.ixx polymorphic-object-result.hxx wrapper-traits.hxx exceptions.hxx nullable.hxx no-id-object-result.hxx session.txx lazy-ptr.txx vector-impl.hxx database.hxx std-deque-traits.hxx statement-processing-common.hxx
nobase_nodist_odbinclude_HEADERS = details/config.h

EXTRA_DIST = details/config-vc.h libodb-vc8.vcproj libodb-vc9.vcproj libodb-vc10.vcxproj libodb-vc10.vcxproj.filters libodb-vc11.vcxproj libodb-vc11.vcxproj.filters libodb-vc12.vcxproj libodb-vc12.vcxproj.filters

# At the moment, DllMain() is only necessary if we are using Win32
# threads. So keep win32_dll_sources in ODB_THREADS_WIN32.
#
if ODB_WIN32
nobase_odbinclude_HEADERS += details/win32/windows.hxx
endif

if ODB_THREADS_POSIX
libodb_la_SOURCES += details/posix/exceptions.cxx details/posix/thread.cxx
nobase_odbinclude_HEADERS += details/posix/thread.hxx details/posix/tls.hxx details/posix/condition.hxx details/posix/mutex.ixx details/posix/mutex.hxx details/posix/thread.ixx details/posix/tls.ixx details/posix/tls.txx details/posix/condition.ixx details/posix/exceptions.hxx
endif

if ODB_THREADS_WIN32
libodb_la_SOURCES += details/win32/init.cxx details/win32/once.cxx details/win32/tls.cxx details/win32/condition.cxx details/win32/thread.cxx details/win32/exceptions.cxx details/win32/dll.cxx
nobase_odbinclude_HEADERS += details/win32/lock.hxx details/win32/thread.hxx details/win32/once-init.hxx details/win32/tls.hxx details/win32/condition.hxx details/win32/tls-init.hxx details/win32/mutex.ixx details/win32/mutex.hxx details/win32/once.hxx details/win32/once.ixx details/win32/tls.ixx details/win32/tls.txx details/win32/condition.ixx details/win32/init.hxx details/win32/exceptions.hxx
endif

AM_CPPFLAGS= -I'$(top_builddir)' -I'$(top_srcdir)' -DLIBODB_DYNAMIC_LIB
AM_LDFLAGS = -release 2.4 -no-undefined
