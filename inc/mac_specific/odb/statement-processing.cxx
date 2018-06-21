// file      : odb/statement-processing.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cassert>

#include <odb/statement-processing-common.hxx>

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
#  include <iostream>
#endif

#include <odb/statement.hxx>

using namespace std;

namespace odb
{
  typedef const void* const* bind_type;

  static inline const void*
  bind_at (size_t i, bind_type bind, size_t bind_skip)
  {
    const char* b (reinterpret_cast<const char*> (bind));
    return *reinterpret_cast<bind_type> (b + i * bind_skip);
  }

  void statement::
  process_insert (const char* s,
                  bind_type bind,
                  size_t bind_size,
                  size_t bind_skip,
                  char param_symbol,
                  string& r)
  {
#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
    assert (bind_size != 0); // Cannot be versioned.
#endif

    bool fast (true); // Fast case (if all present).
    for (size_t i (0); i != bind_size && fast; ++i)
    {
      if (bind_at (i, bind, bind_skip) == 0)
        fast = false;
    }

    // Fast path: just remove the "structure".
    //
#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
    if (fast)
    {
      process_fast (s, r);
      return;
    }
#endif

    // Scan the statement and store the positions of various parts.
    //
    size_t n (traits::length (s));
    const char* e (s + n);

    // Header.
    //
    const char* p (find (s, e, '\n'));
    assert (p != 0);
    size_t header_size (p - s);
    p++;

    // Column list.
    //
    const char* columns_begin (0);
    if (*p == '(')
    {
      columns_begin = p;

      // Find the end of the column list.
      //
      for (const char* ce (paren_begin (p, e)); ce != 0; paren_next (p, ce, e))
        ;
    }

    // OUTPUT
    //
    const char* output_begin (0);
    size_t output_size (0);
    if (e - p > 7 && traits::compare (p, "OUTPUT ", 7) == 0)
    {
      output_begin = p;
      p += 7;
      p = find (p, e, '\n');
      assert (p != 0);
      output_size = p - output_begin;
      p++;
    }

    // VALUES or DEFAULT VALUES
    //
    bool empty (true); // DEFAULT VALUES case (if none present).
    const char* values_begin (0);
    if (e - p > 7 && traits::compare (p, "VALUES\n", 7) == 0)
    {
      p += 7;
      values_begin = p;

      size_t bi (0);
      for (const char* ve (paren_begin (p, e)); ve != 0; paren_next (p, ve, e))
      {
        // We cannot be empty if we have a non-parameterized value, e.g.,
        // INSERT ... VALUES(1,?). We also cannot be empty if this value
        // is present in the bind array.
        //
        if (find (p, ve, param_symbol) == 0 ||
            bind_at (bi++, bind, bind_skip) != 0)
          empty = false;
      }
    }
    else
    {
      // Must be DEFAULT VALUES.
      //
      assert (traits::compare (p, "DEFAULT VALUES", 14) == 0);
      p += 14;

      if (*p == '\n')
        p++;
    }

    // Trailer.
    //
    const char* trailer_begin (0);
    size_t trailer_size (0);
    if (e - p != 0)
    {
      trailer_begin = p;
      trailer_size = e - p;
    }

    // Empty case.
    //
    if (empty)
    {
      r.reserve (header_size +
                 (output_size == 0 ? 0 : output_size + 1) +
                 15 + // For " DEFAULT VALUES"
                 (trailer_size == 0 ? 0 : trailer_size + 1));

      r.assign (s, header_size);

      if (output_size != 0)
      {
        r += ' ';
        r.append (output_begin, output_size);
      }

      r += " DEFAULT VALUES";

      if (trailer_size != 0)
      {
        r += ' ';
        r.append (trailer_begin, trailer_size);
      }

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
      if (r.size () != n)
        cerr << endl
             << "old: '" << s << "'" << endl << endl
             << "new: '" << r << "'" << endl << endl;
#endif

      return;
    }

    // Assume the same size as the original. It can only shrink, and in
    // most cases only slightly. So this is a good approximation.
    //
    r.reserve (n);
    r.assign (s, header_size);

    // Column list.
    //
    {
      r += ' ';

      size_t i (0), bi (0);

      for (const char *c (columns_begin), *ce (paren_begin (c, e)),
                      *v (values_begin), *ve (paren_begin (v, e));
           ce != 0; paren_next (c, ce, e), paren_next (v, ve, e))
      {
        // See if the value contains the parameter symbol and, if so,
        // whether it is present in the bind array.
        //
        if (find (v, ve, param_symbol) != 0 &&
            bind_at (bi++, bind, bind_skip) == 0)
          continue;

        // Append the column.
        //
        if (i++ == 0)
          r += '(';
        else
          r += ", "; // Add the space for consistency with the fast path.

        r.append (c, ce - c);
      }

      r += ')';
    }

    // OUTPUT
    //
    if (output_size != 0)
    {
      r += ' ';
      r.append (output_begin, output_size);
    }

    // Value list.
    //
    {
      r += " VALUES ";

      size_t i (0), bi (0);

      for (const char* v (values_begin), *ve (paren_begin (v, e));
           ve != 0; paren_next (v, ve, e))
      {
        // See if the value contains the parameter symbol and, if so,
        // whether it is present in the bind array.
        //
        if (find (v, ve, param_symbol) != 0 &&
            bind_at (bi++, bind, bind_skip) == 0)
          continue;

        // Append the value.
        //
        if (i++ == 0)
          r += '(';
        else
          r += ", "; // Add the space for consistency with the fast path.

        r.append (v, ve - v);
      }

      r += ')';
    }

    // Trailer.
    //
    if (trailer_size != 0)
    {
      r += ' ';
      r.append (trailer_begin, trailer_size);
    }

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
    if (r.size () != n)
      cerr << endl
           << "old: '" << s << "'" << endl << endl
           << "new: '" << r << "'" << endl << endl;
#endif
  }

  void statement::
  process_update (const char* s,
                  bind_type bind,
                  size_t bind_size,
                  size_t bind_skip,
                  char param_symbol,
                  string& r)
  {
    bool fast (true); // Fast case (if all present).
    for (size_t i (0); i != bind_size && fast; ++i)
    {
      if (bind_at (i, bind, bind_skip) == 0)
        fast = false;
    }

    // Fast path: just remove the "structure".
    //
#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
    if (fast)
    {
      process_fast (s, r);
      return;
    }
#endif

    // Scan the statement and store the positions of various parts.
    //
    size_t n (traits::length (s));
    const char* e (s + n);

    // Header.
    //
    const char* p (find (s, e, '\n'));
    assert (p != 0);
    size_t header_size (p - s);
    p++;

    // SET
    //
    bool empty (true); // Empty SET case.
    const char* set_begin (0);
    if (e - p > 4 && traits::compare (p, "SET\n", 4) == 0)
    {
      p += 4;
      set_begin = p;

      // Scan the SET list.
      //
      size_t bi (0);
      for (const char* pe (comma_begin (p, e)); pe != 0; comma_next (p, pe, e))
      {
        if (empty)
        {
          // We cannot be empty if we have a non-parameterized set expression,
          // e.g., UPDATE ... SET ver=ver+1 ... We also cannot be empty if
          // this expression is present in the bind array.
          //
          if (find (p, pe, param_symbol) == 0 ||
              bind_at (bi++, bind, bind_skip) != 0)
            empty = false;
        }
      }
    }

    // Empty case.
    //
    if (empty)
    {
      r.clear ();

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
      if (n != 0)
        cerr << endl
             << "old: '" << s << "'" << endl << endl
             << "new: '" << r << "'" << endl << endl;
#endif

      return;
    }

    // Trailer.
    //
    const char* trailer_begin (0);
    size_t trailer_size (0);
    if (e - p != 0)
    {
      trailer_begin = p;
      trailer_size = e - p;
    }

    // Assume the same size as the original. It can only shrink, and in
    // most cases only slightly. So this is a good approximation.
    //
    r.reserve (n);
    r.assign (s, header_size);

    // SET list.
    //
    {
      r += " SET ";

      size_t i (0), bi (0);

      for (const char* p (set_begin), *pe (comma_begin (p, e));
           pe != 0; comma_next (p, pe, e))
      {
        // See if the value contains the parameter symbol and, if so,
        // whether it is present in the bind array.
        //
        if (find (p, pe, param_symbol) != 0 &&
            bind_at (bi++, bind, bind_skip) == 0)
          continue;

        // Append the expression.
        //
        if (i++ != 0)
          r += ", "; // Add the space for consistency with the fast path.

        r.append (p, pe - p);
      }
    }

    // Trailer.
    //
    if (trailer_size != 0)
    {
      r += ' ';
      r.append (trailer_begin, trailer_size);
    }

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
    if (r.size () != n)
      cerr << endl
           << "old: '" << s << "'" << endl << endl
           << "new: '" << r << "'" << endl << endl;
#endif
  }

  void statement::
  process_select (const char* s,
                  bind_type bind,
                  size_t bind_size,
                  size_t bind_skip,
                  char quote_open,
                  char quote_close,
#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
                  bool optimize,
#else
                  bool,
#endif
                  string& r,
                  bool as)
  {
    bool empty (true); // Empty case (if none present).
    bool fast (true);  // Fast case (if all present).
    for (size_t i (0); i != bind_size && (empty || fast); ++i)
    {
      if (bind_at (i, bind, bind_skip) != 0)
        empty = false;
      else
        fast = false;
    }

    // Empty.
    //
    if (empty)
    {
      r.clear ();

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
      if (*s != '\0')
        cerr << endl
             << "old: '" << s << "'" << endl << endl
             << "new: '" << r << "'" << endl << endl;
#endif
      return;
    }

    // Fast path: just remove the "structure".
    //
#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
    if (fast && !optimize)
    {
      process_fast (s, r);
      return;
    }
#endif

    // Scan the statement and store the positions of various parts.
    //
    size_t n (traits::length (s));
    const char* e (s + n);

    // Header.
    //
    const char* p (find (s, e, '\n'));
    assert (p != 0);
    size_t header_size (p - s);
    p++;

    // Column list.
    //
    const char* columns_begin (p);
    for (const char* ce (comma_begin (p, e)); ce != 0; comma_next (p, ce, e))
      ;

    // FROM.
    assert (traits::compare (p, "FROM ", 5) == 0);
    const char* from_begin (p);
    p = find (p, e, '\n'); // May not end with '\n'.
    if (p == 0)
      p = e;
    size_t from_size (p - from_begin);
    if (p != e)
      p++;

    // JOIN list.
    //
    const char* joins_begin (0), *joins_end (0);
    if (e - p > 5 && fuzzy_prefix (p, e, "JOIN ", 5))
    {
      joins_begin = p;

      // Find the end of the JOIN list.
      //
      for (const char* je (newline_begin (p, e));
           je != 0; newline_next (p, je, e, "JOIN ", 5, true))
        ;

      joins_end = (p != e ? p - 1 : p);
    }

#ifndef LIBODB_DEBUG_STATEMENT_PROCESSING
    if (fast && joins_begin == 0)
    {
      // No JOINs to optimize so can still take the fast path.
      //
      process_fast (s, r);
      return;
    }
#endif

    // Trailer (WHERE, ORDER BY, etc).
    //
    const char* trailer_begin (0);
    size_t trailer_size (0);
    if (e - p != 0)
    {
      trailer_begin = p;
      trailer_size = e - p;
    }

    // Assume the same size as the original. It can only shrink, and in
    // most cases only slightly. So this is a good approximation.
    //
    r.reserve (n);
    r.assign (s, header_size);

    // Column list.
    //
    {
      r += ' ';

      size_t i (0), bi (0);

      for (const char *c (columns_begin), *ce (comma_begin (c, e));
           ce != 0; comma_next (c, ce, e))
      {
        // See if the column is present in the bind array.
        //
        if (bind_at (bi++, bind, bind_skip) == 0)
          continue;

        // Append the column.
        //
        if (i++ != 0)
          r += ", "; // Add the space for consistency with the fast path.

        r.append (c, ce - c);
      }
    }

    // From.
    //
    r += ' ';
    r.append (from_begin, from_size);

    // JOIN list, pass 1.
    //
    size_t join_pos (0);
    if (joins_begin != 0)
    {
      // Fill in the JOIN "area" with spaces.
      //
      r.resize (r.size () + joins_end - joins_begin + 1, ' ');
      join_pos = r.size () + 1; // End of the last JOIN.
    }

    // Trailer.
    //
    if (trailer_size != 0)
    {
      r += ' ';
      r.append (trailer_begin, trailer_size);
    }

    // JOIN list, pass 2.
    //
    if (joins_begin != 0)
    {
      // Splice the JOINs into the pre-allocated area.
      //
      for (const char* je (joins_end), *j (newline_rbegin (je, joins_begin));
           j != 0; newline_rnext (j, je, joins_begin))
      {
        size_t n (je - j);

        // Get the alias or, if none used, the table name.
        //
        p = find (j, je, "JOIN ", 5) + 5; // Skip past "JOIN ".
        const char* table_begin (p);
        p = find (p, je, ' '); // End of the table name.
        const char* table_end (p);
        p++; // Skip space.

        // We may or may not have the AS keyword.
        //
        const char* alias_begin (0);
        size_t alias_size (0);

        if (p != je && // Not the end.
            (je - p < 4 || traits::compare (p, "ON ", 3) != 0))
        {
          // Something other than "ON ", so got to be an alias.
          //
          if (as)
            p += 3;

          alias_begin = p;
          p = find (p, je, ' '); // There might be no ON (CROSS JOIN).
          alias_size = (p != 0 ? p : je) - alias_begin;
        }
        else
        {
          // Just the table.
          //
          alias_begin = table_begin;
          alias_size = table_end - alias_begin;
        }

        // The alias must be quoted.
        //
        assert (*alias_begin == quote_open &&
                *(alias_begin + alias_size - 1) == quote_close);

        // We now need to see if the alias is used in either the SELECT
        // list, the WHERE conditions, or the ON condition of any of the
        // JOINs that we have already processed and decided to keep.
        //
        // Instead of re-parsing the whole thing again, we are going to
        // take a shortcut and simply search for the alias in the statement
        // we have constructed so far (that's why we have added the
        // trailer before filling in the JOINs). To make it more robust,
        // we are going to do a few extra sanity checks, specifically,
        // that the alias is a top level identifier and is followed by
        // only a single identifer (column). This will catch cases like
        // [s].[t].[c] where [s] is also used as an alias or LEFT JOIN [t]
        // where [t] is also used as an alias in another JOIN.
        //
        bool found (false);
        for (size_t p (r.find (alias_begin, 0, alias_size));
             p != string::npos;
             p = r.find (alias_begin, p + alias_size, alias_size))
        {
          size_t e (p + alias_size);

          // If we are not a top-level qualifier or not a bottom-level,
          // then we are done (3 is for at least "[a]").
          //
          if ((p != 0 && r[p - 1] == '.') ||
              (e + 3 >= r.size () || (r[e] != '.' || r[e + 1] != quote_open)))
            continue;

          // The only way to distinguish the [a].[c] from FROM [a].[c] or
          // JOIN [a].[c] is by checking the prefix.
          //
          if ((p > 5 && r.compare (p - 5, 5, "FROM ") == 0) ||
              (p > 5 && r.compare (p - 5, 5, "JOIN ") == 0))
            continue;

          // Check that we are followed by a single identifier.
          //
          e = r.find (quote_close, e + 2);
          if (e == string::npos || (e + 1 != r.size () && r[e + 1] == '.'))
            continue;

          found = true;
          break;
        }

        join_pos -= n + 1; // Extra one for space.
        if (found)
          r.replace (join_pos, n, j, n);
        else
          r.erase (join_pos - 1, n + 1); // Extra one for space.
      }
    }

#ifdef LIBODB_TRACE_STATEMENT_PROCESSING
    if (r.size () != n)
      cerr << endl
           << "old: '" << s << "'" << endl << endl
           << "new: '" << r << "'" << endl << endl;
#endif
  }
}
