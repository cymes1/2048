#ifndef BOOT_STATE_H
#define BOOT_STATE_H

#include <memory/borrowed-memory.h>
#include <graphics/renderer/renderer.h>
#include <state-machine/state.h>
#include <state-machine/game-state-machine.h>

namespace States
{
    class BootState : public State<GameStateMachine>
    {
    public:
        explicit BootState(GameStateMachine* stateMachine,
                           Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;

    private:
        void initializeDebugLogs();
    };
}


#endif