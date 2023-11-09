#pragma once

// Included Files
#include "Graphics/Graphics.h"
#include "graphics/Window.h"
#include "Inputs/InputSystem.h"
#include "EventHandler.h"

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
    //Physics physics;
    //Audio audio;
    //Network network;
    EventHandler eventHandler;
};