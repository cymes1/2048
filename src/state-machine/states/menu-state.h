#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <state-machine/state.h>
#include <state-machine/game-state-machine.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <ui/button.h>

namespace States
{
    class MenuState : public State<GameStateMachine>
    {
    private:
        Lava::Graphics::Texture startButtonTexture;
        Lava::Graphics::Texture optionsButtonTexture;
        Lava::Graphics::Texture exitButtonTexture;
        Lava::Graphics::Sprite startSprite;
        Lava::Graphics::Sprite optionsSprite;
        Lava::Graphics::Sprite exitSprite;
        Lava::UI::Button startButton;
        Lava::UI::Button optionsButton;
        Lava::UI::Button exitButton;

    private:
        static void onStart();
        static void onOptions();
        static void onExit();

    public:
        explicit MenuState(GameStateMachine* stateMachine);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;
    };
}


#endif