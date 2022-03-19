#include "menu-state.h"
#include <graphics/renderer.h>

using namespace Lava::Graphics;

namespace States
{
    MenuState::MenuState(GameStateMachine *stateMachine)
        : State(stateMachine),
          startButtonTexture("res/texture/start-button.png"),
          optionsButtonTexture("res/texture/options-button.png"),
          exitButtonTexture("res/texture/exit-button.png"),
          startSprite(glm::vec3(960, 690, 0), glm::vec3(462, 92, 1), startButtonTexture),
          optionsSprite(glm::vec3(960, 540, 0), glm::vec3(462, 92, 1), optionsButtonTexture),
          exitSprite(glm::vec3(960, 390, 0), glm::vec3(462, 92, 1), exitButtonTexture)
    {}

    void MenuState::initialize()
    {}

    void MenuState::tick()
    {
        Renderer::getInstance()->draw(startSprite);
        Renderer::getInstance()->draw(optionsSprite);
        Renderer::getInstance()->draw(exitSprite);
    }

    void MenuState::renderImGui()
    {}

    void MenuState::deinitialize()
    {}
}
