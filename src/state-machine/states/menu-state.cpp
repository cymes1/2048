#include "menu-state.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <graphics/renderer/renderer.h>
#include <input/input-system.h>
#include <state-machine/states/game-state.h>

using namespace Lava::Core;
using namespace Lava::Memory;
using namespace Lava::Graphics;
using namespace Lava::Input;

namespace States
{
    MenuState::MenuState(BaseAppStateMachine* stateMachine)
        : BaseAppState(stateMachine),
          startButtonTexture("res/texture/start-button.png"),
          optionsButtonTexture("res/texture/options-button.png"),
          exitButtonTexture("res/texture/exit-button.png"),
          startSprite(glm::vec3(729, 690, 0), glm::vec3(462, 92, 1), startButtonTexture),
          optionsSprite(glm::vec3(729, 540, 0), glm::vec3(462, 92, 1), optionsButtonTexture),
          exitSprite(glm::vec3(729, 390, 0), glm::vec3(462, 92, 1), exitButtonTexture),
          startButton(startSprite, [stateMachine]() { stateMachine->goToState<GameState>(); }),
          optionsButton(optionsSprite, onOptions),
          exitButton(exitSprite, onExit)
    {
    }

    void MenuState::init()
    {
        LOG_DEFAULT("enter MenuState");
        InputSystem::getInstance()->registerButton(startButton);
        InputSystem::getInstance()->registerButton(optionsButton);
        InputSystem::getInstance()->registerButton(exitButton);
    }

    void MenuState::tick()
    {
//        renderer.get().draw(startSprite);
//        renderer.get().draw(optionsSprite);
//        renderer.get().draw(exitSprite);
    }

    void MenuState::deinit()
    {
        InputSystem::getInstance()->clearButtons();
    }

    void MenuState::onStart()
    {
        LOG_DEFAULT("start");
    }

    void MenuState::onOptions()
    {
        LOG_DEFAULT("options");
    }

    void MenuState::onExit()
    {
        InputSystem::getInstance()->exitGame();
    }
}
