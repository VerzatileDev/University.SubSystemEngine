#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class StaticEntity {
public:
    StaticEntity(b2World& world, const sf::Vector2f& position, float size);
    void draw(sf::RenderWindow& window) const;

private:
    b2Body* body;
    sf::RectangleShape shape;
};