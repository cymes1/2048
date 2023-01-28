#include "boot-state.h"
#include <state-machine/states/menu-state.h>
#include <lava.h>
//#include <debug/debug-callback.h>
//#include <graphics/renderer.h>

//using namespace Lava::Debug;
//using namespace Lava::Graphics;

namespace States
{
    BootState::BootState(GameStateMachine *stateMachine)
        : State(stateMachine)
    {}

    void BootState::initialize()
    {
        initializeDebugLogs();
//        glEnable(GL_DEPTH_TEST);
/*
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(50.0f / 255.0f, 62.0f / 255.0f, 56.0f / 255.0f, 1.0f);
        Renderer::getInstance()->initialize();
*/
        LOG_DEFAULT("enter BootState");
    }

    void BootState::tick()
    {
        stateMachine->createNewState<MenuState>();
    }

    void BootState::renderImGui()
    {}

    void BootState::deinitialize()
    {}

    void BootState::initializeDebugLogs()
    {
/*
        DebugMessageControlInfo messageControlInfo = {};
        messageControlInfo.source = GL_DONT_CARE;
        messageControlInfo.type = GL_DONT_CARE;
        messageControlInfo.severity = GL_DEBUG_SEVERITY_NOTIFICATION;
        messageControlInfo.count = 0;
        messageControlInfo.ids = nullptr;
        messageControlInfo.enabled = GL_FALSE;
        initializeDebugMode(messageControlInfo);
*/
    }
}