#define NDEBUG

#include <cstring>
#include <graphics/window.h>
#include <input/input-system.h>
#include <audio/audio-system.h>
#include <time/time.h>
#include <game-state-machine.h>
#include <states/boot-state.h>

using namespace Lava::Audio;
using namespace Lava::Graphics;
using namespace Lava::Input;
using namespace Lava::Time;
using namespace States;

void updateInput();
bool shouldInitializeVulkan(int args, char** argv);

int main(int args, char** argv)
{
    GameStateMachine stateMachine;
    Window window("2048", shouldInitializeVulkan(args, argv));

    InputSystem::getInstance()->initialize(window);
    Time::getInstance()->initialize();
    AudioSystem::getInstance()->initialize();
//    stateMachine.createNewState<BootState>();
    while(!glfwWindowShouldClose(window.getHandle()))
    {
        updateInput();
        AudioSystem::getInstance()->tick();

        Time::getInstance()->tick();
        window.tickVulkan();
//        glClear(GL_COLOR_BUFFER_BIT);

//        stateMachine.tick();
//        stateMachine.renderImGui();
//        glfwSwapBuffers(window.getHandle());

        if(InputSystem::getInstance()->getShouldExit())
            glfwSetWindowShouldClose(window.getHandle(), 1);
    }
//    stateMachine.deinitialize();
    window.waitForVulkan();
    return 0;
}

void updateInput()
{
    InputSystem::getInstance()->tickInput();
    glfwPollEvents();
}

bool shouldInitializeVulkan(int args, char** argv)
{
    return true;
    return args > 1 && strcmp(argv[1], "-vulkan") == 0;
}