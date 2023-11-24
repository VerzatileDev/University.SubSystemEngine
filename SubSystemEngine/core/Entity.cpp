#include "Entity.h"

void Entity::AddComponent(Component* component)
{
	components.push_back(component);
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
}
