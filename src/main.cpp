#include <lava.h>

using namespace Lava;

class Game : public LavaGame
{
public:
    Game(int args, char** argv)
        : LavaGame(args, argv)
    {}
};

LavaGame* Lava::createGame(int args, char** argv)
{
    return new Game(args, argv);
}

