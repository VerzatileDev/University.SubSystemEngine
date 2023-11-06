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
}

void Graphics::UpdateSubsystem()
{
    // Get current time
    auto timeNow = std::chrono::high_resolution_clock::now();

    // Calculate delta time
    std::chrono::duration<float> duration = std::chrono::duration_cast<std::chrono::duration<float>>(timeNow - timeThen);
    deltaTime = duration.count();

    // Display DATA
    window.clear();

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375, 275);
    window.draw(circle);
    window.display();

    // Update previous time
    timeThen = timeNow;
}

void Graphics::CloseWindow()
{
    window.close();
}

sf::RenderWindow& Graphics::GetWindow()
{
    return window;
}

float Graphics::GetDeltaTime()
{
    return deltaTime ;
}
