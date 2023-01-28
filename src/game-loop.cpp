#include "game-loop.h"

using namespace States;

void GameLoop::initialize()
{
    gameStateMachine.createNewState<States::BootState>();
}

void GameLoop::tick()
{
    gameStateMachine.tick();
}

void GameLoop::draw()
{}

void GameLoop::drawImGui()
{
    gameStateMachine.renderImGui();
}