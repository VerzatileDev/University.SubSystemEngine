#pragma once
#include <SDL/SDL.h>
#include "../core/Engine.h"
#include "../core/Event.h"
#include "../core/EventHandler.h"
#include <iostream>

class KeyboardInput
{
public:
	static void PollEvents();
};