#include "boot-state.h"
#include <GL/glew.h>
#include <utils/log.h>
#include <states/menu-state.h>
#include <debug/debug-callback.h>

using namespace Lava::Debug;

namespace States
{
    BootState::BootState(GameStateMachine *stateMachine)
        : State(stateMachine)
    {}

    void BootState::initialize()
    {
        initializeDebugLogs();
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

    void BootState::initializeDebugLogs()
    {
        DebugMessageControlInfo messageControlInfo = {};
        messageControlInfo.source = GL_DONT_CARE;
        messageControlInfo.type = GL_DONT_CARE;
        messageControlInfo.severity = GL_DEBUG_SEVERITY_NOTIFICATION;
        messageControlInfo.count = 0;
        messageControlInfo.ids = nullptr;
        messageControlInfo.enabled = GL_FALSE;
        initializeDebugMode(messageControlInfo);
    }
}