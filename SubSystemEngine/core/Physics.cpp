#include "Physics.h"

Physics::Physics() : world(b2Vec2(0.0f, 9.8f)) {}

Physics::~Physics() {
    // The Box2D world will automatically release its resources upon destruction
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