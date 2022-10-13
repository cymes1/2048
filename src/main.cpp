#include <lava.h>
#include <lava-entry-point.h>
#include <game-initializer.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    explicit Game(GameInitializer* gameInitializer)
        : LavaGame(gameInitializer)
    {}
};

LavaGame* Lava::createGame()
{
    auto* gameInitializer = new GameInitializer();

    return new Game(gameInitializer);
}

