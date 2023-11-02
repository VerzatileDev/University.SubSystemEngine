#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <vector>
#include "Event.h"
#include <iostream>

class EventHandler {
public:
    void AddEvent(const Event& event);
    void ClearEvents();
    void ProcessEvents();

private:
    std::vector<Event> eventQueue;
};

#endif