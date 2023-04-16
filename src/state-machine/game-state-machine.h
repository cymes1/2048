#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include <memory/borrowed-memory.h>
#include <graphics/renderer/renderer.h>
#include <state-machine/state.h>

namespace States
{
    class GameStateMachine
    {
    private:
        Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer;
        State<GameStateMachine>* state;

    public:
        GameStateMachine();

        void initialize(Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer);
        void tick();
        void renderImGui();
        void deinitialize();

        template <class TState>
        void createNewState()
        {
            if(state != nullptr)
            {
                state->deinitialize();
                delete state;
            }

            state = new TState(this, renderer);
            state->initialize();
        }
    };
}

#endif