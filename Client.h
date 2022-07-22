//
// Created by bong on 22. 7. 22.
//

#ifndef REACTOR_PATTERN_CLIENT_H
#define REACTOR_PATTERN_CLIENT_H

#include <thread>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "reactor.h"

class IPCClient: public EventHandler
{
public:
    IPCClient(Reactor& reactor, std::string local_address);
    ~IPCClient () override;

    /**
    * \brief Starts IPCClient
       */
    void start();
    /**
     * \brief Stops IPCClient
     */
    void stop();


private:
    /* Log context */
    const std::string log = "IPCClient";
    /**
       * \brief A file descriptor representing a Unix domain socket file
       */
    int handle_;

    /**
       * \brief A name of a socket file representing the local address of the Unix domain socket
       */
    std::string local_address_;

    /**
    * \brief A flag to control the client processing thread
    */
    std::atomic<bool> ipcclient_done_;

    /**
     * \brief A reactor which is used for notifications about non-blocking writing to the Unix domain socket
     */
    Reactor& reactor_;

};


#endif //REACTOR_PATTERN_CLIENT_H
