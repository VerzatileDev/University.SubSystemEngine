#include "Graphics.h"

void Graphics::Initialize()
{
    Entity* player = new Entity("Player1");
    entityFactory.CreateSquare(player, 50.0f, sf::Color::Green, 100.0f, 100.0f);
    entityManager.AddEntity(player);
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

            entityManager.UpdateEntities();

            const std::vector<Entity*>& entities = entityManager.GetEntities();

            // Update position for all entities
            for (const auto& entity : entities)
            {
                entityManager.UpdateEntityPosition(entity, entity->GetPosition().x + 0.01f, entity->GetPosition().y);
            }


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

