#include "StaticEntity.h"

StaticEntity::StaticEntity(b2World& world, const sf::Vector2f& position, float size) {
    // Box2D Body
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.type = b2_staticBody; // Set as static body
    body = world.CreateBody(&bodyDef);

    b2PolygonShape staticBox;
    staticBox.SetAsBox(size / 2.f, size / 2.f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;
    fixtureDef.density = 1.0f;
    body->CreateFixture(&fixtureDef);

    // SFML Shape
    shape.setSize(sf::Vector2f(size, size));
    shape.setOrigin(size / 2.f, size / 2.f);
    shape.setPosition(position);
}

void StaticEntity::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}