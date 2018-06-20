// file      : odb/sqlite/traits.cxx
// copyright : Copyright (c) 2005-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/sqlite/traits.hxx>

using namespace std;

namespace odb
{
  namespace sqlite
  {
    using details::buffer;

    //
    // default_value_traits<std::string>
    //
    void default_value_traits<string, id_text>::
    set_image (buffer& b, size_t& n, bool& is_null, const string& v)
    {
      is_null = false;
      n = v.size ();

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v.c_str (), n);
    }

    //
    // c_string_value_traits
    //
    void c_string_value_traits::
    set_image (buffer& b, size_t& n, bool& is_null, const char* v)
    {
      is_null = false;
      n = strlen (v);

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v, n);
    }

    //
    // c_array_value_traits_base
    //
    void c_array_value_traits_base::
    set_value (char* const& v,
               const details::buffer& b,
               size_t n,
               bool is_null,
               size_t N)
    {
      if (!is_null)
      {
        n = n < N ? n : N;

        if (n != 0)
          memcpy (v, b.data (), n);
      }
      else
        n = 0;

      if (n != N) // Append '\0' if there is space.
        v[n] = '\0';
    }

    void c_array_value_traits_base::
    set_image (details::buffer& b,
               size_t& n,
               bool& is_null,
               const char* v,
               size_t N)
    {
      is_null = false;

      // Figure out the length. We cannot use strlen since it may
      // not be 0-terminated (strnlen is not standard).
      //
      for (n = 0; n != N && v[n] != '\0'; ++n) ;

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v, n);
    }

    //
    // default_value_traits<std::wstring>
    //
#ifdef _WIN32
    void default_value_traits<wstring, id_text>::
    set_image (buffer& b, size_t& n, bool& is_null, const wstring& v)
    {
      is_null = false;
      n = v.size () * 2;

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v.c_str (), n);
    }

    //
    // c_wstring_value_traits
    //
    void c_wstring_value_traits::
    set_image (buffer& b, size_t& n, bool& is_null, const wchar_t* v)
    {
      is_null = false;
      n = wcslen (v) * 2;

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v, n);
    }

    //
    // c_warray_value_traits_base
    //
    void c_warray_value_traits_base::
    set_value (wchar_t* const& v,
               const details::buffer& b,
               size_t n,
               bool is_null,
               size_t N)
    {
      if (!is_null)
      {
        n /= 2;
        n = n < N ? n : N;

        if (n != 0)
          memcpy (v, b.data (), n * sizeof (wchar_t));
      }
      else
        n = 0;

      if (n != N) // Append '\0' if there is space.
        v[n] = L'\0';
    }

    void c_warray_value_traits_base::
    set_image (details::buffer& b,
               size_t& n,
               bool& is_null,
               const wchar_t* v,
               size_t N)
    {
      is_null = false;

      // Figure out the length. We cannot use wcslen since it may
      // not be 0-terminated (wcsnlen is not standard).
      //
      for (n = 0; n != N && v[n] != L'\0'; ++n) ;

      n *= 2;

      if (n > b.capacity ())
        b.capacity (n);

      if (n != 0)
        memcpy (b.data (), v, n);
    }
#endif // _WIN32

    //
    // default_value_traits<vector<char>, id_blob>
    //
    // std::vector has to be qualified for Sun CC.
    //
    void default_value_traits<std::vector<char>, id_blob>::
    set_image (details::buffer& b,
               size_t& n,
               bool& is_null,
               const value_type& v)
    {
      is_null = false;
      n = v.size ();

      if (n > b.capacity ())
        b.capacity (n);

      // std::vector::data() may not be available in older compilers.
      //
      if (n != 0)
        memcpy (b.data (), &v.front (), n);
    }

    //
    // default_value_traits<vector<unsigned char>, id_blob>
    //
    // std::vector has to be qualified for Sun CC.
    //
    void default_value_traits<std::vector<unsigned char>, id_blob>::
    set_image (details::buffer& b,
               size_t& n,
               bool& is_null,
               const value_type& v)
    {
      is_null = false;
      n = v.size ();

      if (n > b.capacity ())
        b.capacity (n);

      // std::vector::data() may not be available in older compilers.
      //
      if (n != 0)
        memcpy (b.data (), &v.front (), n);
    }
  }
}
