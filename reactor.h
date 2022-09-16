//
// Created by bong on 22. 7. 20.
//

#ifndef REACTOR_PATTERN_REACTOR_H
#define REACTOR_PATTERN_REACTOR_H

#include "event_handler.h"

#include <string>
#include <map>
#include <atomic>

enum class EventType {
    kReadEvent = 1,
    kWriteEvent = 2,
    kExceptionEvent = 3
};

class Reactor {
public:
    Reactor();
    ~Reactor();

    void register_event_handler(int handle, EventHandler* event_handler, EventType eventType,
                                bool one_shot = false);

    void unregister_event_handler(int handle, EventType eventType);
    void handle_events(const struct timeval* timeout = nullptr);
    void unblock();

private:
    /* Log context */
    const std::string log = "Reactor";
    struct EventHandlerMapEntry {
        EventHandler* event_handler_;
        bool one_shot_;
    };

    void dispatch_event_handlers();
    int setup_fd_sets();
    void send_wakeup();
    void handle_wakeup();
    std::array<int, 2> wakeup_pipe_;
    std::atomic_bool dispatching_;
    fd_set rfds, wfds, efds;
    std::map<int, EventHandlerMapEntry> read_event_handlers_;
    std::map<int, EventHandlerMapEntry> write_event_handlers_;
    std::map<int, EventHandlerMapEntry> exception_event_handlers_;
};

#endif //REACTOR_PATTERN_REACTOR_H
