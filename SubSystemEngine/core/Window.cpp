#include "Window.h"
#include <iostream>

Window::Window() : window(sf::VideoMode(800, 600), "SFML + Box2D"), windowSize(800, 600) {}

Window::~Window() {
    if (window.isOpen()) {
        window.close();
    }
}

Window& Window::getInstance() {
    static Window instance;
    return instance;
}

void Window::initialize() {
    // Additional window setup can be done here
}

void Window::clear() {
    window.clear();
}

void Window::display() {
    window.display();
}

sf::RenderWindow& Window::getWindow() {
    return window;
}

void Window::setFullscreen(bool fullscreen) {
    window.create(fullscreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode(windowSize.x, windowSize.y), "SFML + Box2D", fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    windowSize = window.getSize();
}

void Window::setWindowSize(sf::Vector2u size) {
    window.setSize(size);
    windowSize = size;
}