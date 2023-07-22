#include "app-state-machine.h"

#include "states/main-menu-state.h"

void AppStateMachine::onStateMachineLoaded()
{
    goToState<MainMenuState>();
}
