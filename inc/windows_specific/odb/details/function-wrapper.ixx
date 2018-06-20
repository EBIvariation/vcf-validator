// file      : odb/details/function-wrapper.ixx
// copyright : Copyright (c) 2009-2014 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace details
  {
    template <typename F>
    inline function_wrapper<F>::
    ~function_wrapper ()
    {
      if (deleter != 0)
        deleter (std_function);
    }

    template <typename F>
    inline function_wrapper<F>::
    function_wrapper (F* f)
        : function (f), deleter (0), std_function (0)
    {
    }

    template <typename F>
    inline function_wrapper<F>::
    function_wrapper (const function_wrapper<F>& x)
        : function (0), deleter (0), std_function (0)
    {
      swap (const_cast<function_wrapper<F>&> (x));
    }

    template <typename F>
    inline function_wrapper<F>& function_wrapper<F>::
    operator= (const function_wrapper<F>& x)
    {
      swap (const_cast<function_wrapper<F>&> (x));
      return *this;
    }

    template <typename F>
    inline function_wrapper<F>::
    operator bool_convertible () const
    {
      return function != 0 ? &function_wrapper<F>::true_value : 0;
    }
  }
}
