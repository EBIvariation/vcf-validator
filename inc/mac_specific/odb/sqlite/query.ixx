// file      : odb/sqlite/query.ixx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace sqlite
  {
    inline void query_base::
    init_parameters () const
    {
      return parameters_->init ();
    }

    inline binding& query_base::
    parameters_binding () const
    {
      return parameters_->binding ();
    }

    inline const details::shared_ptr<query_params>& query_base::
    parameters () const
    {
      return parameters_;
    }

    template <typename T, database_type_id ID>
    inline void query_base::
    append (val_bind<T> v, const char* conv)
    {
      append (
        details::shared_ptr<query_param> (
          new (details::shared) query_param_impl<T, ID> (v)),
        conv);
    }

    template <typename T, database_type_id ID>
    inline void query_base::
    append (ref_bind<T> r, const char* conv)
    {
      append (
        details::shared_ptr<query_param> (
          new (details::shared) query_param_impl<T, ID> (r)),
        conv);
    }
  }
}
