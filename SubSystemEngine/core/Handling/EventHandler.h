#pragma once

// Included Files
#include "Event.h"
#include "../Entities/Player.h"
#include "../SubSystem.h"

// System Libraries
#include <vector>
#include <iostream>
#include <functional> 
#include "../Physics/ContactListener.h"


class EventHandler {
public:
    EventHandler();
    EventHandler(SubSystem& subsystem);
    ~EventHandler();
    static EventHandler& getInstance();
    void AddEvent(const Event& event);
    void ClearEvents();
    void ProcessEvents();
    bool IsRunning();
    void setContactListener(ContactListener& contactListener);
private:
    std::vector<Event> eventQueue;
    bool running = true;
    Player& player = Player::getInstance();
    bool canJump = true;
    ContactListener* contactListener;
    SubSystem* subsystemRef = nullptr;
};
