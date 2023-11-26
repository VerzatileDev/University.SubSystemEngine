#include "Graphics.h"

Graphics::Graphics() {}

Graphics::~Graphics() {}

void Graphics::initialize() {
    // Additional graphics setup can be done here
}

void Graphics::update() {
    Window::getInstance().clear();

    EntityManager::getInstance().updateEntities();

    EntityManager::getInstance().drawEntities();

    Window::getInstance().display();
}

sf::RenderWindow& Graphics::getWindow() {
    return Window::getInstance().getWindow();
}

void Graphics::handleResize() {
    // Handle resizing-related adjustments if needed
    // For example, update the view to maintain the scale of elements
    sf::Vector2u newSize = Window::getInstance().getWindow().getSize();
    sf::View view = Window::getInstance().getWindow().getView();
    view.setSize(static_cast<float>(newSize.x), static_cast<float>(newSize.y));
    Window::getInstance().getWindow().setView(view);
}