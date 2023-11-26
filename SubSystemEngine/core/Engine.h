#pragma once

// Included Files
#include "Graphics/Graphics.h"
#include "graphics/Window.h"
#include "Inputs/InputSystem.h"
#include "physics/Physics.h"
#include "EventHandler.h"

#include "EntityFactory.h"
#include "EntityManager.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void Initialize();
    void Update();

private:
    InputSystem inputSystem;
    Graphics graphics;
    Physics physics;

    EntityFactory entityFactory; // Entity Factory Reference Holder
    EntityManager entityManager; // Entity Manager Reference Holder
    //Audio audio;
    //Network network;
    EventHandler eventHandler;
};