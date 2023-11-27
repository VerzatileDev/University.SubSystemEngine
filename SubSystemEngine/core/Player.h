#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Physics.h"
#include <iostream>

class Player {
public:
    Player();
    Player(Physics& physics);
    ~Player();

    void initialize(b2World& world, const sf::Vector2f& position, float size);
    void update();
    void draw(sf::RenderWindow& window);
    sf::RectangleShape& getShape();
private:
    b2Body* body;
    sf::RectangleShape shape;
    Physics& physicsRef;
    Physics physicsInstance;
};