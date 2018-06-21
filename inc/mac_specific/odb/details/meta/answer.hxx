// file      : odb/details/meta/answer.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_ANSWER_HXX
#define ODB_DETAILS_META_ANSWER_HXX

#include <odb/pre.hxx>

namespace odb
{
  namespace details
  {
    namespace meta
    {
      struct yes
      {
        char filling;
      };

      struct no
      {
        char filling[2];
      };
    }
  }
}

#include <odb/post.hxx>

#endif // ODB_DETAILS_META_ANSWER_HXX
