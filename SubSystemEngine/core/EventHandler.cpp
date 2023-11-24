#include "EventHandler.h"

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
            std::cout << "Closing the Engine" << std::endl; // Debug
            running = false;
            break;
        case Event::KeyPressed:
            //std::cout << "Key Pressed: " << event.GetKeyString() << std::endl; // Debug
            if (event.GetKeyString() == "Escape") {
                std::cout << "Closing the Engine" << std::endl; // Debug
                running = false;
            }
            break;
        case Event::KeyHeldDown:
            //std::cout << "Key Held: " << event.GetKeyString() << std::endl; // Debug
            break;
        case Event::KeyReleased:
            //std::cout << "Key Released: " << event.GetKeyString() << std::endl; // Debug
            break;
        default:
            std::cout << "Event not defined with an action " << std::endl; // Debug
            break;
        }
    }
    ClearEvents();
}