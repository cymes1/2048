#ifndef STATE_H
#define STATE_H

#include <memory/borrowed-memory.h>
#include <graphics/renderer/renderer.h>

namespace States
{
    template <typename TStateMachine>
    class State
    {
    protected:
        TStateMachine* stateMachine;
        Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer;

    public:
        explicit State(TStateMachine* stateMachine,
                       Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer)
                       : stateMachine(stateMachine), renderer(renderer)
                       {}
        virtual ~State() = default;

        virtual void initialize() = 0;
        virtual void tick() = 0;
        virtual void renderImGui() = 0;
        virtual void deinitialize() = 0;
    };
}

#endif
