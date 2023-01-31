#include "menu-state.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <graphics/renderer.h>
#include <input/input-system.h>
#include <state-machine/states/game-state.h>
#include <cstdio>

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
        LOG_DEFAULT("enter MenuState");
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
    {
//        ImGui::ShowDemoWindow();
    }

    void MenuState::deinitialize()
    {
        InputSystem::getInstance()->clearButtons();
    }

    void MenuState::onStart()
    {
        printf("start\n");
    }

    void MenuState::onOptions()
    {
        printf("options\n");
    }

    void MenuState::onExit()
    {
        InputSystem::getInstance()->exitGame();
    }
}
