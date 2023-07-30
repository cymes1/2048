#include <lava.h>
#include <lava-entry-point.h>
#include <game-loop.h>
#include <state-machine/app-state-machine.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    explicit Game(GameLoop* _gameLoop, AppStateMachine* _stateMachine)
        : LavaGame(_gameLoop, _stateMachine)
    {}
};

LavaGame* Lava::createGame()
{
    auto* gameLoop = new GameLoop();
    auto* stateMachine = new AppStateMachine();

    return new Game(gameLoop, stateMachine);
}

