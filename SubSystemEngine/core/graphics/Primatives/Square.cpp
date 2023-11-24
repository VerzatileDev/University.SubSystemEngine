#include "Square.h"

Square::Square() : size(10.0f), color(sf::Color::White)
{
    SetPosition(0.0f, 0.0f);
}

Square::Square(float size, const sf::Color& color) : size(size), color(color)
{

}

void Square::Render(sf::RenderWindow& window)
{
    // Draw the square on the window
    sf::RectangleShape square(sf::Vector2f(size, size));
    square.setPosition(position);
    square.setFillColor(color);
    window.draw(square);
}

void Square::Update()
{
}
