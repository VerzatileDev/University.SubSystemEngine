#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Physics.h"

class Ground {
public:
    Ground(b2World& world, const sf::Vector2f& position, float size);

    void draw(sf::RenderWindow& window);

private:
    b2Body* body;
    sf::RectangleShape shape;
};