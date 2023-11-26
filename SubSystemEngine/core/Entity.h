#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Entity
{
public:
    Entity();
    ~Entity();
    Entity(b2World& world, const sf::Vector2f& position, float size);

    void update();
    void draw(sf::RenderWindow& window) const;
    void moveLeft();
    void moveRight();
private:
    b2Body* body;
    sf::RectangleShape shape;
};
