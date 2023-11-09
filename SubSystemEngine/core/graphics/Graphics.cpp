#include "Graphics.h"

void Graphics::Initialize()
{}

void Graphics::Update()
{
    try {
        timer.StartTimer();

        sf::RenderWindow& window = Window::getInstance().getRenderWindow();
        if (window.isOpen()) {
            window.clear(sf::Color::Blue);

            sf::CircleShape circle(50);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(100, 100);

            window.draw(circle);
            window.display();
        }

        timer.StopTimer();
        IsFrameRateTrackingEnabled() ? timer.GetAndPrintFrameRate() : void(); // Enabled By EventHandler Input
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
