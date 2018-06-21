// file      : odb/details/function-wrapper.hxx
// copyright : Copyright (c) 2009-2014 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_FUNCTION_WRAPPER_HXX
#define ODB_DETAILS_FUNCTION_WRAPPER_HXX

#include <odb/pre.hxx>

#include <odb/details/config.hxx> // ODB_CXX11

#ifdef ODB_CXX11
#  include <functional>  // std::function
#  include <type_traits> // std::enable_if, std::is_convertible
#endif

namespace odb
{
  namespace details
  {
    // Low-level 'callable object' wrapper similar to std::function but
    // that works in both C++98 and 11. In particular, the call site can
    // be compiled in C++98 and the registration site in C++11 and it
    // will work.
    //
    template <typename F>
    struct function_wrapper
    {
      ~function_wrapper ();

      explicit
      function_wrapper (F* = 0);

#ifdef ODB_CXX11
      typedef typename std::function<F> std_function_type;

      // This overload accepts lambdas and std::functions, but when the
      // argument is convertible to F*, then we disable it in favor of the
      // other overload (above), which is more efficient.
      //
      // Subtlety alert: if you're thinking of changing this to accept a
      // std::function<F> argument, stop. That creates an overload ambiguity
      // when the actual parameter is a lambda, which is convertible to either
      // std::function<F> or F*.
      //
      template <typename F1>
      function_wrapper(F1,
                       typename std::enable_if<
                       !std::is_convertible<F1, F*>::value>::type* = 0);
#endif

      // Destructive copy construction and assignment (aka move). These
      // should really only be called by containers when they need to
      // reallocate the underlying buffer and move the elements.
      //
      function_wrapper (const function_wrapper<F>&);
      function_wrapper&
      operator= (const function_wrapper<F>&);

      void swap (function_wrapper<F>&);

      // Conversion to bool.
      //
    public:
      typedef void (function_wrapper<F>::*bool_convertible) ();
      void true_value () {}

      operator bool_convertible () const;

    public:
      F* function;
      void (*deleter) (const void*);
      const void* std_function;
    };
  }
}

#include <odb/details/function-wrapper.ixx>
#include <odb/details/function-wrapper.txx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_FUNCTION_WRAPPER_HXX
