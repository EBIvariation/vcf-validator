// file      : odb/sqlite/binding.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_BINDING_HXX
#define ODB_SQLITE_BINDING_HXX

#include <odb/pre.hxx>

#include <cstddef>  // std::size_t

#include <odb/forward.hxx>

#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class LIBODB_SQLITE_EXPORT binding
    {
    public:
      typedef sqlite::bind bind_type;

      binding (): bind (0), count (0), version (0) {}

      binding (bind_type* b, std::size_t n)
          : bind (b), count (n), version (0)
      {
      }

      bind_type* bind;
      std::size_t count;
      std::size_t version;

    private:
      binding (const binding&);
      binding& operator= (const binding&);
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_BINDING_HXX
