#include "game-state-machine.h"

namespace States
{
    GameStateMachine::GameStateMachine()
        : state(nullptr)
    {}

    void GameStateMachine::tick()
    {
        state->tick();
    }

    void GameStateMachine::deinitialize()
    {
        if(state != nullptr)
            state->deinitialize();
    }
}