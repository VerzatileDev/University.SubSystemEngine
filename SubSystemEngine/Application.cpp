#include "Core/Engine.h"

int main(int args, char* argv[])
{
    Engine engine;
    engine.initialize();
    engine.update();
    return 0;
}