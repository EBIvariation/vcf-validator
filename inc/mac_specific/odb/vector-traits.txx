// file      : odb/vector-traits.txx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  template <typename V, typename A LIBODB_VECTOR_ARG_DECL>
  bool access::container_traits<vector<V, A LIBODB_VECTOR_ARG_USE> >::
  changed (const container_type& c)
  {
    // Because modifications can cancel each other (e.g., push and pop),
    // it is tricky to keep track of whether there are any changes in
    // the container. Instead, we are just going to examine each element
    // just like update().
    //

    // We should either be tracking or summarily changed.
    //
    if (c._tracking ())
    {
      const vector_impl& impl (c._impl ());

      for (std::size_t i (0), n (impl.size ()); i < n; ++i)
      {
        if (impl.state (i) != vector_impl::state_unchanged)
          return true;
      }
    }
    else
      return true;

    return false;
  }

  template <typename V, typename A LIBODB_VECTOR_ARG_DECL>
  void access::container_traits<vector<V, A LIBODB_VECTOR_ARG_USE> >::
  update (const container_type& c, const functions& f)
  {
    bool u (false); // Updated flag.

    if (c._tracking ())
    {
      const vector_impl& impl (c._impl ());

      for (std::size_t i (0), n (impl.size ()); i < n; ++i)
      {
        vector_impl::element_state_type s (impl.state (i));

        switch (s)
        {
        case vector_impl::state_unchanged:
          {
            break;
          }
        case vector_impl::state_inserted:
          {
            f.insert (i, c[static_cast<index_type> (i)]);
            u = u || true;
            break;
          }
        case vector_impl::state_updated:
          {
            f.update (i, c[static_cast<index_type> (i)]);
            u = u || true;
            break;
          }
        case vector_impl::state_erased:
          {
            f.delete_ (i); // Delete from i onwards.
            u = u || true;
            break;
          }
        }

        // We delete all trailing elements in one go.
        //
        if (s == vector_impl::state_erased)
          break;
      }
    }
    else
    {
      // Fall back to delete all/insert all.
      //
      f.delete_ (0);

      for (index_type i (0), n (c.size ()); i < n; ++i)
        f.insert (i, c[i]);

      u = true;
    }

    // Arm the rollback callback and (re)start change tracking.
    //
    if (u)
    {
      c._arm (transaction::current ());
      c._start ();
    }
  }
}
