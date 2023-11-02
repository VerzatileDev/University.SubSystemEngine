#include "Event.h"

Event::Event(EventType type) : type(type) {}

Event::EventType Event::GetType() const {
    return type;
}