#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "../Physics/Physics.h"

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

    void setDesiredVelocity(const b2Vec2& velocity);

private:
    b2Body* body;
    sf::RectangleShape shape;
    Physics& physicsRef;
    Physics physicsInstance;
    sf::Texture playerTexture;
    b2Vec2 desiredVelocity;
};