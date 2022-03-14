#include "menu-state.h"
#include <graphics/renderer.h>

using namespace Lava::Graphics;

namespace States
{
    MenuState::MenuState(GameStateMachine *stateMachine)
        : State(stateMachine),
          pikachuTexture("res/texture/pikachu.png"),
          gerwantTexture("res/texture/happy-gerwant.png"),
          sprite1(glm::vec3(600, 500, 0), glm::vec3(400, 400, 1), pikachuTexture),
          sprite2(glm::vec3(1000, 1000, 0), glm::vec3(200, 200, 1), gerwantTexture)
    {}

    void MenuState::initialize()
    {}

    void MenuState::tick()
    {
        Renderer::getInstance()->draw(sprite1);
        Renderer::getInstance()->draw(sprite2);
    }

    void MenuState::renderImGui()
    {}

    void MenuState::deinitialize()
    {}
}
