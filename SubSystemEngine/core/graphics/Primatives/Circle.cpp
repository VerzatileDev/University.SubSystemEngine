#include "Circle.h"

Circle::Circle() : radius(50.0f), color(sf::Color::White)
{
    SetPosition(0.0f, 0.0f);
}

Circle::Circle(float radius, const sf::Color& color) : radius(radius), color(color)
{

}

void Circle::Render(sf::RenderWindow& window)
{
    // Draw the circle on the window
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

void Circle::Update()
{}