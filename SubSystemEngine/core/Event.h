#pragma once

// System Libraries
#include <string>

class Event {
public:
    enum EventType {
        Closed,
        KeyPressed,
        KeyHeldDown,
        KeyReleased,
    };

    Event(EventType type, std::string keyString);
    Event(EventType type);
    EventType GetType() const;
    std::string GetKeyString() const;

private:
    EventType type;
    std::string keyString;
};