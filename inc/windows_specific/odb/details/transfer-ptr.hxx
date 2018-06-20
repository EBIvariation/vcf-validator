// file      : odb/details/transfer-ptr.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_TRANSFER_PTR_HXX
#define ODB_DETAILS_TRANSFER_PTR_HXX

#include <odb/pre.hxx>

#include <memory> // std::auto_ptr, std::unique_ptr

#include <odb/details/config.hxx> // ODB_CXX11

namespace odb
{
  namespace details
  {
    template <typename T>
    class transfer_ptr
    {
    public:
      typedef T element_type;

      transfer_ptr (): p_ (0) {}

      template <typename T1>
      transfer_ptr (std::auto_ptr<T1> p): p_ (p.release ()) {}

#ifdef ODB_CXX11
#ifdef ODB_CXX11_NULLPTR
      transfer_ptr (std::nullptr_t): p_ (0) {}
#endif

      template <typename T1>
      transfer_ptr (std::unique_ptr<T1>&& p): p_ (p.release ()) {}
#endif

      ~transfer_ptr () {delete p_;}

      T*
      transfer ()
      {
        T* r (p_);
        p_ = 0;
        return r;
      }

    private:
      T* p_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_TRANSFER_PTR_HXX
