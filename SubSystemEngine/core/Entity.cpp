#include "Entity.h"

Entity::Entity(const std::string& name) : name(name) {}

void Entity::AddComponent(Component* component) {
    components.push_back(component);
}

void Entity::Update() {
    for (auto& component : components) {
        component->Update();
    }
}

void Entity::SetPosition(float x, float y) {
    position.x = x;
    position.y = y;

    for (auto& component : components) {
        GraphicsComponent* graphicsComponent = dynamic_cast<GraphicsComponent*>(component);
        if (graphicsComponent) {
            graphicsComponent->SetPosition(x, y);
        }
    }
}

const sf::Vector2f& Entity::GetPosition() const {
    return position;
}

const std::string& Entity::GetName() const {
    return name;
}

const std::vector<Component*>& Entity::GetComponents() const
{
    return components;
}