//
// Created by bong on 22. 7. 20.
//

#include "reactor.h"
#include <thread>

int main() {

    Reactor reactor;
    std::atomic<bool> reactor_done(false);
    std::thread reactor_thread = std::thread([&reactor,&reactor_done]() {
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        while (!reactor_done) {
            reactor.handle_events(&timeout);
        }
    });


    reactor_done = true;
    reactor.unblock();
    reactor_thread.join();

    return 0;
}