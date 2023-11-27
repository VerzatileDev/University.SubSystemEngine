#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Physics.h"
#include <iostream>

const float PIXELS_PER_METER = 30.0f;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Player {
public:
    static Player& getInstance();
    Player();
    Player(Physics& physics);
    ~Player();

    void initialize(b2World& world, const sf::Vector2f& position, float size);
    void update();
    void draw(sf::RenderWindow& window);
    sf::RectangleShape& getShape();

    void moveLeft();
    void moveRight();
    void stopMoving();
    void jump();

private:
    b2Body* body;
    sf::RectangleShape shape;
    Physics& physicsRef;
    Physics physicsInstance;
    sf::Texture playerTexture;
};