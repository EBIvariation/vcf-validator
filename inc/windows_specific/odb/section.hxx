// file      : odb/section.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SECTION_HXX
#define ODB_SECTION_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>
#include <odb/details/export.hxx>

namespace odb
{
  class LIBODB_EXPORT section
  {
  public:
    // Load state.
    //
    bool
    loaded () const {return state_.loaded;}

    // Mark a loaded section as not loaded. This, for example, can be
    // useful if you don't want the section to be reloaded during the
    // object reload.
    //
    void
    unload ()
    {
      state_.loaded = 0;
      state_.changed = 0;
      state_.restore = 0;
    }

    // Change state.
    //
    bool
    changed () const {return state_.changed;}

    // Mark the section as changed.
    //
    void
    change ()
    {
      state_.changed = 1;
      state_.restore = 0;
    }

    // User data. 4 bits of custom state.
    //
    unsigned char
    user_data () const {return state_.user;}

    void
    user_data (unsigned char u) {state_.user = u;}

  public:
    section ()
    {
      state_.loaded = 0;
      state_.changed = 0;
      state_.armed = 0;
      state_.restore = 0;
    }

    ~section ()
    {
      if (state_.armed)
        disarm ();
    }

    // Implementation details.
    //
  public:
    // Arm the callback and set the restore flag if transaction is not NULL.
    //
    void
    reset (bool l = false, bool c = false, transaction* t = 0) const
    {
      state_.loaded = l;
      state_.changed = c;

      if (t != 0 && !state_.armed)
      {
        t->callback_register (&transacion_callback,
                              const_cast<section*> (this));
        state_.armed = 1;
      }

      state_.restore = (t != 0);
    }

  private:
    void
    disarm ();

    static void
    transacion_callback (unsigned short, void* key, unsigned long long);

  private:
    mutable struct
    {
      unsigned char loaded : 1;
      unsigned char changed : 1;
      unsigned char armed : 1;    // Transaction callback is armed.
      unsigned char restore: 1;   // Restore changed flag on rollback.
      unsigned char user : 4;     // User data.
    } state_;
  };
}

#include <odb/post.hxx>

#endif // ODB_SECTION_HXX
