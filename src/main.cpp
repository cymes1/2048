#include <graphics/window.h>
#include <input/input-system.h>
#include <game-state-machine.h>
#include <states/boot-state.h>

using namespace Lava::Graphics;
using namespace Lava::Input;
using namespace States;

int main()
{
    GameStateMachine stateMachine;
    Window window("2048");

    InputSystem::getInstance()->initialize(window);
    stateMachine.createNewState<BootState>();
    while(!glfwWindowShouldClose(window.getHandle()))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        stateMachine.tick();
        stateMachine.renderImGui();
        glfwSwapBuffers(window.getHandle());

        if(InputSystem::getInstance()->getShouldExit())
            glfwSetWindowShouldClose(window.getHandle(), 1);
    }
    stateMachine.deinitialize();
    return 0;
}