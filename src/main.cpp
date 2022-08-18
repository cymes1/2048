#define NDEBUG

#include <cstring>
#include <game.h>

/*
#include <graphics/window.h>
#include <graphics/vulkan-context.h>
#include <input/input-system.h>
#include <audio/audio-system.h>
#include <time/time.h>
#include <game-state-machine.h>

using namespace Lava::Audio;
using namespace Lava::Graphics;
using namespace Lava::Input;
using namespace Lava::Time;
using namespace States;
*/

using namespace Lava;

void updateInput();
bool shouldInitializeVulkan(int args, char** argv);

int main(int args, char** argv)
{
    Game game;
/*
    GameStateMachine stateMachine;
    bool initializeVulkan = shouldInitializeVulkan(args, argv);
    Window window("2048", initializeVulkan);

    if(initializeVulkan)
        VulkanContext::getInstance()->initialize(window);

    InputSystem::getInstance()->initialize(window);
    Time::getInstance()->initialize();
    AudioSystem::getInstance()->initialize();
//    stateMachine.createNewState<BootState>();
    while(!glfwWindowShouldClose(window.getHandle()))
    {
        updateInput();
        AudioSystem::getInstance()->tick();

        Time::getInstance()->tick();
        if(initializeVulkan)
            VulkanContext::getInstance()->tick();
//        glClear(GL_COLOR_BUFFER_BIT);

//        stateMachine.tick();
//        stateMachine.renderImGui();
//        glfwSwapBuffers(window.getHandle());

        if(InputSystem::getInstance()->getShouldExit())
            glfwSetWindowShouldClose(window.getHandle(), 1);
    }
//    stateMachine.deinitialize();
    if(initializeVulkan)
        VulkanContext::getInstance()->waitForVulkan();
*/
    return 0;
}

void updateInput()
{
/*
    InputSystem::getInstance()->tickInput();
    glfwPollEvents();
*/
}

bool shouldInitializeVulkan(int args, char** argv)
{
    return true;
    return args > 1 && strcmp(argv[1], "-vulkan") == 0;
}