// file      : odb/details/win32/dll.cxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

// If we are building a static library from VC++ (LIBODB_STATIC_LIB) or
// a static library from automake (!DLL_EXPORT), then omit DllMain.
//

#if (defined(_MSC_VER) && defined(LIBODB_DYNAMIC_LIB)) || \
    (!defined(_MSC_VER) && defined(DLL_EXPORT))

#include <odb/details/win32/windows.hxx>
#include <odb/details/win32/init.hxx>

using namespace odb::details;

extern "C" BOOL WINAPI
DllMain (HINSTANCE, DWORD reason, LPVOID reserved)
{
  switch (reason)
  {
  case DLL_PROCESS_ATTACH:
    {
      process_start ();
      thread_start ();
      break;
    }

  case DLL_THREAD_ATTACH:
    {
      thread_start ();
      break;
    }

  case DLL_THREAD_DETACH:
    {
      thread_end ();
      break;
    }

  case DLL_PROCESS_DETACH:
    {
      thread_end ();
      process_end (reserved == NULL);
      break;
    }
  }

  return 1;
}

#endif
