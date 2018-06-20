// file      : odb/query-dynamic.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  // query_base
  //
  inline query_base::
  query_base (const query_column<bool>& c)
  {
    // Some databases provide the IS TRUE operator. However, we cannot
    // use it since the column type might now be SQL boolean type.
    //
    append (c.native_info);
    append_val (true, c.native_info);
    append (query_base::clause_part::op_eq, 0);
  }
}
