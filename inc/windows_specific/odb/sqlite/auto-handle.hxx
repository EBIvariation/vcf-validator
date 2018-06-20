// file      : odb/sqlite/auto-handle.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_AUTO_HANDLE_HXX
#define ODB_SQLITE_AUTO_HANDLE_HXX

#include <odb/pre.hxx>

#include <cassert>
#include <sqlite3.h>

#include <odb/sqlite/version.hxx>

namespace odb
{
  namespace sqlite
  {
    template <typename H>
    struct handle_traits;

    template <>
    struct handle_traits<sqlite3>
    {
      static void
      release (sqlite3* h)
      {
        if (sqlite3_close (h) == SQLITE_BUSY)
        {
          // Connection has outstanding prepared statements.
          //
          assert (false);
        }
      }
    };

    template <>
    struct handle_traits<sqlite3_stmt>
    {
      static void
      release (sqlite3_stmt* h)
      {
        sqlite3_finalize (h);
      }
    };

    template <typename H>
    class auto_handle
    {
    public:
      auto_handle (H* h = 0)
          : h_ (h)
      {
      }

      ~auto_handle ()
      {
        if (h_ != 0)
          handle_traits<H>::release (h_);
      }

      H*
      get () const
      {
        return h_;
      }

      void
      reset (H* h = 0)
      {
        if (h_ != 0)
          handle_traits<H>::release (h_);

        h_ = h;
      }

      H*
      release ()
      {
        H* h (h_);
        h_ = 0;
        return h;
      }

      operator H* () const
      {
        return h_;
      }

    private:
      auto_handle (const auto_handle&);
      auto_handle& operator= (const auto_handle&);

    private:
      H* h_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_AUTO_HANDLE_HXX
