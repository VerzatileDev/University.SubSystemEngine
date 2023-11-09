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

sf::RenderWindow& Window::getRenderWindow() {
    //std::cout << "Window Gotten" << std::endl; // Debug
    return window;
}