#include "app-state-machine.h"

#include "main/state-machine/states/main-menu-state.h"

void AppStateMachine::onStateMachineLoaded()
{
    goToState<MainMenuState>();
}
