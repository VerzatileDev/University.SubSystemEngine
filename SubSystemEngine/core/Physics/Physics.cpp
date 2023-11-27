#include "Physics.h"
#include <iostream>

Physics::Physics() : world(b2Vec2(0.0f, 9.8f)) {}

Physics::~Physics() {
    b2Body* body = world.GetBodyList();
    while (body) {
        b2Body* nextBody = body->GetNext();
        world.DestroyBody(body);
        body = nextBody;
    }
}

void Physics::initialize() {
}

void Physics::update() {
    timer.StartTimer();
    // Update physics
    world.Step(1.0f / 60.0f, 8, 3);

    timer.StopTimer();
    //IsFrameRateTrackingEnabled() ? timer.GetAndPrintFrameRate("Physics") : void(); // Enabled by EventHandler Tab
    timer.GetAndPrintFrameRate("Physics");
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

void Physics::applyLinearVelocity(b2Body* body, const b2Vec2& velocity)
{
    	body->SetLinearVelocity(velocity);
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
    // To be made still
}
