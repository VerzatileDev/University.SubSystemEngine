#pragma once

#include "Entity.h"
#include "graphics/Primatives/Circle.h"
#include "graphics/Primatives/Square.h"

class EntityFactory
{
public:

    void CreateSquare(Entity* entity, float size, const sf::Color& color, float initialX, float initialY);
    void CreateCircle(Entity* entity, float radius, const sf::Color& color, float initialX, float initialY);

};