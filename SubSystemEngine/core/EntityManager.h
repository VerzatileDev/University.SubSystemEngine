#pragma once

#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class EntityManager
{
public:
    static EntityManager& getInstance();

    void AddEntity(Entity* entity);
    void UpdateEntities();
    Entity* GetEntity(int index);
    const std::vector<Entity*>& GetEntities() const;

    void UpdateEntityPosition(Entity* entity, float x, float y);
    EntityManager() = default;
private:
    std::vector<Entity*> entities;
};