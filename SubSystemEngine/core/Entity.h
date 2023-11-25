#pragma once

// System Libraries
#include <vector>
#include <string>
#include <iostream>

// Included Files
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include "graphics/GraphicsComponent.h"

class Entity : public Component
{
public:
    void AddComponent(Component* component);
    void Update() override;
    void SetPosition(float x, float y);
    const sf::Vector2f& GetPosition() const;
    const std::vector<Component*>& GetComponents() const;

    const std::string GetName() const;

    // Set a name for the entity
    void SetName(const std::string& name);
private:
    std::vector<Component*> components;
    sf::Vector2f position;
    std::string name;
};