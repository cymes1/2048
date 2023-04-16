#include "game-state.h"
#include <input/input-system.h>
#include <audio/audio-system.h>
#include <graphics/renderer/renderer.h>
#include <state-machine/states/menu-state.h>

using namespace Lava::Audio;
using namespace Lava::Memory;
using namespace Lava::Graphics;
using namespace Lava::Input;

namespace States
{
    GameState::GameState(GameStateMachine *stateMachine, BorrowedMemory<Renderer> renderer)
        : State(stateMachine, renderer),
          backTexture("res/texture/start-button.png"),
          backSprite(glm::vec3(960, 690, 0), glm::vec3(462, 92, 1), backTexture),
          backButton(backSprite, [stateMachine]() { stateMachine->createNewState<MenuState>(); }),
          boardManager(renderer)
    {}

    void GameState::initialize()
    {
        InputSystem::getInstance()->registerButton(backButton);
        boardManager.init();
    }

    void GameState::tick()
    {
        boardManager.tick();

        renderer.get().draw(backSprite);

        if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_ESCAPE))
        {
            AudioSystem::getInstance()->playSound();
        }
    }
    
    void GameState::renderImGui()
    {}

    void GameState::deinitialize()
    {
        InputSystem::getInstance()->clearButtons();
    }

    void GameState::onBack()
    {
    }
}