// file      : odb/sqlite/query-dynamic.ixx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace sqlite
  {
    //
    //
    template <typename T, database_type_id ID>
    inline query_column<T, ID>::
    query_column (odb::query_column<T>& qc,
                  const char* table, const char* column, const char* conv)
        : query_column_base (table, column, conv)
    {
      native_column_info& ci (qc.native_info[id_sqlite]);
      ci.column = static_cast<query_column_base*> (this);

      // For some reason GCC needs this statically-typed pointer in
      // order to instantiate the functions.
      //
      query_param_factory f (&query_param_factory_impl<T, ID>);
      ci.param_factory = reinterpret_cast<void*> (f);
    }
  }
}
