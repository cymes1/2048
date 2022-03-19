#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <state.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <game-state-machine.h>

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

    public:
        explicit MenuState(GameStateMachine* stateMachine);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;
    };
}


#endif