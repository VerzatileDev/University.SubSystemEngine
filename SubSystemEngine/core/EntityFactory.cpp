#include "EntityFactory.h"

Entity* EntityFactory::CreateSquare()
{
    Entity* entity = new Entity();
    Square* squareComponent = new Square();
    entity->AddComponent(squareComponent);
    entity->Update();

    return entity;
}

Entity* EntityFactory::CreateCircle()
{
    Entity* entity = new Entity();
    Circle* circleComponent = new Circle();
    entity->AddComponent(circleComponent);
    entity->Update();

    return entity;
}

Entity* EntityFactory::CreateSquare(float size, const sf::Color& color, float initialX, float initialY)
{
    Entity* entity = new Entity();
    Square* squareComponent = new Square(size, color);
    entity->AddComponent(squareComponent);
    squareComponent->SetPosition(initialX, initialY); 
    entity->Update();

    return entity;
}

Entity* EntityFactory::CreateCircle(float radius, const sf::Color& color, float initialX, float initialY)
{
    Entity* entity = new Entity();
    Circle* circleComponent = new Circle(radius, color);
    entity->AddComponent(circleComponent);
    circleComponent->SetPosition(initialX, initialY);
    entity->Update();

    return entity;
}