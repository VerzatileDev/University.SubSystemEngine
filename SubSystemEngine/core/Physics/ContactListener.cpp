#include "ContactListener.h"
#include <iostream>

ContactListener::ContactListener() : playerOnGround(false) {}

ContactListener::~ContactListener()
{
}

void ContactListener::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    if (IsGroundContact(fixtureA) || IsGroundContact(fixtureB))
    {
        playerOnGround = true;
        std::cout << "Player touched the ground!" << std::endl;
    }
}

void ContactListener::EndContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    if (IsGroundContact(fixtureA) || IsGroundContact(fixtureB))
    {
        playerOnGround = false;
    }
}

bool ContactListener::IsPlayerOnGround() const
{
    return playerOnGround;
}

bool ContactListener::IsGroundContact(b2Fixture* fixture) const
{
    return fixture->GetFilterData().categoryBits == 1;
}
