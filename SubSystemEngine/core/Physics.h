#pragma once

#include <Box2D/Box2D.h>

class Physics {
public:
    Physics();
    ~Physics();

    void initialize();
    void update();

    b2World& getWorld(); // Added a getter for the Box2D world
private:
    b2World world;
};