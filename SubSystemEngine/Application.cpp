#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"

int main(int args, char* argv[])
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(); // Clear the window

        // Draw your content here

        window.display(); // Display the content
    }

    return 0;
}