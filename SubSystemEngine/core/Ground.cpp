#include "Ground.h"
#include <iostream>

Ground::Ground() : body(nullptr), physicsRef(physicsInstance)
{
}

Ground::Ground(Physics& physics) : body(nullptr), physicsRef(physics) {
}

Ground::~Ground() {
    // Managed by Physics destructor
}

void Ground::initialize(b2World& world, const sf::Vector2f& position, float size) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x + 400, position.y + 300);
    bodyDef.type = b2_staticBody;  // Ground is a static object
    body = world.CreateBody(&bodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(size / (2.0f), size / (2.0f));

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &groundBox;
    fixtureDef.density = 1.0f;
    body->CreateFixture(&fixtureDef);
    shape.setSize(sf::Vector2f(size, size));
    shape.setOrigin(size / 2.0f, size / 2.0f);
}

void Ground::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Ground::getShape()
{
    return shape;
}

void Ground::update() {
    if (body) {
        b2Vec2 position = body->GetPosition();
        std::cout << "Player Position: (" << position.x << ", " << position.y << ")" << std::endl;
        shape.setPosition(position.x, position.y);
    }
}
