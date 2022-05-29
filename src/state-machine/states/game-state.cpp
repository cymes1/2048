#include "game-state.h"
#include <input/input-system.h>
#include <graphics/renderer.h>
#include <states/menu-state.h>

using namespace Lava::Input;
using namespace Lava::Graphics;

namespace States
{
    GameState::GameState(GameStateMachine *stateMachine)
        : State(stateMachine),
          backTexture("res/texture/start-button.png"),
          backSprite(glm::vec3(960, 690, 0), glm::vec3(462, 92, 1), backTexture),
          backButton(backSprite, [stateMachine]() { stateMachine->createNewState<MenuState>(); })
    {}

    void GameState::initialize()
    {
        InputSystem::getInstance()->registerButton(backButton);
    }

    void GameState::tick()
    {
        if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_LEFT))
        {
            LavaEngine::Utils::Log::info("click down");
        }
        if(InputSystem::getInstance()->getKey(GLFW_KEY_LEFT))
        {
            LavaEngine::Utils::Log::info("click");
        }
        if(InputSystem::getInstance()->getKeyUp(GLFW_KEY_LEFT))
        {
            LavaEngine::Utils::Log::info("click up");
        }
        Renderer::getInstance()->draw(backSprite);
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