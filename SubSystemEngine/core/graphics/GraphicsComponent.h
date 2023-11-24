#pragma once

#include "../Component.h"
#include <SFML/Graphics.hpp>

class GraphicsComponent : public Component
{
public:
    GraphicsComponent();
    GraphicsComponent(const sf::Vector2f& initialPosition);
    virtual ~GraphicsComponent();

    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void SetPosition(float x, float y); // Entity Position updates


protected:
    sf::Vector2f position;
};