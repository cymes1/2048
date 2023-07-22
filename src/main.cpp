#include <lava.h>
#include <lava-entry-point.h>
#include <game-initializer.h>
#include <game-loop.h>
#include <state-machine/app-state-machine.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    explicit Game(GameInitializer* _gameInitializer, GameLoop* _gameLoop, AppStateMachine* _stateMachine)
        : LavaGame(_gameInitializer, _gameLoop, _stateMachine)
    {}
};

LavaGame* Lava::createGame()
{
    auto* gameInitializer = new GameInitializer();
    auto* gameLoop = new GameLoop();
    auto* stateMachine = new AppStateMachine();

    return new Game(gameInitializer, gameLoop, stateMachine);
}

