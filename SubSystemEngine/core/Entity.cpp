#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
    if (body) {
        body->GetWorld()->DestroyBody(body);
    }
}

Entity::Entity(b2World& world, const sf::Vector2f& position, float size) {
    // Box2D Body
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.type = b2_dynamicBody;
    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(size / 2.f, size / 2.f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    body->CreateFixture(&fixtureDef);

    // SFML Shape
    shape.setSize(sf::Vector2f(size, size));
    shape.setOrigin(size / 2.f, size / 2.f);
    shape.setPosition(position.x, position.y);
}

void Entity::update() {
    // Update SFML shape position based on Box2D body position
    b2Vec2 position = body->GetPosition();
    shape.setPosition(position.x, position.y);
}

void Entity::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}