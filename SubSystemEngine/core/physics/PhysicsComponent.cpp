#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(b2World& world, const b2BodyDef& bodyDef)
{
    body = world.CreateBody(&bodyDef);
}

PhysicsComponent::~PhysicsComponent()
{
    // Cleanup if needed...
}

void PhysicsComponent::ApplyForce(const b2Vec2& force)
{
    body->ApplyForceToCenter(force, true);
}

void PhysicsComponent::Update()
{
    // Synchronize the position of the Box2D body with the entity's position
    b2Vec2 position = body->GetPosition();
    //SetPosition(sf::Vector2f(position.x, position.y));

    // Other physics-related updates...
}