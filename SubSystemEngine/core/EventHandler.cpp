#include "EventHandler.h"

EventHandler& EventHandler::getInstance() {
    static EventHandler instance;
    return instance;
}

void EventHandler::AddEvent(const Event& event) {
    eventQueue.push_back(event);
}

void EventHandler::ClearEvents() {
    eventQueue.clear();
}

bool EventHandler::IsRunning() {
    return running;
}

void EventHandler::ProcessEvents() {
    for (Event& event : eventQueue) {
        switch (event.GetType()) {
        case Event::Closed:
            std::cout << "Closing the Engine" << std::endl;
            running = false;
            break;
        case Event::KeyPressed:
            if (event.GetKeyString() == "Escape") {
                std::cout << "Closing the Engine" << std::endl;
                running = false;
            }
            break;
        case Event::KeyHeldDown:
            if (event.GetKeyString() == "A") {
                // Handle moving left (e.g., player.moveLeft())
                
            }
            else if (event.GetKeyString() == "D") {
                // Handle moving right (e.g., player.moveRight())
                
            }
            break;
        case Event::KeyReleased:
            break;
        default:
            std::cout << "Event not defined with an action " << std::endl;
            break;
        }
    }
    ClearEvents();
}