#include "Ground.h"

Ground::Ground(b2World& world, const sf::Vector2f& position, float size) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.type = b2_staticBody; // Ground is a static body
    body = world.CreateBody(&bodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(size / 2.f, size / 2.f);
    body->CreateFixture(&groundBox, 0.0f);

    shape.setSize(sf::Vector2f(size, size));
    shape.setOrigin(size / 2.f, size / 2.f);
    shape.setPosition(position);
}

void Ground::draw(sf::RenderWindow& window) {
    window.draw(shape);
}