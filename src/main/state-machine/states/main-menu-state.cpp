#include "main-menu-state.h"

using namespace Lava::Core;
using namespace Lava::Graphics;

MainMenuState::MainMenuState(BaseAppStateMachine* _stateMachine, DomainManager* _domainManager)
    : Lava::Core::BaseAppState(_stateMachine, _domainManager)
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
    LOG_DEFAULT("Enter MainMenuState");
    initializeDebugLogs();

    gameDomain = domainManager->getOrCreateDomain<GameDomain>();
//        glEnable(GL_DEPTH_TEST);
/*
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(50.0f / 255.0f, 62.0f / 255.0f, 56.0f / 255.0f, 1.0f);
        Renderer::getInstance()->initialize();
*/
}

void MainMenuState::deinit()
{
    domainManager->unloadDomain<GameDomain>();
    LOG_DEFAULT("Leave MainMenuState");
}

void MainMenuState::tick()
{
    gameDomain->earlyTick();
    gameDomain->tick();
    gameDomain->lateTick();
}
