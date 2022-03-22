#include "menu-state.h"
#include <graphics/renderer.h>
#include <input/input-system.h>
#include <utils/log.h>
#include <states/game-state.h>

using namespace Lava::Graphics;
using namespace Lava::Input;

namespace States
{
    MenuState::MenuState(GameStateMachine *stateMachine)
        : State(stateMachine),
          startButtonTexture("res/texture/start-button.png"),
          optionsButtonTexture("res/texture/options-button.png"),
          exitButtonTexture("res/texture/exit-button.png"),
          startSprite(glm::vec3(960, 690, 0), glm::vec3(462, 92, 1), startButtonTexture),
          optionsSprite(glm::vec3(960, 540, 0), glm::vec3(462, 92, 1), optionsButtonTexture),
          exitSprite(glm::vec3(960, 390, 0), glm::vec3(462, 92, 1), exitButtonTexture),
          startButton(startSprite, [stateMachine]() { stateMachine->createNewState<GameState>(); }),
          optionsButton(optionsSprite, onOptions),
          exitButton(exitSprite, onExit)
    {
    }

    void MenuState::initialize()
    {
        InputSystem::getInstance()->registerButton(startButton);
        InputSystem::getInstance()->registerButton(optionsButton);
        InputSystem::getInstance()->registerButton(exitButton);
    }

    void MenuState::tick()
    {
        Renderer::getInstance()->draw(startSprite);
        Renderer::getInstance()->draw(optionsSprite);
        Renderer::getInstance()->draw(exitSprite);
    }

    void MenuState::renderImGui()
    {}

    void MenuState::deinitialize()
    {
        InputSystem::getInstance()->clearButtons();
    }

    void MenuState::onStart()
    {
        LavaEngine::Utils::Log::info("start");
    }

    void MenuState::onOptions()
    {
        LavaEngine::Utils::Log::info("options");
    }

    void MenuState::onExit()
    {
        InputSystem::getInstance()->exitGame();
    }
}
