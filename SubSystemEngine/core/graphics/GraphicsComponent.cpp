#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent()
{}

GraphicsComponent::GraphicsComponent(const sf::Vector2f& initialPosition) : position(initialPosition)
{}

GraphicsComponent::~GraphicsComponent()
{}

void GraphicsComponent::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;
    //std::cout<< position.x << " " << position.y << std::endl; // Debug
}

void GraphicsComponent::Update()
{
}
