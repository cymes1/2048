#ifndef BOOT_STATE_H
#define BOOT_STATE_H

#include <state.h>
#include <game-state-machine.h>

namespace States
{
    class BootState : public State<GameStateMachine>
    {
    public:
        explicit BootState(GameStateMachine* stateMachine);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;
    };
}


#endif