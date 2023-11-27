#include "ContactListener.h"
#include <iostream>

ContactListener::ContactListener() {}

ContactListener::~ContactListener() {}

void ContactListener::BeginContact(b2Contact* contact) {
    // Handle begin contact events
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if (bodyUserDataA && bodyUserDataB) {
        Player* player = static_cast<Player*>(bodyUserDataA);
        Ground* ground = static_cast<Ground*>(bodyUserDataB);

        std::cout << "Contact between Player and Ground!" << std::endl;

        // Handle collision between player and ground
        if (player && ground) {
            // Add collision handling logic here
            std::cout << "Player collided with ground!" << std::endl;
        }
    }
}

void ContactListener::EndContact(b2Contact* contact) {
    // Called when two fixtures cease to touch
    // Implement your logic here
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
    // Called before collision response
    // Implement your logic here
}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    // Called after collision response
    // Implement your logic here
}