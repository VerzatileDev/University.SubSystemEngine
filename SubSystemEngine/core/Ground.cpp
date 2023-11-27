#include "Ground.h"

Ground::Ground() : body(nullptr), physicsRef(physicsInstance)
{
}

Ground::Ground(Physics& physics) : body(nullptr), physicsRef(physics) {
}

Ground::~Ground() {
    // Managed by Physics destructor
}

void Ground::initialize(b2World& world, const sf::Vector2f& position, float size) {
    shape.setSize(sf::Vector2f(WINDOW_WIDT, 20));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(WINDOW_WIDT / 2, 10);
    shape.setPosition(WINDOW_WIDT / 2, WINDOW_HEIGH - 10);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(WINDOW_WIDT / (2 * PIXELS_PER_METE), (WINDOW_HEIGH - 10) / PIXELS_PER_METE);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(WINDOW_WIDT / (2 * PIXELS_PER_METE), 10 / PIXELS_PER_METE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &groundBox;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 0.0f;
    fixtureDef.filter.categoryBits = 1;
    body->CreateFixture(&fixtureDef);

    body->SetUserData(this);
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
        shape.setPosition(position.x * PIXELS_PER_METE, position.y * PIXELS_PER_METE);
    }
}
