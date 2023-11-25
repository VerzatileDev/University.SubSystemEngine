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
    Entity(const std::string& name);

    void AddComponent(Component* component);
    void Update();  // Add an Update function to update all components

    void SetPosition(float x, float y);
    const sf::Vector2f& GetPosition() const;

    const std::string& GetName() const;
    const std::vector<Component*>& GetComponents() const;

private:
    std::vector<Component*> components;
    sf::Vector2f position;
    std::string name;
};