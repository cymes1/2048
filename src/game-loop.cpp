#include "game-loop.h"

using namespace Lava::Memory;
using namespace Lava::Graphics;
using namespace States;

void GameLoop::initialize(BorrowedMemory<Renderer> renderer)
{
    gameStateMachine.initialize(renderer);
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