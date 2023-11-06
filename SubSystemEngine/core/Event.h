#pragma once

// Included Libraries
#include <SFML/Window.hpp>

class Event {
public:
    enum EventType {
        Closed,
        KeyPressed,
        KeyHeldDown,
        KeyReleased,
        EscapePressed,

    };

    Event(EventType type);
    EventType GetType() const;

private:
    EventType type;
};