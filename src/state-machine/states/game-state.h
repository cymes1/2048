#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <state.h>
#include <game-state-machine.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <ui/button.h>

namespace States
{
    class GameState : public State<GameStateMachine>
    {
    private:
        Lava::Graphics::Texture backTexture;
        Lava::Graphics::Sprite backSprite;
        Lava::UI::Button backButton;

    private:
        static void onBack();

    public:
        explicit GameState(GameStateMachine* stateMachine);

        void initialize() override;
        void tick() override;
        void renderImGui() override;
        void deinitialize() override;
    };
}


#endif