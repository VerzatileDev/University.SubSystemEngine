#include "EntityManager.h"
#include <iostream>

EntityManager& EntityManager::getInstance()
{
    static EntityManager instance; // Create instance on first access
    return instance;
}

void EntityManager::AddEntity(Entity* entity)
{
    entities.push_back(entity);
}

void EntityManager::UpdateEntityPosition(Entity* entity, float x, float y)
{
    if (entity)
    {
        entity->SetPosition(x, y);
        //std::cout << "Updated position for entity: " << entity->GetName() << " to (" << x << ", " << y << ")" << std::endl;
    }
}

void EntityManager::UpdateEntities()
{
    for (auto& entity : entities)
    {
        entity->Update();
    }
}

Entity* EntityManager::GetEntity(int index)
{
    if (index >= 0 && index < entities.size())
    {
        return entities[index];
    }
    return nullptr;
}

const std::vector<Entity*>& EntityManager::GetEntities() const
{
    return entities;
}

b2Vec2 EntityManager::SFMLToBox2D(const sf::Vector2f& sfmlPosition)
{
    return b2Vec2(sfmlPosition.x / 30.0f, -sfmlPosition.y / 30.0f);
}

sf::Vector2f EntityManager::Box2DToSFML(const b2Vec2& box2DPosition)
{
    return sf::Vector2f(box2DPosition.x * 30.0f, -box2DPosition.y * 30.0f);
}
