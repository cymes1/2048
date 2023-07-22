#ifndef APP_STATE_MACHINE_H
#define APP_STATE_MACHINE_H

#include <lava.h>
#include "states/main-menu-state.h"

class AppStateMachine : public Lava::Core::BaseAppStateMachine
{
public:
    void onStateMachineLoaded() override;
};

#endif