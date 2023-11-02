#include "EventHandler.h"

void EventHandler::AddEvent(const Event& event) {
    eventQueue.push_back(event);
}

void EventHandler::ClearEvents() {
    eventQueue.clear();
}

void EventHandler::ProcessEvents() {
    for (Event& event : eventQueue) {
        switch (event.GetType()) {
        case Event::Closed:
            // Handle Closed event
            // For example, you can set 'running' to false
            std::cout <<"Closed event" << std::endl;
            // running = false;
            break;
            // Add cases for other event types as needed

        default:
            break;
        }
    }

    ClearEvents();
}