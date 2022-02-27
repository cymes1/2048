#include "menu-state.h"
#include <utils/log.h>

namespace States
{
    MenuState::MenuState(GameStateMachine *stateMachine)
            : State(stateMachine)
    {}

    void MenuState::initialize()
    {
        LavaEngine::Utils::Log::info("initialize menu state");
    }

    void MenuState::tick()
    {
    }

    void MenuState::deinitialize()
    {
        LavaEngine::Utils::Log::info("deinitialize menu state");
    }
}
