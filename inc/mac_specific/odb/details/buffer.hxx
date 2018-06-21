// file      : odb/details/buffer.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_BUFFER_DETAILS_HXX
#define ODB_BUFFER_DETAILS_HXX

#include <odb/pre.hxx>

#include <new>
#include <cstddef> // std::size_t

#include <odb/details/export.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT basic_buffer_base
    {
    public:
      ~basic_buffer_base ()
      {
        if (data_ != 0)
          operator delete (data_);
      }

      basic_buffer_base (std::size_t capacity)
        : capacity_ (capacity)
      {
        data_ = capacity_ == 0 ? 0 : operator new (capacity_);
      }

      std::size_t
      capacity () const
      {
        return capacity_;
      }

      void
      capacity (std::size_t, std::size_t data_size = 0);

    protected:
      void* data_;
      std::size_t capacity_;
    };

    template <typename T>
    class basic_buffer: public basic_buffer_base
    {
    public:
      basic_buffer (std::size_t capacity = 256)
          : basic_buffer_base (capacity)
      {
      }

      T*
      data ()
      {
        return static_cast<T*> (data_);
      }

      const T*
      data () const
      {
        return static_cast<T*> (data_);
      }
    };

    typedef basic_buffer<char> buffer;
    typedef basic_buffer<unsigned char> ubuffer;
  }
}

#include <odb/post.hxx>

#endif // ODB_BUFFER_DETAILS_HXX
