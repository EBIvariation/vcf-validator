// file      : odb/statement-processingc-common.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STATEMENT_PROCESSING_COMMON_HXX
#define ODB_STATEMENT_PROCESSING_COMMON_HXX

#include <odb/pre.hxx>

//#define LIBODB_DEBUG_STATEMENT_PROCESSING 1
//#define LIBODB_TRACE_STATEMENT_PROCESSING 1

#include <string>
#include <cstddef> // std::size_t

namespace odb
{
  typedef std::char_traits<char> traits;

  static inline const char*
  find (const char* b, const char* e, char c)
  {
    return traits::find (b, e - b, c);
  }

  static inline const char*
  rfind (const char* b, const char* e, char c)
  {
    for (--e; b != e; --e)
      if (*e == c)
        return e;

    return 0;
  }

  static inline const char*
  find (const char* b, const char* e, const char* s, std::size_t n)
  {
    for (; b != e; ++b)
    {
      if (*b == *s &&
          static_cast<std::size_t> (e - b) >= n &&
          traits::compare (b, s, n) == 0)
        return b;
    }

    return 0;
  }

  // Iterate over INSERT column/value list, UPDATE SET expression list,
  // or SELECT column/join list.
  //
  // for (const char* b (columns_begin), *e (begin (b, end));
  //      e != 0;
  //      next (b, e, end))
  // {
  //   // b points to the beginning of the value (i.e., one past '(').
  //   // e points one past the end of the value (i.e., to ',', ')', or '\n').
  // }
  //
  // // b points one past the last value.
  //
  static inline const char*
  paren_begin (const char*& b, const char* end)
  {
    // Note that the list may not end with '\n'.

    b++; // Skip '('.
    const char* e (find (b, end, '\n'));
    return (e != 0 ? e : end) - 1; // Skip ',' or ')'.
  }

  static inline void
  paren_next (const char*& b, const char*& e, const char* end)
  {
    if (*e == ',')
    {
      b = e + 2; // Skip past '\n'.
      e = find (b, end, '\n');
      e = (e != 0 ? e : end) - 1; // Skip ',' or ')'.
    }
    else
    {
      b = (e + 1 != end ? e + 2 : end); // Skip past '\n'.
      e = 0;
    }
  }

  static inline const char*
  comma_begin (const char* b, const char* end)
  {
    // Note that the list may not end with '\n'.

    const char* e (find (b, end, '\n'));
    return e != 0 ? e - (*(e - 1) == ',' ? 1 : 0) : end; // Skip ','.
  }

  static inline void
  comma_next (const char*& b, const char*& e, const char* end)
  {
    if (*e == ',')
    {
      b = e + 2; // Skip past '\n'.
      e = find (b, end, '\n');
      e = (e != 0 ? e - (*(e - 1) == ',' ? 1 : 0) : end); // Skip ','.
    }
    else
    {
      b = (e != end ? e + 1 : end); // Skip past '\n'.
      e = 0;
    }
  }

  // Only allows A-Z and spaces before prefix (e.g., JOIN in LEFT OUTER JOIN).
  //
  static inline bool
  fuzzy_prefix (const char* b,
                const char* end,
                const char* prefix,
                std::size_t prefix_size)
  {
    for (; b != end; ++b)
    {
      char c (*b);

      if ((c < 'A' || c > 'Z') && c != ' ')
        break;

      if (c == *prefix &&
          static_cast<std::size_t> (end - b) > prefix_size &&
          traits::compare (b, prefix, prefix_size) == 0)
        return true;
    }

    return false;
  }

  static inline const char*
  newline_begin (const char* b, const char* end)
  {
    // Note that the list may not end with '\n'.

    const char* e (find (b, end, '\n'));
    return e != 0 ? e : end;
  }

  static inline void
  newline_next (const char*& b,
                const char*& e,
                const char* end,
                const char* prefix,
                std::size_t prefix_size,
                bool prefix_fuzzy = false)
  {
    if (e != end)
      e++; // Skip past '\n'.

    b = e;

    // Do we have another element?
    //
    if (static_cast<std::size_t> (end - b) > prefix_size &&
        (prefix_fuzzy
         ? fuzzy_prefix (b, end, prefix, prefix_size)
         : traits::compare (b, prefix, prefix_size) == 0))
    {
      e = find (b, end, '\n');
      if (e == 0)
        e = end;
    }
    else
      e = 0;
  }

  // Note that end must point to the beginning of the list.
  //
  static inline const char*
  newline_rbegin (const char* e, const char* end)
  {
    const char* b (rfind (end, e - 1, '\n'));
    return b != 0 ? b + 1 : end; // Skip past '\n'.
  }

  static inline void
  newline_rnext (const char*& b, const char*& e, const char* end)
  {
    if (b != end)
    {
      e = b - 1; // Skip to previous '\n'.
      b = rfind (end, e - 1, '\n');
      b = (b != 0 ? b + 1 : end); // Skip past '\n'.
    }
    else
    {
      e = end - 1; // One before the first element.
      b = 0;
    }
  }

  // Fast path: just remove the "structure".
  //
  static inline void
  process_fast (const char* s, std::string& r)
  {
    r = s;
    for (std::size_t i (r.find ('\n'));
         i != std::string::npos;
         i = r.find ('\n', i))
      r[i++] = ' ';
  }
}

#include <odb/post.hxx>

#endif // ODB_STATEMENT_PROCESSING_COMMON_HXX
