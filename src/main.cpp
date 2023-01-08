#include <lava.h>
#include <lava-entry-point.h>
#include <game-initializer.h>
#include <game-loop.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    explicit Game(GameInitializer* gameInitializer, GameLoop* gameLoop)
        : LavaGame(gameInitializer, gameLoop)
    {}
};

LavaGame* Lava::createGame()
{
    auto* gameInitializer = new GameInitializer();
    auto* gameLoop = new GameLoop();

    return new Game(gameInitializer, gameLoop);
}

