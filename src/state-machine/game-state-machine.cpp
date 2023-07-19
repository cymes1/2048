#include "game-state-machine.h"
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

using namespace Lava::Memory;
using namespace Lava::Graphics;

namespace States
{
    GameStateMachine::GameStateMachine()
        : state(nullptr)
    {}

    void GameStateMachine::initialize(Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer)
    {
        this->renderer = renderer;
    }

    void GameStateMachine::tick()
    {
        state->tick();
    }

    void GameStateMachine::renderImGui()
    {
/*
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("ClearColor");
        state->renderImGui();
        ImGui::Separator();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                    1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
*/
    }

    void GameStateMachine::deinitialize()
    {
        if(state != nullptr)
            state->deinitialize();
    }
}