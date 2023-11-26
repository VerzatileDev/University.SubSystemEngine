#pragma once
#include "Graphics.h"
#include "Physics.h"
#include "Entity.h" // Player
#include "StaticEntity.h"
#include "Window.h"
#include "InputSystem.h"
#include "EventHandler.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void initialize();
    void update();
private:
    Graphics graphics;
    Physics physics;
    InputSystem input;

    Entity player;
    StaticEntity staticEntity;
};