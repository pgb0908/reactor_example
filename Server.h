//
// Created by bong on 22. 7. 22.
//

#ifndef REACTOR_PATTERN_SERVER_H
#define REACTOR_PATTERN_SERVER_H

#include "reactor.h"

class IPCServer: public EventHandler
{
public:
    IPCServer(Reactor& reactor, std::string local_address);
    virtual ~IPCServer ();

    /**
    * \brief Starts reading messages from the Unix domain socket connected to a server.
       */
    void start();
    /**
     * \brief Stops reading messages from the Unix domain socket connected to a server
     *        and closes the connection.
     */
    void stop();


private:
    /* Log context */
    const std::string log = "IPCServer";

    /**
       * \brief handler for asynchronous event notification on the Unix domain socket connected to a server.
       *
       * \param a an a argument.
       */
    void handle_read(int handle) override;

    /**
       * \brief A file descriptor representing an established connection to an application.
       */
    int handle_;

    /**
       * \brief Proving that the server is not blocked while waiting on new connections.
       */
    void do_something_else();

    /**
       * \brief Unix path representing the local address of the accepting Unix domain socket.
       */
    std::string local_address_;

    /**
    * \brief A flag to control the server processing thread
    */
    std::atomic<bool> ipcserver_done_;

    /**
     * \brief A reactor which is used for notification about incoming connections.
     */
    Reactor& reactor_;

};


#endif //REACTOR_PATTERN_SERVER_H
