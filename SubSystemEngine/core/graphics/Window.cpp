#include "Window.h"

void Window::Initialize(int width, int height, const std::string& title)
{
    try {
        window.create(sf::VideoMode(width, height), title);
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred during window creation: " << e.what() << std::endl;
    }
}

sf::RenderWindow& Window::getRenderWindow() 
{
    try {
        return window;
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred trying to get an instance of window, see if window is initialized: " << e.what() << std::endl;
    }
}