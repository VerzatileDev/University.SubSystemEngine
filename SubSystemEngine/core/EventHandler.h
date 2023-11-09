#pragma once

// Included Files
#include "Event.h"

// System Libraries
#include <vector>
#include <iostream>

class EventHandler {
public:
    static EventHandler& getInstance() {
        static EventHandler instance;
        return instance;
    }

    void AddEvent(const Event& event);
    void ClearEvents();
    void ProcessEvents();
    bool IsRunning();

private:
    std::vector<Event> eventQueue;
    bool running = true;
};
