#include "Entity.h"

void Entity::AddComponent(Component* component)
{
    components.push_back(component);
}

const sf::Vector2f& Entity::GetPosition() const
{
    return position;
}

const std::vector<Component*>& Entity::GetComponents() const
{
    return components;
}

void Entity::Update()
{
    for (auto& component : components)
    {
        component->Update();
    }
}

void Entity::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;

    for (auto& component : components)
    {
        GraphicsComponent* graphicsComponent = dynamic_cast<GraphicsComponent*>(component);
        if (graphicsComponent)
        {
            graphicsComponent->SetPosition(x, y);
        }
    }
    //std::cout << "Entity Position Set: (" << x << ", " << y << ")" << std::endl; // Debug
}

const std::string Entity::GetName() const  // Change here
{
    return name;
}

void Entity::SetName(const std::string& newName)
{
    name = newName;
}