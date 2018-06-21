// file      : odb/vector.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_VECTOR_HXX
#define ODB_VECTOR_HXX

#include <odb/pre.hxx>
#include <odb/details/config.hxx> // ODB_CXX11

#include <vector>
#include <iterator>
#include <cstddef>  // std::ptrdiff_t

#ifdef ODB_CXX11
#  include <utility>          // std::move, std::forward
#  ifdef ODB_CXX11_INITIALIZER_LIST
#    include <initializer_list>
#  endif
#endif

#include <odb/vector-impl.hxx>

// Because both std::vector and odb::vector are called 'vector' (who
// cares about namespace qualifications, right?), Sun CC complains
// with a bogus "Ambiguous partial specialization" error. A really
// hideous workaround for this bug is to to add a dummy third template
// argument (with a default value).
//
#ifdef __SUNPRO_CC
#  define LIBODB_VECTOR_ARG_DEFAULT ,int = 0
#  define LIBODB_VECTOR_ARG_DECL ,int DUMMY
#  define LIBODB_VECTOR_ARG_USE ,DUMMY
#else
#  define LIBODB_VECTOR_ARG_DEFAULT
#  define LIBODB_VECTOR_ARG_DECL
#  define LIBODB_VECTOR_ARG_USE
#endif

namespace odb
{
  // An std::vector-like container that keeps track of changes.
  //
  // Note that the style and order of definitions is as appears
  // in the standard.
  //
  template <class V, class I>
  class vector_iterator;

  template <class T, class A = std::allocator<T> LIBODB_VECTOR_ARG_DEFAULT>
  class vector: public vector_base
  {
  public:
    typedef std::vector<T, A>                   base_vector_type;
    typedef typename base_vector_type::iterator base_iterator_type;
    typedef typename base_vector_type::reverse_iterator
                                                base_reverse_iterator_type;
    // types:
    //
    typedef typename base_vector_type::reference        reference;
    typedef typename base_vector_type::const_reference  const_reference;
    typedef vector_iterator<vector, base_iterator_type> iterator;
    typedef typename base_vector_type::const_iterator   const_iterator;
    typedef typename base_vector_type::size_type        size_type;
    typedef typename base_vector_type::difference_type  difference_type;
    typedef T                                           value_type;
    typedef A                                           allocator_type;
    typedef typename base_vector_type::pointer          pointer;
    typedef typename base_vector_type::const_pointer    const_pointer;
    // No non-const reverse iterator support for Sun CC with non-standard STL.
    //
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
    typedef vector_iterator<vector, base_reverse_iterator_type>
                                                        reverse_iterator;
#endif
    typedef typename base_vector_type::const_reverse_iterator
                                                        const_reverse_iterator;
    // construct/copy/destroy:
    //
    explicit vector(const A& a = A()): v_ (a) {}
    explicit vector(size_type n): v_ (n) {} // C++11
    vector(size_type n, const T& v, const A& a = A()): v_ (n, v, a) {}
    template <class I>
    vector(I f, I l, const A& a = A()) : v_ (f, l, a) {}
    vector(const vector& x): vector_base (x), v_ (x.v_) {}
    // ~vector() {}
    vector& operator=(const vector&);
    template <class I>
    void assign(I f, I l);
    void assign(size_type n, const T& u);
    allocator_type get_allocator() const /*noexcept*/
    {return v_.get_allocator ();}

#ifdef ODB_CXX11
    vector(vector&& x): vector_base (std::move (x)), v_ (std::move (x.v_)) {}
    vector(const vector& x, const A& a): vector_base (x), v_ (x.v_, a) {}
    vector(vector&& x, const A& a)
        : vector_base (std::move (x)), v_ (std::move (x.v_), a) {}
    vector& operator=(vector&&);
#ifdef ODB_CXX11_INITIALIZER_LIST
    vector(std::initializer_list<T> il, const A& a = A()): v_ (il, a) {}
    vector& operator=(std::initializer_list<T>);
    void assign(std::initializer_list<T>);
#endif
#endif

    // iterators: (all /*noexcept*/)
    //
    iterator               begin() {return iterator (this, v_.begin ());}
    iterator               end() {return iterator (this, v_.end ());}
    const_iterator         begin() const {return v_.begin ();}
    const_iterator         end() const {return v_.end ();}
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
    reverse_iterator       rbegin() {return reverse_iterator (this, v_.rbegin ());}
    reverse_iterator       rend() {return reverse_iterator (this, v_.rend ());}
#endif
    const_reverse_iterator rbegin() const {return v_.rbegin ();}
    const_reverse_iterator rend() const {return v_.rend ();}

    // Return standard vector iterators. The begin() functions mark all
    // the elements as modified.
    //
    base_iterator_type         mbegin ();
    base_iterator_type         mend () {return v_.end ();}
    base_reverse_iterator_type mrbegin ();
    base_reverse_iterator_type mrend () {return v_.rend ();}

#ifdef ODB_CXX11
    const_iterator         cbegin() const {return v_.cbegin ();}
    const_iterator         cend() const {return v_.cend ();}
    const_reverse_iterator crbegin() const {return v_.crbegin ();}
    const_reverse_iterator crend() const {return v_.crend ();}
#endif

    // capacity:
    //
    size_type size() const /*noexcept*/ {return v_.size ();}
    size_type max_size() const /*noexcept*/ {return v_.max_size ();}
    void      resize(size_type); // C++11
    void      resize(size_type, const T&);
    size_type capacity() const /*noexcept*/ {return v_.capacity ();}
    bool      empty() const /*noexcept*/ {return v_.empty ();}
    void      reserve(size_type);

#ifdef ODB_CXX11
    void shrink_to_fit();
#endif

    // element access:
    //
    //reference        operator[](size_type n);
    reference          modify(size_type n);
    const_reference    operator[](size_type n) const {return v_[n];}
    //reference        at(size_type n);
    reference          modify_at(size_type n);
    const_reference    at(size_type n) const {return v_.at (n);}
    //reference        front();
    reference          modify_front();
    const_reference    front() const {return v_.front ();}
    //reference        back();
    reference          modify_back();
    const_reference    back() const {return v_.back ();}

    // data access:
    //
#ifdef ODB_CXX11
    //T*        data() noexcept;
    T*        modify_data() /*noexcept*/;
    const T*  data() const /*noexcept*/ {return v_.data ();}
#endif

    // modifiers:
    //
    void push_back(const T& x);
    void pop_back();
    iterator insert(iterator position, const T& x);
    void     insert(iterator position, size_type n, const T& x);
    template <class I>
    void insert(iterator position, I first, I last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void     swap(vector&);
    void     clear() /*noexcept*/;

#ifdef ODB_CXX11
    // In C++11 all modifiers use const_iterator instead of iterator
    // to represent position. However, some standard libraries (notably
    // GCC's) still use iterator and so we will do that as well, for now.
    //
    void push_back(T&& x);
    iterator insert(iterator position, T&& x);

#ifdef ODB_CXX11_VARIADIC_TEMPLATE
    template <class... Args>
    void emplace_back(Args&&... args);
    template <class... Args>
    iterator emplace(iterator position, Args&&... args);
#endif
#endif

    // Interfacing with the base vector.
    //
    vector (const base_vector_type& x): v_ (x) {}
    vector& operator= (const base_vector_type&);
    operator const base_vector_type& () const {return v_;}
    base_vector_type& base () {return v_;}
    const base_vector_type& base () const {return v_;}

#ifdef ODB_CXX11
    vector (base_vector_type&& x): v_ (std::move (x)) {}
    vector& operator= (base_vector_type&&);
#endif

    // Change tracking (the rest comes from vector_base).
    //
  public:
    void
    _start () const {impl_.start (v_.size ());}

  private:
    base_vector_type v_;
  };

  namespace core
  {
    using odb::vector;
  }

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator==(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () == y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator==(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const std::vector<T,A>& y)
  {return x.base () == y;}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator==(const std::vector<T,A>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x == y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator< (const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () < y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator<(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                        const std::vector<T,A>& y)
  {return x.base () < y;}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator<(const std::vector<T,A>& x,
                        const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x < y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator!=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () != y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator!=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const std::vector<T,A>& y)
  {return x.base () != y;}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator!=(const std::vector<T,A>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x != y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator> (const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () > y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator>=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () >= y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator>=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const std::vector<T,A>& y)
  {return x.base () >= y;}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator>=(const std::vector<T,A>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x >= y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator<=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x.base () <= y.base ();}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator<=(const vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                         const std::vector<T,A>& y)
  {return x.base () <= y;}

  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline bool operator<=(const std::vector<T,A>& x,
                         const vector<T,A LIBODB_VECTOR_ARG_USE>& y)
  {return x <= y.base ();}

  template <class V, class I>
  class vector_iterator
  {
  public:
    typedef V vector_type;
    typedef I base_iterator_type;
    typedef typename vector_type::const_iterator const_iterator_type;

    // Sun CC with non-standard STL does not have iterator_traits.
    //
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
    typedef std::iterator_traits<base_iterator_type> base_iterator_traits;

    typedef typename base_iterator_traits::value_type value_type;
    typedef typename base_iterator_traits::difference_type difference_type;
    typedef typename base_iterator_traits::pointer pointer;
    typedef typename base_iterator_traits::reference reference;
    typedef typename base_iterator_traits::iterator_category iterator_category;
#else
    // Base iterator is just a pointer.
    //
    typedef typename vector_type::value_type value_type;
    typedef typename vector_type::pointer pointer;
    typedef typename vector_type::reference reference;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
#endif

    typedef typename vector_type::size_type size_type;
    typedef typename vector_type::const_reference const_reference;
    typedef typename vector_type::const_pointer const_pointer;

    vector_iterator (): v_ (0), i_ () {}
    vector_iterator (vector_type* v, const base_iterator_type& i)
        : v_ (v), i_ (i) {}
    operator const_iterator_type () const {return i_;}
    base_iterator_type base () const {return i_;}
    vector_type* vector () const {return v_;}

    // Note: const_{reference,pointer}.
    //
    const_reference operator* () const {return *i_;}
    const_pointer   operator-> () const {return i_.operator -> ();}
    const_reference operator[] (difference_type n) const {return i_[n];}

    // Modifiers.
    //
    // Buggy Sun CC cannot have them out of class.
    //
    reference modify () const
    {
      if (v_->_tracking ())
        v_->_impl ().modify (
          static_cast<size_type> (i_ - v_->base ().begin ()));
      return *i_;
    }

    reference modify (difference_type n) const
    {
      if (v_->_tracking ())
        v_->_impl ().modify (
          static_cast<size_type> (i_ - v_->base ().begin () + n));
      return i_[n];
    }

    vector_iterator& operator++ () {++i_; return *this;}
    vector_iterator  operator++ (int) {return vector_iterator (v_, i_++);}
    vector_iterator& operator-- () {--i_; return *this;}
    vector_iterator  operator-- (int) {return vector_iterator (v_, i_--);}

    vector_iterator operator+ (difference_type n) const
    {return vector_iterator (v_, i_ + n);}
    vector_iterator& operator+= (difference_type n) {i_ += n; return *this;}
    vector_iterator operator- (difference_type n) const
    {return vector_iterator (v_, i_ - n);}
    vector_iterator& operator-= (difference_type n) {i_ -= n; return *this;}

    // Implementation details.
    //
  public:
    base_iterator_type _base () const {return i_;} // Same as base ().

  private:
    vector_type* v_;
    base_iterator_type i_;
  };

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
  template <class V, class J>
  class vector_iterator<V, std::reverse_iterator<J> >
  {
  public:
    typedef V vector_type;
    typedef std::reverse_iterator<J> base_iterator_type;
    typedef typename vector_type::const_reverse_iterator const_iterator_type;
    typedef std::iterator_traits<base_iterator_type> base_iterator_traits;

    typedef typename vector_type::iterator iterator_type;
    typedef typename base_iterator_traits::value_type value_type;
    typedef typename base_iterator_traits::difference_type difference_type;
    typedef typename base_iterator_traits::pointer pointer;
    typedef typename base_iterator_traits::reference reference;
    typedef typename base_iterator_traits::iterator_category iterator_category;

    typedef typename vector_type::size_type size_type;
    typedef typename vector_type::const_reference const_reference;
    typedef typename vector_type::const_pointer const_pointer;

    vector_iterator (): v_ (0), i_ () {}
    explicit vector_iterator (const iterator_type& i)
        : v_ (i.vector ()), i_ (i.base ()) {}
    vector_iterator (vector_type* v, const base_iterator_type& i)
        : v_ (v), i_ (i) {}
    operator const_iterator_type () const {return i_;}
    iterator_type base () const {return iterator_type (v_, i_.base ());}
    base_iterator_type rbase () const {return i_;}
    vector_type* vector () const {return v_;}

    // Note: const_{reference,pointer}.
    //
    const_reference operator* () const {return *i_;}
    const_pointer   operator-> () const {return i_.operator -> ();}
    const_reference operator[] (difference_type n) const {return i_[n];}

    // Modifiers.
    //
    reference modify () const
    {
      if (v_->_tracking ())
        v_->_impl ().modify (
          static_cast<size_type> (v_->base ().rend () - i_ - 1));
      return *i_;
    }

    reference modify (difference_type n) const
    {
      if (v_->_tracking ())
        // Note: going in the opposite direction.
        v_->_impl ().modify (
          static_cast<size_type> (v_->base ().rend () - i_ - 1 - n));
      return i_[n];
    }

    vector_iterator& operator++ () {++i_; return *this;}
    vector_iterator  operator++ (int) {return vector_iterator (v_, i_++);}
    vector_iterator& operator-- () {--i_; return *this;}
    vector_iterator  operator-- (int) {return vector_iterator (v_, i_--);}

    vector_iterator operator+ (difference_type n) const
    {return vector_iterator (v_, i_ + n);}
    vector_iterator& operator+= (difference_type n) {i_ += n; return *this;}
    vector_iterator operator- (difference_type n) const
    {return vector_iterator (v_, i_ - n);}
    vector_iterator& operator-= (difference_type n) {i_ -= n; return *this;}

    // Implementation details.
    //
  public:
    base_iterator_type _base () const {return i_;} // Same as rbase().

  private:
    vector_type* v_;
    base_iterator_type i_;
  };
#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC

  // operator==
  //
  template <class V, class I>
  inline bool
  operator== (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () == y._base ();}

  template <class V, class I>
  inline bool
  operator== (const vector_iterator<V, I>& x,
              const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () == y;}

  template <class V, class I>
  inline bool
  operator== (const typename vector_iterator<V, I>::const_iterator_type& x,
              const vector_iterator<V, I>& y)
  {return x == y._base ();}

  // operator<
  //
  template <class V, class I>
  inline bool
  operator< (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () < y._base ();}

  template <class V, class I>
  inline bool
  operator< (const vector_iterator<V, I>& x,
             const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () < y;}

  template <class V, class I>
  inline bool
  operator< (const typename vector_iterator<V, I>::const_iterator_type& x,
             const vector_iterator<V, I>& y)
  {return x < y._base ();}

  // operator!=
  //
  template <class V, class I>
  inline bool
  operator!= (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () != y._base ();}

  template <class V, class I>
  inline bool
  operator!= (const vector_iterator<V, I>& x,
              const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () != y;}

  template <class V, class I>
  inline bool
  operator!= (const typename vector_iterator<V, I>::const_iterator_type& x,
              const vector_iterator<V, I>& y)
  {return x != y._base ();}

  // operator>
  //
  template <class V, class I>
  inline bool
  operator> (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () > y._base ();}

  template <class V, class I>
  inline bool
  operator> (const vector_iterator<V, I>& x,
              const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () > y;}

  template <class V, class I>
  inline bool
  operator> (const typename vector_iterator<V, I>::const_iterator_type& x,
              const vector_iterator<V, I>& y)
  {return x > y._base ();}

  // operator>=
  //
  template <class V, class I>
  inline bool
  operator>= (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () >= y._base ();}

  template <class V, class I>
  inline bool
  operator>= (const vector_iterator<V, I>& x,
              const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () >= y;}

  template <class V, class I>
  inline bool
  operator>= (const typename vector_iterator<V, I>::const_iterator_type& x,
              const vector_iterator<V, I>& y)
  {return x >= y._base ();}

  // operator<=
  //
  template <class V, class I>
  inline bool
  operator<= (const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () <= y._base ();}

  template <class V, class I>
  inline bool
  operator<= (const vector_iterator<V, I>& x,
              const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () <= y;}

  template <class V, class I>
  inline bool
  operator<= (const typename vector_iterator<V, I>::const_iterator_type& x,
              const vector_iterator<V, I>& y)
  {return x <= y._base ();}

  // operator-
  //
  template <class V, class I>
  inline typename vector_iterator<V, I>::difference_type
  operator-(const vector_iterator<V, I>& x, const vector_iterator<V, I>& y)
  {return x._base () - y._base ();}

  template <class V, class I>
  inline typename vector_iterator<V, I>::difference_type
  operator-(const vector_iterator<V, I>& x,
            const typename vector_iterator<V, I>::const_iterator_type& y)
  {return x._base () - y;}

  template <class V, class I>
  inline typename vector_iterator<V, I>::difference_type
  operator-(const typename vector_iterator<V, I>::const_iterator_type& x,
            const vector_iterator<V, I>& y)
  {return x - y._base ();}

  // operator+
  //
  template <class V, class I>
  inline vector_iterator<V, I>
  operator+(typename vector_iterator<V, I>::difference_type n,
            const vector_iterator<V, I>& x)
  {return vector_iterator<V, I> (x.vector (), n + x._base ());}
}

namespace std
{
  template <class T, class A LIBODB_VECTOR_ARG_DECL>
  inline void swap(odb::vector<T,A LIBODB_VECTOR_ARG_USE>& x,
                   odb::vector<T,A LIBODB_VECTOR_ARG_USE>& y) {x.swap (y);}
}

#include <odb/vector.ixx>

#include <odb/vector-traits.hxx>

#include <odb/post.hxx>

#endif // ODB_VECTOR_HXX
