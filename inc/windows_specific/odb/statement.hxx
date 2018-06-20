// file      : odb/statement.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STATEMENT_HXX
#define ODB_STATEMENT_HXX

#include <odb/pre.hxx>

#include <string>
#include <cstddef> // std::size_t

#include <odb/forward.hxx> // connection

#include <odb/details/export.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  class LIBODB_EXPORT statement: public details::shared_base
  {
  private:
    statement (const statement&);
    statement& operator= (const statement&);

  public:
    typedef odb::connection connection_type;

    virtual const char*
    text () const = 0;

    virtual connection_type&
    connection ()  = 0;

    virtual
    ~statement () = 0;

  protected:
    statement () {}

    // Statement processing. Kept public only for testing.
    //
  public:
    // Expected statement structure:
    //
    //  INSERT INTO table\n
    // [(a,\n
    //  b)\n]
    // [OUTPUT ...\n]
    // [VALUES\n
    //  ($1,\n
    //  $2)[\n]]
    // [DEFAULT VALUES[\n]]
    // [RETURNING ...]
    // [; SELECT ...]
    //
    static void
    process_insert (const char* statement,
                    const void* const* bind, // Array of bind buffer pointers.
                    std::size_t bind_size,   // Number of bind elements.
                    std::size_t bind_skip,   // Offset to the next bind.
                    char param_symbol,       // $, ?, :, etc.
                    std::string& result);

    // Expected statement structure:
    //
    //  UPDATE table\n
    //  SET\n
    //  a=$1,\n
    //  b=$2[\n]
    // [OUTPUT ...]
    // [WHERE ...]
    //
    static void
    process_update (const char* statement,
                    const void* const* bind, // Array of bind buffer pointers.
                    std::size_t bind_size,   // Number of bind elements.
                    std::size_t bind_skip,   // Offset to the next bind.
                    char param_symbol,       // $, ?, :, etc.
                    std::string& result);

    // Expected statement structure:
    //
    //  SELECT\n
    //  [schema.]table.a,\n
    //  alias.b\n
    //  FROM [schema.]table[\n]
    // [{A-Z }* JOIN [schema.]table [AS alias][ ON ...][\n]]*
    // [WHERE ...]
    //
    static void
    process_select (const char* statement,
                    const void* const* bind, // Array of bind buffer pointers.
                    std::size_t bind_size,   // Number of bind elements.
                    std::size_t bind_skip,   // Offset to the next bind.
                    char quote_open,         // Identifier opening quote.
                    char quote_close,        // Identifier closing quote.
                    bool optimize,           // Remove unused JOINs.
                    std::string& result,
                    bool as = true);         // JOINs use AS keyword.
  };
}

#include <odb/post.hxx>

#endif // ODB_STATEMENT_HXX
