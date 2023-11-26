#pragma once

#include <vector>
#include "Entity.h"
#include "Window.h"

class EntityManager {
public:
    static EntityManager& getInstance();

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    void updateEntities();
    void drawEntities();

private:
    EntityManager() = default;
    ~EntityManager() = default;

    std::vector<Entity*> entities;
};