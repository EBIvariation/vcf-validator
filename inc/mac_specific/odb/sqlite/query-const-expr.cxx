// file      : odb/sqlite/query-const-expr.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/sqlite/query.hxx>

namespace odb
{
  namespace sqlite
  {
    // Sun CC cannot handle this in query.cxx.
    //
    const query_base query_base::true_expr (true);
  }
}
