#pragma once

// System libraries
#include <iostream>

// Included Libraries
#include <SFML/Graphics.hpp>

class Window
{
public:
    // Singleton pattern to ensure only one instance of the window is created
    static Window& getInstance() {
        static Window instance;
        return instance;
    }

    // Defines Window properties and creates the window
    void Initialize(int width, int height, const std::string& title);
    sf::RenderWindow& getRenderWindow();

    // Disable copy constructor & assignment operator
    // This avoids copies of the singleton when passing by value and assignment
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    Window() = default; // Private constructor to prevent instantiation
    sf::RenderWindow window;
};