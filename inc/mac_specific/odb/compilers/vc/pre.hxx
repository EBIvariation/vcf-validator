// file      : odb/compilers/vc/pre.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

// Push warning state.
//
#pragma warning (push, 3)

// Disabled warnings.
//
#pragma warning (disable:4068) // unknown pragma
#pragma warning (disable:4251) // needs to have DLL-interface
#pragma warning (disable:4290) // exception specification ignored
#pragma warning (disable:4355) // passing 'this' to a member
#pragma warning (disable:4800) // forcing value to bool
#pragma warning (disable:4231) // non-standard extension (extern template)

// Elevated warnings.
//
#pragma warning (2:4239) // standard doesn't allow this conversion
