#include <graphics/window.h>
#include <game-state-machine.h>
#include <states/boot-state.h>

using namespace LavaEngine::Graphics;
using namespace States;

int main()
{
    GameStateMachine stateMachine;
    Window window(800, 600, "2048");

    stateMachine.initialize<BootState>();
    while(!glfwWindowShouldClose(window.handle()))
    {
        glfwPollEvents();
        glClearColor(0.5f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        stateMachine.tick();
        glfwSwapBuffers(window.handle());
    }
    stateMachine.deinitialize();
    return 0;
}