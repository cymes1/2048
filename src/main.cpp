#include <graphics/window.h>
#include <game-state-machine.h>
#include <states/boot-state.h>

using namespace LavaEngine::Graphics;
using namespace States;

int main()
{
    GameStateMachine stateMachine;
    Window window("2048");

    stateMachine.createNewState<BootState>();
    while(!glfwWindowShouldClose(window.handle()))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        stateMachine.tick();
        stateMachine.renderImGui();
        glfwSwapBuffers(window.handle());
    }
    stateMachine.deinitialize();
    return 0;
}