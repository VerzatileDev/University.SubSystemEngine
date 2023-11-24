#pragma once

#include "../GraphicsComponent.h"

class Square : public GraphicsComponent
{
public:
    Square(); // Default at position of 0 0, white, size 10 (This is the default square)
    Square(float size, const sf::Color& color); // Definable properties size and color
    void Render(sf::RenderWindow& window) override;
    void Update() override;
private:
    float size;
    sf::Color color;
};