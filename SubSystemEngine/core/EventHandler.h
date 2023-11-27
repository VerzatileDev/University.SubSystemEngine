#pragma once

// Included Files
#include "Event.h"

// System Libraries
#include <vector>
#include <iostream>
#include <functional> 


class EventHandler {
public:
    static EventHandler& getInstance();
    void AddEvent(const Event& event);
    void ClearEvents();
    void ProcessEvents();
    bool IsRunning();

    void setPlayerMoveLeftCallback(std::function<void()> callback);
    void setPlayerMoveRightCallback(std::function<void()> callback);
private:
    std::vector<Event> eventQueue;
    bool running = true;

    std::function<void()> playerMoveLeftCallback;
    std::function<void()> playerMoveRightCallback;
};
