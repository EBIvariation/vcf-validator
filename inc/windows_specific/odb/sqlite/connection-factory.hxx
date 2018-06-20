// file      : odb/sqlite/connection-factory.hxx
// copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_SQLITE_CONNECTION_FACTORY_HXX
#define ODB_SQLITE_CONNECTION_FACTORY_HXX

#include <odb/pre.hxx>

#include <vector>
#include <cstddef> // std::size_t
#include <cassert>

#include <odb/details/mutex.hxx>
#include <odb/details/condition.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/details/export.hxx>

namespace odb
{
  namespace sqlite
  {
    class LIBODB_SQLITE_EXPORT connection_factory
    {
    public:
      virtual connection_ptr
      connect () = 0;

    public:
      typedef sqlite::database database_type;

      virtual void
      database (database_type&) = 0;

      virtual
      ~connection_factory ();
    };

    // Share a single connection.
    //
    class LIBODB_SQLITE_EXPORT single_connection_factory:
      public connection_factory
    {
    public:
      single_connection_factory (): db_ (0) {}

      virtual connection_ptr
      connect ();

      virtual void
      database (database_type&);

      virtual
      ~single_connection_factory ();

    private:
      single_connection_factory (const single_connection_factory&);
      single_connection_factory& operator= (const single_connection_factory&);

    protected:
      class LIBODB_SQLITE_EXPORT single_connection: public connection
      {
      public:
        single_connection (database_type&, int extra_flags = 0);
        single_connection (database_type&, sqlite3*);

      private:
        static bool
        zero_counter (void*);

      private:
        friend class single_connection_factory;

        shared_base::refcount_callback callback_;

        // NULL factory value indicates that the connection is not in use.
        //
        single_connection_factory* factory_;
      };

      friend class single_connection;

      typedef details::shared_ptr<single_connection> single_connection_ptr;

      // This function is called when the factory needs to create the
      // connection.
      //
      virtual single_connection_ptr
      create ();

    protected:
      // Return true if the connection should be deleted, false otherwise.
      //
      bool
      release (single_connection*);

    protected:
      database_type* db_;
      details::mutex mutex_;
      single_connection_ptr connection_;
    };

    // Create a new connection every time one is requested.
    //
    class LIBODB_SQLITE_EXPORT new_connection_factory:
      public connection_factory
    {
    public:
      new_connection_factory (): db_ (0), extra_flags_ (0) {}

      virtual connection_ptr
      connect ();

      virtual void
      database (database_type&);

    private:
      new_connection_factory (const new_connection_factory&);
      new_connection_factory& operator= (const new_connection_factory&);

    private:
      database_type* db_;
      int extra_flags_;
    };

    // Pool a number of connections.
    //
    class LIBODB_SQLITE_EXPORT connection_pool_factory:
      public connection_factory
    {
    public:
      // The max_connections argument specifies the maximum number of
      // concurrent connections this pool will maintain. If this value
      // is 0 then the pool will create a new connection every time all
      // of the existing connections are in use.
      //
      // The min_connections argument specifies the minimum number of
      // connections that should be maintained by the pool. If the
      // number of connections maintained by the pool exceeds this
      // number and there are no active waiters for a new connection,
      // then the pool will release the excess connections. If this
      // value is 0 then the pool will maintain all the connections
      // that were ever created.
      //
      // The ping argument specifies whether to ping the connection to
      // make sure it is still alive before returning it to the caller.
      //
      connection_pool_factory (std::size_t max_connections = 0,
                               std::size_t min_connections = 0)
          : max_ (max_connections),
            min_ (min_connections),
            extra_flags_ (0),
            in_use_ (0),
            waiters_ (0),
            db_ (0),
            cond_ (mutex_)
      {
        // max_connections == 0 means unlimited.
        //
        assert (max_connections == 0 || max_connections >= min_connections);
      }

      virtual connection_ptr
      connect ();

      virtual void
      database (database_type&);

      virtual
      ~connection_pool_factory ();

    private:
      connection_pool_factory (const connection_pool_factory&);
      connection_pool_factory& operator= (const connection_pool_factory&);

    protected:
      class LIBODB_SQLITE_EXPORT pooled_connection: public connection
      {
      public:
        pooled_connection (database_type&, int extra_flags = 0);
        pooled_connection (database_type&, sqlite3*);

      private:
        static bool
        zero_counter (void*);

      private:
        friend class connection_pool_factory;

        shared_base::refcount_callback callback_;

        // NULL pool value indicates that the connection is not in use.
        //
        connection_pool_factory* pool_;
      };

      friend class pooled_connection;

      typedef details::shared_ptr<pooled_connection> pooled_connection_ptr;
      typedef std::vector<pooled_connection_ptr> connections;

      // This function is called whenever the pool needs to create a new
      // connection.
      //
      virtual pooled_connection_ptr
      create ();

    protected:
      // Return true if the connection should be deleted, false otherwise.
      //
      bool
      release (pooled_connection*);

    protected:
      const std::size_t max_;
      const std::size_t min_;
      int extra_flags_;

      std::size_t in_use_;  // Number of connections currently in use.
      std::size_t waiters_; // Number of threads waiting for a connection.

      database_type* db_;
      connections connections_;

      details::mutex mutex_;
      details::condition cond_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_SQLITE_CONNECTION_FACTORY_HXX
