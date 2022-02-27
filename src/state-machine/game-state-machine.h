#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include <state.h>

namespace States
{
    class GameStateMachine
    {
    private:
        State<GameStateMachine>* state;

    public:
        GameStateMachine();

        void tick();
        void deinitialize();

        template <class TState>
        void initialize()
        {
            createNewState<TState>();
        }

        template <class TState>
        void createNewState()
        {
            if(state != nullptr)
            {
                state->deinitialize();
                delete state;
            }

            state = new TState(this);
            state->initialize();
        }
    };
}

#endif