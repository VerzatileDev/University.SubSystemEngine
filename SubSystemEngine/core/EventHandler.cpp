#include "EventHandler.h"
#include "Engine.h"

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
            std::cout <<"Closing the Engine" << std::endl;
            running = false;
            break;

        default:
            break;
        }
    }

    ClearEvents();
}