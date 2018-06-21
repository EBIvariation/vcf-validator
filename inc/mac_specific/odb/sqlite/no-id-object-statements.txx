// file      : odb/sqlite/no-id-object-statements.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::memset

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    no_id_object_statements<T>::
    ~no_id_object_statements ()
    {
    }

    template <typename T>
    no_id_object_statements<T>::
    no_id_object_statements (connection_type& conn)
        : statements_base (conn),
          select_image_binding_ (select_image_bind_, select_column_count),
          insert_image_binding_ (insert_image_bind_, insert_column_count)
    {
      image_.version = 0;
      select_image_version_ = 0;
      insert_image_version_ = 0;

      std::memset (insert_image_bind_, 0, sizeof (insert_image_bind_));
      std::memset (select_image_bind_, 0, sizeof (select_image_bind_));
      std::memset (
        select_image_truncated_, 0, sizeof (select_image_truncated_));

      for (std::size_t i (0); i < select_column_count; ++i)
        select_image_bind_[i].truncated = select_image_truncated_ + i;
    }
  }
}
