// file      : odb/tr1/memory.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TR1_MEMORY_HXX
#define ODB_TR1_MEMORY_HXX

//
// Try to include TR1 <memory> in a compiler-specific manner. Fall back
// on the Boost TR1 implementation if the compiler does not support TR1.
//

#include <cstddef> // __GLIBCXX__, _HAS_TR1

// GNU C++ or Intel C++ using libstd++.
//
#if defined (__GNUC__) && __GNUC__ >= 4 && defined (__GLIBCXX__)
#  include <tr1/memory>
//
// IBM XL C++.
//
#elif defined (__xlC__) && __xlC__ >= 0x0900
#  define __IBMCPP_TR1__
#  include <memory>
//
// VC++ or Intel C++ using VC++ standard library.
//
#elif defined (_MSC_VER) && \
  (_MSC_VER == 1500 && defined (_HAS_TR1) || _MSC_VER > 1500)
#  include <memory>
//
// Boost fall-back.
//
#else
#  include <boost/tr1/memory.hpp>
#endif

#endif // ODB_TR1_MEMORY_HXX
