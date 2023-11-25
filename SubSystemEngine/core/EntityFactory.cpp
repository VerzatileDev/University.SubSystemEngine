#include "EntityFactory.h"


void EntityFactory::CreateSquare(Entity* entity, float size, const sf::Color& color, float initialX, float initialY)
{
    if (entity)
    {
        entity->AddComponent(new Square(size, color));
        entity->SetPosition(initialX, initialY);
    }
}

void EntityFactory::CreateCircle(Entity* entity, float radius, const sf::Color& color, float initialX, float initialY)
{
    if (entity)
    {
        entity->AddComponent(new Circle(radius, color));
        entity->SetPosition(initialX, initialY);
    }
}