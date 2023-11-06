#include "InputSystem.h"

InputSystem::InputSystem(Graphics& graphics, EventHandler& eventHandler)
    : graphics(graphics), eventHandler(eventHandler) {
    // Initialize other parts of InputSystem if needed
    

}

InputSystem::~InputSystem()
{
}

void InputSystem::PollEvents()
{
    //std::cout << "Window is valid: " << (graphics.GetWindow().isOpen() ? "true" : "false") << std::endl;
    sf::Event event;
    while (graphics.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            eventHandler.AddEvent(Event(Event::Closed));
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            // Get the key code
            sf::Keyboard::Key keyCode = event.key.code;

            // Convert the key code to a string
            std::string keyName;
            switch (keyCode)
            {
            case sf::Keyboard::A: keyName = "A"; break;
            case sf::Keyboard::B: keyName = "B"; break;
                // Add cases for other keys as needed
            default: keyName = "Unknown"; break;
            }

            // Print the key name
            std::cout << "Key pressed: " << keyName << std::endl;
        }
    }
}