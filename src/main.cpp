#include <graphics/window.h>
#include <input/input-system.h>
#include <time/time.h>
#include <game-state-machine.h>
#include <states/boot-state.h>

using namespace Lava::Graphics;
using namespace Lava::Input;
using namespace Lava::Time;
using namespace States;

void updateInput();

int main()
{
    GameStateMachine stateMachine;
    Window window("2048");

    InputSystem::getInstance()->initialize(window);
    Time::getInstance()->initialize();
    stateMachine.createNewState<BootState>();
    while(!glfwWindowShouldClose(window.getHandle()))
    {
        updateInput();

/*
        std::vector <int> elements;
        for (auto i = 0; i < 100'000'000; ++i)
            elements.push_back(i);
*/
        Time::getInstance()->tick();
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

void updateInput()
{
    InputSystem::getInstance()->tickInput();
    glfwPollEvents();
}