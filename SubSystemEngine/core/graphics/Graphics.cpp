#include "Graphics.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

void Graphics::Init(int screenWidth, int screenHeight, const std::string& windowTitle)
{
    window.create(sf::VideoMode(screenWidth, screenHeight), windowTitle);
    // Initialize any other graphics-related resources here
}

void Graphics::UpdateSubsystem()
{
    window.clear(); // Clear screen to a single color (here, white)

    // Draw a circle (for example)
    sf::CircleShape circle(50); // Create a circle with radius 50
    circle.setFillColor(sf::Color::Green); // Set the fill color to green
    circle.setPosition(375, 275); // Set the position of the circle

    // Draw the circle
    window.draw(circle);

    window.display(); // Display the rendered frame on screen
}

void Graphics::CloseWindow()
{
    window.close();
}


Graphics& Graphics::GetInstance()
{
    static Graphics instance;
    return instance;
}

sf::RenderWindow& Graphics::GetWindow()
{
    return window;
}