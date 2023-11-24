#pragma once

// System Libraries
#include <vector>

// Included Files
#include "Component.h"
#include <SFML/System/Vector2.hpp>

class Entity : public Component
{
public:
    void AddComponent(Component* component); // Add a new component to the entity
    void Update() override; // Update all components entities
    void SetPosition(float x, float y);
    sf::Vector2f position;

    const std::vector<Component*>& GetComponents() const;
private:
    std::vector<Component*> components; // Data storage
};