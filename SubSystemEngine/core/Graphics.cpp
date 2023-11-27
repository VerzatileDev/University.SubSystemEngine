#include "Graphics.h"
#include <iostream>

Graphics::Graphics() : debugDrawingEnabled(false) {}

Graphics::~Graphics() 
{
    drawables.clear();
}

void Graphics::initialize() {
    
}

void Graphics::update() {
    Window::getInstance().clear();

    render();

    Window::getInstance().display();
}

void Graphics::render() {
    for (const auto& drawable : drawables) {
        Window::getInstance().getWindow().draw(*drawable);
    }

}

sf::RenderWindow& Graphics::getWindow() {
    return Window::getInstance().getWindow();
}

void Graphics::handleResize() {
    // Handle resizing-related adjustments if needed
    // For example, update the view to maintain the scale of elements
    sf::Vector2u newSize = Window::getInstance().getWindow().getSize();
    view.setSize(static_cast<float>(newSize.x), static_cast<float>(newSize.y));
    Window::getInstance().getWindow().setView(view);
}

void Graphics::addDrawable(sf::Drawable& drawable) {
    drawables.push_back(&drawable);
}

void Graphics::removeDrawable(sf::Drawable& drawable) {
    drawables.erase(std::remove(drawables.begin(), drawables.end(), &drawable), drawables.end());
}

void Graphics::drawText(const sf::Text& text) {
    addDrawable(const_cast<sf::Text&>(text));
}

void Graphics::drawSprite(const sf::Sprite& sprite) {
    addDrawable(const_cast<sf::Sprite&>(sprite));
}

void Graphics::drawShape(const sf::Shape& shape) {
    addDrawable(const_cast<sf::Shape&>(shape));
}

void Graphics::enableDebugDrawing(bool enable) {
    debugDrawingEnabled = enable;
}