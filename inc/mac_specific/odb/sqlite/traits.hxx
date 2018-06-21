// file      : odb/sqlite/traits.hxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_TRAITS_HXX
#define ODB_SQLITE_TRAITS_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11

#include <string>
#include <vector>
#include <limits>  // std::numeric_limits
#include <cstddef> // std::size_t
#include <cstring> // std::memcpy, std::memset, std::strlen

#ifdef ODB_CXX11
#  include <array>
#endif

#include <odb/traits.hxx>
#include <odb/wrapper-traits.hxx>

#include <odb/details/buffer.hxx>
#include <odb/details/wrapper-p.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    enum database_type_id
    {
      id_integer,
      id_real,
      id_text,
      id_blob
    };

    //
    // image_traits
    //

    template <typename T, database_type_id>
    struct image_traits;

    template <typename T>
    struct image_traits<T, id_integer> {typedef long long image_type;};

    template <typename T>
    struct image_traits<T, id_real> {typedef double image_type;};

    template <typename T>
    struct image_traits<T, id_text>
    {
      typedef details::buffer image_type;

      // By default the text is in UTF-8.
      //
      static const bind::buffer_type bind_value = bind::text;
    };

    template <typename T>
    struct image_traits<T, id_blob> {typedef details::buffer image_type;};

    //
    // value_traits
    //

    template <typename W, database_type_id, bool null_handler>
    struct wrapped_value_traits;

    template <typename T, database_type_id>
    struct default_value_traits;

    template <typename T, database_type_id, bool w = details::wrapper_p<T>::r>
    struct select_traits;

    template <typename T, database_type_id ID>
    struct select_traits<T, ID, false>
    {
      typedef default_value_traits<T, ID> type;
    };

    template <typename W, database_type_id ID>
    struct select_traits<W, ID, true>
    {
      typedef
      wrapped_value_traits<W, ID, wrapper_traits<W>::null_handler>
      type;
    };

    template <typename T, database_type_id ID>
    class value_traits: public select_traits<T, ID>::type
    {
    };

    // The wrapped_value_traits specializations should be able to handle
    // any value type which means we have to have every possible signature
    // of the set_value() and set_image() functions.
    //
    template <typename W, database_type_id ID>
    struct wrapped_value_traits<W, ID, false>
    {
      typedef wrapper_traits<W> wtraits;
      typedef typename wtraits::unrestricted_wrapped_type wrapped_type;

      typedef W value_type;
      typedef wrapped_type query_type;
      typedef typename image_traits<wrapped_type, ID>::image_type image_type;

      typedef value_traits<wrapped_type, ID> vtraits;

      static void
      set_value (W& v, const image_type& i, bool is_null)
      {
        vtraits::set_value (wtraits::set_ref (v), i, is_null);
      }

      static void
      set_image (image_type& i, bool& is_null, const W& v)
      {
        vtraits::set_image (i, is_null, wtraits::get_ref (v));
      }

      // TEXT and BLOB.
      //
      static void
      set_value (W& v, const details::buffer& b, std::size_t n, bool is_null)
      {
        vtraits::set_value (wtraits::set_ref (v), b, n, is_null);
      }

      static void
      set_image (details::buffer& b, std::size_t& n, bool& is_null, const W& v)
      {
        vtraits::set_image (b, n, is_null, wtraits::get_ref (v));
      }
    };

    template <typename W, database_type_id ID>
    struct wrapped_value_traits<W, ID, true>
    {
      typedef wrapper_traits<W> wtraits;
      typedef typename wtraits::unrestricted_wrapped_type wrapped_type;

      typedef W value_type;
      typedef wrapped_type query_type;
      typedef typename image_traits<wrapped_type, ID>::image_type image_type;

      typedef value_traits<wrapped_type, ID> vtraits;

      static void
      set_value (W& v, const image_type& i, bool is_null)
      {
        if (is_null)
          wtraits::set_null (v);
        else
          vtraits::set_value (wtraits::set_ref (v), i, is_null);
      }

      static void
      set_image (image_type& i, bool& is_null, const W& v)
      {
        is_null = wtraits::get_null (v);

        if (!is_null)
          vtraits::set_image (i, is_null, wtraits::get_ref (v));
      }

      // TEXT and BLOB.
      //
      static void
      set_value (W& v, const details::buffer& b, std::size_t n, bool is_null)
      {
        if (is_null)
          wtraits::set_null (v);
        else
          vtraits::set_value (wtraits::set_ref (v), b, n, is_null);
      }

      static void
      set_image (details::buffer& b, std::size_t& n, bool& is_null, const W& v)
      {
        is_null = wtraits::get_null (v);

        if (!is_null)
          vtraits::set_image (b, n, is_null, wtraits::get_ref (v));
      }
    };

    template <typename T, database_type_id ID>
    struct default_value_traits
    {
      typedef T value_type;
      typedef T query_type;
      typedef typename image_traits<T, ID>::image_type image_type;

      static void
      set_value (T& v, const image_type& i, bool is_null)
      {
        if (!is_null)
          v = T (i);
        else
          v = T ();
      }

      static void
      set_image (image_type& i, bool& is_null, T v)
      {
        is_null = false;
        i = image_type (v);
      }
    };

    // Float & double specialization. SQLite converts NaNs to NULLs so
    // we convert NULLs to NaNs for consistency.
    //
    template <typename T>
    struct real_value_traits
    {
      typedef T value_type;
      typedef T query_type;
      typedef double image_type;

      static void
      set_value (T& v, double i, bool is_null)
      {
        if (!is_null)
          v = T (i);
        else
          v = std::numeric_limits<T>::quiet_NaN ();
      }

      static void
      set_image (double& i, bool& is_null, T v)
      {
        is_null = false;
        i = image_type (v);
      }
    };

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<float, id_real>:
      real_value_traits<float>
    {
    };

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<double, id_real>:
      real_value_traits<double>
    {
    };

    // std::string specialization.
    //
    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<std::string, id_text>
    {
      typedef std::string value_type;
      typedef std::string query_type;
      typedef details::buffer image_type;

      static void
      set_value (std::string& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          v.assign (b.data (), n);
        else
          v.erase ();
      }

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const std::string&);
    };

    // char*/const char* specialization
    //
    // Specialization for const char* which only supports initialization
    // of an image from the value but not the other way around. This way
    // we can pass such values to the queries.
    //
    struct LIBODB_SQLITE_EXPORT c_string_value_traits
    {
      typedef const char* value_type;
      typedef details::buffer image_type;

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const char*);
    };

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<char*, id_text>:
      c_string_value_traits {};

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<const char*, id_text>:
      c_string_value_traits {};

    // char[N] specialization.
    //
    struct LIBODB_SQLITE_EXPORT c_array_value_traits_base
    {
      static void
      set_value (char* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null,
                 std::size_t N);

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const char* v,
                 std::size_t N);
    };

    template <std::size_t N>
    struct default_value_traits<char[N], id_text>
    {
      typedef char* value_type;
      typedef char query_type[N];
      typedef details::buffer image_type;

      static void
      set_value (char* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_array_value_traits_base::set_value (v, b, n, is_null, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const char* v)
      {
        c_array_value_traits_base::set_image (b, n, is_null, v, N);
      }
    };

    // std::array<char, N> (string) specialization.
    //
#ifdef ODB_CXX11
    template <std::size_t N>
    struct default_value_traits<std::array<char, N>, id_text>
    {
      typedef std::array<char, N> value_type;
      typedef std::array<char, N> query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_array_value_traits_base::set_value (v.data (), b, n, is_null, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const value_type& v)
      {
        c_array_value_traits_base::set_image (b, n, is_null, v.data (), N);
      }
    };
#endif

    // char specialization.
    //
    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<char, id_text>
    {
      typedef char value_type;
      typedef char query_type;
      typedef details::buffer image_type;

      static void
      set_value (char& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_array_value_traits_base::set_value (&v, b, n, is_null, 1);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 char v)
      {
        c_array_value_traits_base::set_image (b, n, is_null, &v, 1);
      }
    };

#ifdef _WIN32
    // std::wstring specialization. Using UTF-16 binding.
    //
    struct wstring_image_traits
    {
      typedef details::buffer image_type;
      static const bind::buffer_type bind_value = bind::text16;
    };

    template <>
    struct image_traits<std::wstring, id_text>: wstring_image_traits {};

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<std::wstring, id_text>
    {
      typedef std::wstring value_type;
      typedef std::wstring query_type;
      typedef details::buffer image_type;

      static void
      set_value (std::wstring& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          v.assign (reinterpret_cast<const wchar_t*> (b.data ()), n / 2);
        else
          v.erase ();
      }

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const std::wstring&);
    };

    // wchar_t*/const wchar_t* specialization.
    //
    struct LIBODB_SQLITE_EXPORT c_wstring_value_traits
    {
      typedef const wchar_t* value_type;
      typedef details::buffer image_type;

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const wchar_t*);
    };

    template <>
    struct image_traits<wchar_t*, id_text>: wstring_image_traits {};

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<wchar_t*, id_text>:
      c_wstring_value_traits {};

    template <>
    struct image_traits<const wchar_t*, id_text>: wstring_image_traits {};

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<const wchar_t*, id_text>:
      c_wstring_value_traits {};

    // wchar_t[N] specialization.
    //
    struct LIBODB_SQLITE_EXPORT c_warray_value_traits_base
    {
      static void
      set_value (wchar_t* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null,
                 std::size_t N);

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const wchar_t* v,
                 std::size_t N);
    };

    template <std::size_t N>
    struct image_traits<wchar_t[N], id_text>: wstring_image_traits {};

    template <std::size_t N>
    struct default_value_traits<wchar_t[N], id_text>
    {
      typedef wchar_t* value_type;
      typedef wchar_t query_type[N];
      typedef details::buffer image_type;

      static void
      set_value (wchar_t* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_warray_value_traits_base::set_value (v, b, n, is_null, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const wchar_t* v)
      {
        c_warray_value_traits_base::set_image (b, n, is_null, v, N);
      }
    };

    // std::array<wchar_t, N> (string) specialization.
    //
#ifdef ODB_CXX11
    template <std::size_t N>
    struct image_traits<std::array<wchar_t, N>, id_text>:
      wstring_image_traits {};

    template <std::size_t N>
    struct default_value_traits<std::array<wchar_t, N>, id_text>
    {
      typedef std::array<wchar_t, N> value_type;
      typedef std::array<wchar_t, N> query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_warray_value_traits_base::set_value (v.data (), b, n, is_null, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const value_type& v)
      {
        c_warray_value_traits_base::set_image (b, n, is_null, v.data (), N);
      }
    };
#endif

    // wchar_t specialization.
    //
    template <>
    struct image_traits<wchar_t, id_text>: wstring_image_traits {};

    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<wchar_t, id_text>
    {
      typedef wchar_t value_type;
      typedef wchar_t query_type;
      typedef details::buffer image_type;

      static void
      set_value (wchar_t& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        c_warray_value_traits_base::set_value (&v, b, n, is_null, 1);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 wchar_t v)
      {
        c_warray_value_traits_base::set_image (b, n, is_null, &v, 1);
      }
    };
#endif // _WIN32

    // std::vector<char> (buffer) specialization.
    //
    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<
      std::vector<char>, id_blob>
    {
    public:
      typedef std::vector<char> value_type;
      typedef std::vector<char> query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          v.assign (b.data (), b.data () + n);
        else
          v.clear ();
      }

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const value_type&);
    };

    // std::vector<unsigned char> (buffer) specialization.
    //
    template <>
    struct LIBODB_SQLITE_EXPORT default_value_traits<
      std::vector<unsigned char>, id_blob>
    {
    public:
      typedef std::vector<unsigned char> value_type;
      typedef std::vector<unsigned char> query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
        {
          const unsigned char* d (
            reinterpret_cast<const unsigned char*> (b.data ()));
          v.assign (d, d + n);
        }
        else
          v.clear ();
      }

      static void
      set_image (details::buffer&,
                 std::size_t& n,
                 bool& is_null,
                 const value_type&);
    };

    // char[N] (buffer) specialization.
    //
    template <std::size_t N>
    struct default_value_traits<char[N], id_blob>
    {
    public:
      typedef char* value_type;
      typedef char query_type[N];
      typedef details::buffer image_type;

      static void
      set_value (char* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          std::memcpy (v, b.data (), (n < N ? n : N));
        else
          std::memset (v, 0, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const char* v)
      {
        is_null = false;
        n = N;

        if (n > b.capacity ())
          b.capacity (n);

        std::memcpy (b.data (), v, n);
      }
    };

    // unsigned char[N] (buffer) specialization.
    //
    template <std::size_t N>
    struct default_value_traits<unsigned char[N], id_blob>
    {
    public:
      typedef unsigned char* value_type;
      typedef unsigned char query_type[N];
      typedef details::buffer image_type;

      static void
      set_value (unsigned char* const& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          std::memcpy (v, b.data (), (n < N ? n : N));
        else
          std::memset (v, 0, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const unsigned char* v)
      {
        is_null = false;
        n = N;

        if (n > b.capacity ())
          b.capacity (n);

        std::memcpy (b.data (), v, n);
      }
    };

#ifdef ODB_CXX11
    // std::array<char, N> (buffer) specialization.
    //
    template <std::size_t N>
    struct default_value_traits<std::array<char, N>, id_blob>
    {
    public:
      typedef std::array<char, N> value_type;
      typedef value_type query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          std::memcpy (v.data (), b.data (), (n < N ? n : N));
        else
          std::memset (v.data (), 0, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const value_type& v)
      {
        is_null = false;
        n = N;

        if (n > b.capacity ())
          b.capacity (n);

        std::memcpy (b.data (), v.data (), n);
      }
    };

    // std::array<unsigned char, N> (buffer) specialization.
    //
    template <std::size_t N>
    struct default_value_traits<std::array<unsigned char, N>, id_blob>
    {
    public:
      typedef std::array<unsigned char, N> value_type;
      typedef value_type query_type;
      typedef details::buffer image_type;

      static void
      set_value (value_type& v,
                 const details::buffer& b,
                 std::size_t n,
                 bool is_null)
      {
        if (!is_null)
          std::memcpy (v.data (), b.data (), (n < N ? n : N));
        else
          std::memset (v.data (), 0, N);
      }

      static void
      set_image (details::buffer& b,
                 std::size_t& n,
                 bool& is_null,
                 const value_type& v)
      {
        is_null = false;
        n = N;

        if (n > b.capacity ())
          b.capacity (n);

        std::memcpy (b.data (), v.data (), n);
      }
    };
#endif

    //
    // type_traits
    //

    template <typename T>
    struct default_type_traits;

    template <typename T>
    class type_traits: public default_type_traits<T> {};

    // Integral types.
    //
    template <>
    struct default_type_traits<bool>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<signed char>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<unsigned char>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<short>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<unsigned short>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<int>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<unsigned int>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<long>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<unsigned long>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<long long>
    {
      static const database_type_id db_type_id = id_integer;
    };

    template <>
    struct default_type_traits<unsigned long long>
    {
      static const database_type_id db_type_id = id_integer;
    };

    // Float types.
    //
    template <>
    struct default_type_traits<float>
    {
      static const database_type_id db_type_id = id_real;
    };

    template <>
    struct default_type_traits<double>
    {
      static const database_type_id db_type_id = id_real;
    };

    // String types.
    //
    template <>
    struct default_type_traits<std::string>
    {
      static const database_type_id db_type_id = id_text;
    };

    template <>
    struct default_type_traits<char*>
    {
      static const database_type_id db_type_id = id_text;
    };

    template <>
    struct default_type_traits<const char*>
    {
      static const database_type_id db_type_id = id_text;
    };

    template <std::size_t N>
    struct default_type_traits<char[N]>
    {
      static const database_type_id db_type_id = id_text;
    };

#ifdef ODB_CXX11
    template <std::size_t N>
    struct default_type_traits<std::array<char, N> >
    {
      static const database_type_id db_type_id = id_text;
    };
#endif

    template <>
    struct default_type_traits<char>
    {
      static const database_type_id db_type_id = id_text;
    };

    // Binary types.
    //
    template <std::size_t N>
    struct default_type_traits<unsigned char[N]>
    {
      static const database_type_id db_type_id = id_blob;
    };

    template <>
    struct default_type_traits<std::vector<char> >
    {
      static const database_type_id db_type_id = id_blob;
    };

    template <>
    struct default_type_traits<std::vector<unsigned char> >
    {
      static const database_type_id db_type_id = id_blob;
    };

#ifdef ODB_CXX11
    template <std::size_t N>
    struct default_type_traits<std::array<unsigned char, N> >
    {
      static const database_type_id db_type_id = id_blob;
    };
#endif
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_TRAITS_HXX
