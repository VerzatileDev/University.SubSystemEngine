#include "EntityManager.h"
#include <iostream>

EntityManager& EntityManager::getInstance() {
    static EntityManager instance;
    return instance;
}

void EntityManager::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void EntityManager::UpdateEntities() {
    for (auto& entity : entities) {
        entity->Update();
    }
}

Entity* EntityManager::GetEntity(int index) {
    if (index >= 0 && index < entities.size()) {
        return entities[index];
    }
    return nullptr;
}

const std::vector<Entity*>& EntityManager::GetEntities() const {
    return entities;
}

void EntityManager::UpdateEntityPosition(Entity* entity, float x, float y) {
    if (entity) {
        entity->SetPosition(x, y);
    }
}
