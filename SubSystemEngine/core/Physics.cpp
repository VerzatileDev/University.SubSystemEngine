#include "Physics.h"
#include <iostream>

Physics::Physics() : world(b2Vec2(0.0f, -0.02f)) {}

Physics::~Physics() {
    b2Body* body = world.GetBodyList();
    while (body) {
        b2Body* nextBody = body->GetNext();
        world.DestroyBody(body);
        body = nextBody;
    }
}

void Physics::initialize() {
    // Additional physics setup can be done here
}

void Physics::update() {
    // Update physics
    world.Step(1.0f / 60.0f, 8, 3);
}

b2World& Physics::getWorld() {
    return world;
}

b2Body* Physics::createBody(const b2BodyDef& bodyDef) {
    return world.CreateBody(&bodyDef);
}

b2Fixture* Physics::createFixture(b2Body* body, const b2FixtureDef& fixtureDef) {
    return body->CreateFixture(&fixtureDef);
}

b2Joint* Physics::createJoint(const b2JointDef& jointDef) {
    return world.CreateJoint(&jointDef);
}

void Physics::setContactListener(b2ContactListener* listener) {
    world.SetContactListener(listener);
}

void Physics::applyForceToCenter(b2Body* body, const b2Vec2& force) {
    body->ApplyForceToCenter(force, true);
}

void Physics::applyLinearImpulse(b2Body* body, const b2Vec2& impulse) {
    body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
}

void Physics::setGravity(const b2Vec2& gravity) {
    world.SetGravity(gravity);
}

void Physics::rayCast(b2RayCastCallback* callback, const b2Vec2& point1, const b2Vec2& point2) {
    world.RayCast(callback, point1, point2);
}

void Physics::queryAABB(b2QueryCallback* callback, const b2AABB& aabb) {
    world.QueryAABB(callback, aabb);
}

void Physics::destroyBody(b2Body* body) {
    world.DestroyBody(body);
}

void Physics::enableDebugDrawing(bool enable) {
    // Implement debug drawing logic here
    // This function depends on your specific rendering requirements
    // For example, you can draw shapes using SFML to visualize the physics objects
}
