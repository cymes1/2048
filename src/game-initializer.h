#ifndef GAME_INITIALIZER_H
#define GAME_INITIALIZER_H

#include <lava.h>

class GameInitializer : public Lava::IEngineInitializer
{
public:
    void onPreWindowCreation() override;
};

#endif