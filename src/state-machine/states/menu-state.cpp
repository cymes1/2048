#include "menu-state.h"
#include <graphics/renderer.h>

using namespace Lava::Graphics;

namespace States
{
    MenuState::MenuState(GameStateMachine *stateMachine)
            : State(stateMachine)
    {}

    void MenuState::initialize()
    {}

    void MenuState::tick()
    {
        Renderer::getInstance()->draw();
    }

    void MenuState::renderImGui()
    {}

    void MenuState::deinitialize()
    {}
}
