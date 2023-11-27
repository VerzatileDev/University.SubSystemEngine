#pragma once
#include <Box2D/Box2D.h>
#include "Player.h"
#include "Ground.h"

class ContactListener : public b2ContactListener {
public:
    ContactListener();
    ~ContactListener();
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;

    bool IsPlayerOnGround() const;

private:
    bool IsGroundContact(b2Fixture* fixture) const;
    bool playerOnGround;
};