#pragma once

// Included Libraries
#include <SFML/Window.hpp>
#include <string>

class Event {
public:
    enum EventType {
        Closed,
        KeyPressed,
        KeyHeldDown,
        KeyReleased,
    };

    Event(EventType type, std::string keyString); // Change the second parameter to string
    Event(EventType type);
    EventType GetType() const;
    std::string GetKeyString() const;

private:
    EventType type;
    std::string keyString;
    sf::Keyboard::Key keyCode;
};