#pragma once
#include <Box2D/Box2D.h>

class Physics {
public:
    Physics();
    ~Physics();

    void initialize();
    void update();

    b2World& getWorld();

    b2Body* createBody(const b2BodyDef& bodyDef);
    b2Fixture* createFixture(b2Body* body, const b2FixtureDef& fixtureDef);
    b2Joint* createJoint(const b2JointDef& jointDef);

    void setContactListener(b2ContactListener* listener);

    void applyForceToCenter(b2Body* body, const b2Vec2& force);
    void applyLinearImpulse(b2Body* body, const b2Vec2& impulse);

    void setGravity(const b2Vec2& gravity);

    void rayCast(b2RayCastCallback* callback, const b2Vec2& point1, const b2Vec2& point2);
    void queryAABB(b2QueryCallback* callback, const b2AABB& aabb);

    void destroyBody(b2Body* body);

    void enableDebugDrawing(bool enable);

private:
    b2World world;
};