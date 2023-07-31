#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <memory/borrowed-memory.h>
#include <lava.h>
#include <graphics/renderer/renderer.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <ui/button.h>

namespace States
{
class MenuState : public Lava::Core::BaseAppState
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
        explicit MenuState(Lava::Core::BaseAppStateMachine* stateMachine);

        void init() override;
        void deinit() override;
        void tick() override;
    };
}


#endif