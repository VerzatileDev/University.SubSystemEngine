#pragma once

#include "../GraphicsComponent.h"

class Circle : public GraphicsComponent
{
public:
    Circle(); // Default at position of 0 0, white, radius 10 (This is the default circle)
    Circle(float radius, const sf::Color& color); // Definable properties radius and color
    void Render(sf::RenderWindow& window) override;
    void Update() override;

private:
    float radius;
    sf::Color color;
};