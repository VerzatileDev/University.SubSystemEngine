#pragma once

// included FIles
#include "../Component.h"
#include <SFML/Graphics.hpp>

// System Libraries
#include <iostream>

class GraphicsComponent : public Component
{
public:
    GraphicsComponent(); // Default Constructor
    GraphicsComponent(const sf::Vector2f& initialPosition); // Constructor with initial position
    virtual ~GraphicsComponent();

    virtual void Render(sf::RenderWindow& window) = 0; // Render the entity Defined by Primative
    virtual void SetPosition(float x, float y); // Entity Position updates

    // Add this virtual function
    virtual void Update();

protected:
    sf::Vector2f position; // Entity Position
};