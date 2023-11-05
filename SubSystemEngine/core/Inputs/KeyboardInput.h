#pragma once

// Included Libraries
#include <SDL/SDL.h>
#include <iostream>

// Included Files
#include "../core/Engine.h"
#include "../core/Event.h"
#include "../core/EventHandler.h"

class KeyboardInput
{
public:
	static void PollEvents();
};