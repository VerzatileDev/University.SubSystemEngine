#include "EntityManager.h"

EntityManager& EntityManager::getInstance() {
    static EntityManager instance;
    return instance;
}

void EntityManager::addEntity(Entity* entity) {
    entities.push_back(entity);
}

void EntityManager::removeEntity(Entity* entity) {
    // Remove the entity from the vector (you might want to implement this)
}

void EntityManager::updateEntities() {
    for (auto& entity : entities) {
        entity->update();
    }
}

void EntityManager::drawEntities() {
    for (const auto& entity : entities) {
        entity->draw(Window::getInstance().getWindow());
    }
}