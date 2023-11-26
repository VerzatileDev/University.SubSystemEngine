#include "Graphics.h"

void Graphics::Initialize()
{
    Window::getInstance().Initialize(800, 600, "Game Window");
}

void Graphics::Update()
{
    try {
        timer.StartTimer();

        sf::RenderWindow& window = Window::getInstance().getRenderWindow();

        if (window.isOpen())
        {
            // Clearance
            window.clear(sf::Color::Blue);

            EntityManager& entityManager = EntityManager::getInstance();
            entityManager.UpdateEntities();

            const std::vector<Entity*>& entities = entityManager.GetEntities();


            // Render entities using their updated positions
            for (const auto& entity : entities)
            {
                const std::vector<Component*>& components = entity->GetComponents();

                for (const auto& component : components)
                {
                    GraphicsComponent* graphicsComponent = dynamic_cast<GraphicsComponent*>(component);
                    if (graphicsComponent)
                    {
                        graphicsComponent->Render(window); // Render the entities
                    }
                }
            }

            window.display();
        }

        timer.StopTimer();
        IsFrameRateTrackingEnabled() ? timer.GetAndPrintFrameRate() : void(); // Enabled By EventHandler / Input (Prints Frame Rate of the Current System)
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred in the Update of graphics, see the following: " << e.what() << std::endl;
    }
}

