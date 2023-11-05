#pragma once

// Included Libraries
#include <SFML/Window.hpp>

class Event {
public:
    enum EventType {
        Closed,

    };

    Event(EventType type);
    EventType GetType() const;

private:
    EventType type;
};