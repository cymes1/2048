#ifndef STATE_H
#define STATE_H

namespace States
{
    template <typename TStateMachine>
    class State
    {
    protected:
        TStateMachine* stateMachine;

    public:
        explicit State(TStateMachine* stateMachine) : stateMachine(stateMachine) {}
        virtual ~State() = default;

        virtual void initialize() = 0;
        virtual void tick() = 0;
        virtual void renderImGui() = 0;
        virtual void deinitialize() = 0;
    };
}

#endif
