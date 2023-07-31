#include "main-menu-state.h"

MainMenuState::MainMenuState(Lava::Core::BaseAppStateMachine* _stateMachine)
    : Lava::Core::BaseAppState(_stateMachine)
{}

MainMenuState::~MainMenuState() = default;

void initializeDebugLogs()
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

void MainMenuState::init()
{
    initializeDebugLogs();
//        glEnable(GL_DEPTH_TEST);
/*
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(50.0f / 255.0f, 62.0f / 255.0f, 56.0f / 255.0f, 1.0f);
        Renderer::getInstance()->initialize();
*/
    LOG_DEFAULT("Enter MainMenuState");
}

void MainMenuState::deinit()
{
    LOG_DEFAULT("Leave MainMenuState");
}

void MainMenuState::tick()
{}
