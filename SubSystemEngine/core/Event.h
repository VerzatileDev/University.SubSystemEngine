#ifndef EVENT_H
#define EVENT_H

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

#endif