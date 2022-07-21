//
// Created by bong on 22. 7. 20.
//

#ifndef REACTOR_PATTERN_EVENT_HANDLER_H
#define REACTOR_PATTERN_EVENT_HANDLER_H

class EventHandler {
public:

    virtual ~EventHandler() = default;

    virtual void handle_read(int handle) {}
    virtual void handle_write(int handle) {}
    virtual void handle_exception(int handle) {}
};

#endif //REACTOR_PATTERN_EVENT_HANDLER_H
