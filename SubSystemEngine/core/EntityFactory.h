#pragma once

#include "Entity.h"
#include "graphics/Primatives/Circle.h"
#include "graphics/Primatives/Square.h"

class EntityFactory
{
public:
    static Entity* CreateSquare(); // default square
    static Entity* CreateCircle(); // default circle
    static Entity* CreateSquare(float size, const sf::Color& color, float initialX, float initialY); // custom square
    static Entity* CreateCircle(float radius, const sf::Color& color, float initialX, float initialY); // custom circle

};