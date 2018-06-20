// file      : odb/details/function-wrapper.txx
// copyright : Copyright (c) 2009-2014 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <utility> // std::swap, std::move

namespace odb
{
  namespace details
  {
#ifdef ODB_CXX11
    template <typename F>
    struct caller_impl;

#ifdef ODB_CXX11_VARIADIC_TEMPLATE
    template <typename R, typename... A>
    struct caller_impl<R (A...)>
    {
      static R
      function (const void* f, A... a)
      {
        return (*static_cast<const std::function<R (A...)>*> (f)) (a...);
      }
    };
#else
    template <typename R, typename A1>
    struct caller_impl<R (A1)>
    {
      static R
      function (const void* f, A1 a1)
      {
        return (*static_cast<const std::function<R (A1)>*> (f)) (a1);
      }
    };

    template <typename R, typename A1, typename A2>
    struct caller_impl<R (A1, A2)>
    {
      static R
      function (const void* f, A1 a1, A2 a2)
      {
        return (*static_cast<const std::function<R (A1, A2)>*> (f)) (a1, a2);
      }
    };
#endif

    template <typename F>
    void
    deleter_impl (const void* f)
    {
      delete static_cast<const std::function<F>*> (f);
    }

    template <typename F>
    template <typename F1>
    function_wrapper<F>::
    function_wrapper (
      F1 f,
      typename std::enable_if<!std::is_convertible<F1, F*>::value>::type*)
    {
      std_function_type sf (std::move (f));

      if (F* const* const f = sf.template target<F*> ())
      {
        function = *f;
        deleter = 0;
        std_function = 0;
      }
      else
      {
        function = reinterpret_cast<F*> (&caller_impl<F>::function);
        deleter = &deleter_impl<F>;
        std_function = new std_function_type (std::move (sf));
      }
    }
#endif

    template <typename F>
    void function_wrapper<F>::
    swap (function_wrapper<F>& x)
    {
      std::swap (function, x.function);
      std::swap (deleter, x.deleter);
      std::swap (std_function, x.std_function);
    }
  }
}
