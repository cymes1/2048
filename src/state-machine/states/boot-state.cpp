#include "boot-state.h"
#include <GL/glew.h>
#include <utils/log.h>
#include <states/menu-state.h>

namespace States
{
    BootState::BootState(GameStateMachine *stateMachine)
        : State(stateMachine)
    {}

    void BootState::initialize()
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.4f, 0.3f, 0.5f, 1.0f);
    }

    void BootState::tick()
    {
        stateMachine->createNewState<MenuState>();
    }

    void BootState::renderImGui()
    {
    }

    void BootState::deinitialize()
    {
        LavaEngine::Utils::Log::info("deinitialize boot state");
    }
}