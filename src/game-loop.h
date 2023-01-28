#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <lava.h>
#include <state-machine/game-state-machine.h>
#include <state-machine/states/boot-state.h>

class GameLoop : public Lava::LavaMainLoop
{
private:
    States::GameStateMachine gameStateMachine;

protected:
    void initialize() override;
    void tick() override;
    void draw() override;
    void drawImGui() override;
};

#endif