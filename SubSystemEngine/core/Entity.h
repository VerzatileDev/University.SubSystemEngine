#pragma once

// System Libraries
#include <vector>
#include <string>
#include <iostream>
#include <memory>

// Included Files
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include "graphics/GraphicsComponent.h"

class Entity : public Component
{
public:
    Entity(const std::string& name);

    // Github Co-Pilot told me to do this To avoid Memory leaks apparently
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;
    Entity(Entity&&) = delete;
    Entity& operator=(Entity&&) = delete;
    //

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