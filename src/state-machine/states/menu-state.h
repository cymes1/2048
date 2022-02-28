#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <state.h>
#include <game-state-machine.h>

namespace States
{
    class MenuState : public State<GameStateMachine>
    {
    public:
        explicit MenuState(GameStateMachine* stateMachine);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;
    };
}


#endif