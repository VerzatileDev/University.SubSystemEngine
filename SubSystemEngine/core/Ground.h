#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Physics.h"
#include <iostream>

class Ground {
public:
    Ground();
    Ground(Physics& physics);
    ~Ground();

    void initialize(b2World& world, const sf::Vector2f& position, float size);
    void draw(sf::RenderWindow& window);
    void update();
    sf::RectangleShape& getShape();
private:
    b2Body* body;
    sf::RectangleShape shape;
    Physics& physicsRef;
    Physics physicsInstance;
};