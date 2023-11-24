#pragma once

#include "../Component.h"
#include <Box2D/Box2D.h>

class PhysicsComponent : public Component
{
public:
    PhysicsComponent(b2World& world, const b2BodyDef& bodyDef);
    ~PhysicsComponent();

    void ApplyForce(const b2Vec2& force);
    void Update() override;

    // Other functions...

private:
    b2Body* body;
    bool hasGravity;
};