#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Physics.h"
#include <iostream>

// HardCoded Because I Don't know how to make them Globally Accessible
const int WINDOW_WIDT = 800;
const int WINDOW_HEIGH = 600;
const float PIXELS_PER_METE = 30.0f;

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