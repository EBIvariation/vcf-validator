// file      : odb/sqlite/section-statements.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::memset

namespace odb
{
  namespace sqlite
  {
    template <typename T, typename ST>
    section_statements<T, ST>::
    section_statements (connection_type& conn,
                        image_type& im, id_image_type&,
                        binding& id, binding& idv)
        : conn_ (conn),
          svm_ (0),
          image_ (im),
          id_binding_ (id),
          idv_binding_ (idv),
          select_image_binding_ (select_image_bind_,
                                 select_column_count +
                                 managed_optimistic_load_column_count),
          update_image_binding_ (update_image_bind_,
                                 update_column_count + id_column_count +
                                 managed_optimistic_update_column_count)
    {
      select_image_version_ = 0;
      update_image_version_ = 0;
      update_id_binding_version_ = 0;

      std::memset (select_image_bind_, 0, sizeof (select_image_bind_));
      std::memset (
        select_image_truncated_, 0, sizeof (select_image_truncated_));
      std::memset (update_image_bind_, 0, sizeof (update_image_bind_));

      for (std::size_t i (0); i < select_bind_count; ++i)
        select_image_bind_[i].truncated = select_image_truncated_ + i;
    }
  }
}
