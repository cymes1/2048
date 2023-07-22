#include "main-menu-state.h"

MainMenuState::MainMenuState(Lava::Core::BaseAppStateMachine* _stateMachine)
    : Lava::Core::BaseAppState(_stateMachine)
{}

MainMenuState::~MainMenuState() = default;

void MainMenuState::init()
{
    LOG_DEFAULT("Enter MainMenuState");
}

void MainMenuState::deinit()
{
    LOG_DEFAULT("Leave MainMenuState");
}

void MainMenuState::tick()
{}
