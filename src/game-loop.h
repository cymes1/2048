#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <lava.h>

class GameLoop : public Lava::LavaMainLoop
{
protected:
    void tick() override;
    void draw() override;
    void drawImGui() override;
};

#endif