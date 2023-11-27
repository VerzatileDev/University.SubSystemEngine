#pragma once

#include "Graphics.h"
#include "Physics.h"
#include "Event.h"
#include "EventHandler.h"
#include "Player.h"
#include "Ground.h"
#include "Window.h"
#include "InputSystem.h"

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
    Player player;
    Ground ground;
    InputSystem input;
};