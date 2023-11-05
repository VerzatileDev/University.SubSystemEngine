#pragma once

// Included Libraries
#include <vector>
#include <iostream>

// Included Files
#include "Event.h"

class EventHandler {
public:
    void AddEvent(const Event& event);
    void ClearEvents();
    void ProcessEvents();
    bool IsRunning();

private:
    std::vector<Event> eventQueue;
    bool running = true;
};