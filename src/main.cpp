#include <lava.h>
#include <lava-entry-point.h>
#include <state-machine/app-state-machine.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    explicit Game(AppStateMachine* _stateMachine)
        : LavaGame(_stateMachine)
    {}
};

LavaGame* Lava::createGame()
{
    auto* stateMachine = new AppStateMachine();

    return new Game(stateMachine);
}

