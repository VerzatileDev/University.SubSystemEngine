#pragma once

#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class EntityManager
{
public:
    static EntityManager& getInstance();
    EntityManager() = default;
    void AddEntity(Entity* entity);
    void UpdateEntities();
    void UpdateEntityPosition(Entity* entity, float x, float y);
    Entity* GetEntity(int index);
    const std::vector<Entity*>& GetEntities() const; // Add this method
    b2Vec2 SFMLToBox2D(const sf::Vector2f& sfmlPosition);
    sf::Vector2f Box2DToSFML(const b2Vec2& box2DPosition);

private:
    std::vector<Entity*> entities;
};