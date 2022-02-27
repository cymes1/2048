#include "boot-state.h"
#include <utils/log.h>
#include <states/menu-state.h>

namespace States
{
    BootState::BootState(GameStateMachine *stateMachine)
        : State(stateMachine)
    {}

    void BootState::initialize()
    {
        LavaEngine::Utils::Log::info("initialize boot state");
    }

    void BootState::tick()
    {
        stateMachine->createNewState<MenuState>();
    }

    void BootState::deinitialize()
    {
        LavaEngine::Utils::Log::info("deinitialize boot state");
    }
}