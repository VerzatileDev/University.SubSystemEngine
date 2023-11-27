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
            if (event.GetKeyString() == "A" && playerMoveLeftCallback) {
                playerMoveLeftCallback();
            }
            else if (event.GetKeyString() == "D" && playerMoveRightCallback) {
                playerMoveRightCallback();
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

void EventHandler::setPlayerMoveLeftCallback(std::function<void()> callback) {
    playerMoveLeftCallback = callback;
}

void EventHandler::setPlayerMoveRightCallback(std::function<void()> callback) {
    playerMoveRightCallback = callback;
}