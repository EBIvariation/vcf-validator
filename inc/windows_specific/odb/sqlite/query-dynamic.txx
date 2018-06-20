// file      : odb/sqlite/query-dynamic.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace sqlite
  {
    template <typename T, database_type_id ID>
    details::shared_ptr<query_param>
    query_param_factory_impl (const void* val, bool by_ref)
    {
      const T& v (*static_cast<const T*> (val));

      return details::shared_ptr<query_param> (
        by_ref
        ? new (details::shared) query_param_impl<T, ID> (ref_bind<T> (v))
        : new (details::shared) query_param_impl<T, ID> (val_bind<T> (v)));
    }
  }
}
