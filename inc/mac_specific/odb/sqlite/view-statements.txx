// file      : odb/sqlite/view-statements.txx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstddef> // std::size_t
#include <cstring> // std::memset

namespace odb
{
  namespace sqlite
  {
    template <typename T>
    view_statements<T>::
    ~view_statements ()
    {
    }

    template <typename T>
    view_statements<T>::
    view_statements (connection_type& conn)
        : statements_base (conn),
          image_binding_ (image_bind_, view_traits::column_count)
    {
      image_.version = 0;
      image_version_ = 0;

      std::memset (image_bind_, 0, sizeof (image_bind_));
      std::memset (image_truncated_, 0, sizeof (image_truncated_));

      for (std::size_t i (0); i < view_traits::column_count; ++i)
        image_bind_[i].truncated = image_truncated_ + i;
    }
  }
}
