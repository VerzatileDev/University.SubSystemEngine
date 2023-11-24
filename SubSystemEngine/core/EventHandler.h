#pragma once

// Included Files
#include "Event.h"

// System Libraries
#include <vector>
#include <iostream>

class EventHandler {
public:
    
    static EventHandler& getInstance()  // Singleton (Only one instance of EventHandler can exist) - returns the instance
    {
        static EventHandler instance;
        return instance;
    }

    void AddEvent(const Event& event); // Adds an event to the queue
    void ClearEvents(); // Clears all events in the queue
    void ProcessEvents(); // Processes all events in the queue
    bool IsRunning(); // Returns true if the Game Loop should continue running

private:
    std::vector<Event> eventQueue; // The queue of events to be processed
    bool running = true; // The Game Loop will stop when this is false
};
