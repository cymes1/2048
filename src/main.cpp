#include <lava.h>

using namespace Lava;

class Game : public LavaGame
{};

LavaGame* Lava::createGame()
{
    return new Game();
}

