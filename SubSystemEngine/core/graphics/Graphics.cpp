#include "Graphics.h"

void Graphics::Initialize()
{
    Entity* player = entityFactory.CreateSquare(50.0f, sf::Color::Green, 100.0f, 100.0f);
    entities.push_back(player);

    Entity* player2 = entityFactory.CreateCircle();
    entities.push_back(player2);
}

void Graphics::Update()
{
    try {
        timer.StartTimer(); // Running by Default

        sf::RenderWindow& window = Window::getInstance().getRenderWindow();

        if (window.isOpen()) 
        {
            // Clearance
            window.clear(sf::Color::Blue);

            for (const auto& entity : entities)
            {
                const std::vector<Component*>& components = entity->GetComponents();

                for (const auto& component : components)
                {
                    GraphicsComponent* graphicsComponent = dynamic_cast<GraphicsComponent*>(component);
                    if (graphicsComponent)
                    {
                        graphicsComponent->Render(window);
                    }
                }
            }

            window.display();
        }

        timer.StopTimer();
        IsFrameRateTrackingEnabled() ? timer.GetAndPrintFrameRate() : void(); // Enabled By EventHandler / Input
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occured in the Update of graphics, see the following: " << e.what() << std::endl;
    }
}

