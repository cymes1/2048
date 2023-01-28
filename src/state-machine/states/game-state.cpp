#include "game-state.h"
#include <input/input-system.h>
#include <audio/audio-system.h>
#include <graphics/renderer.h>
#include <state-machine/states/menu-state.h>

using namespace Lava::Audio;
using namespace Lava::Graphics;
using namespace Lava::Input;

namespace States
{
    GameState::GameState(GameStateMachine *stateMachine)
        : State(stateMachine),
          backTexture("res/texture/start-button.png"),
          backSprite(glm::vec3(960, 690, 0), glm::vec3(462, 92, 1), backTexture),
          backButton(backSprite, [stateMachine]() { stateMachine->createNewState<MenuState>(); }),
          boardManager()
    {}

    void GameState::initialize()
    {
        InputSystem::getInstance()->registerButton(backButton);
        boardManager.init();
    }

    void GameState::tick()
    {
        boardManager.tick();

        Renderer::getInstance()->draw(backSprite);

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