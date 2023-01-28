#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <state-machine/state.h>
#include <state-machine/game-state-machine.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <ui/button.h>
#include <board/board-manager.h>

namespace States
{
    class GameState : public State<GameStateMachine>
    {
    private:
        Lava::Graphics::Texture backTexture;
        Lava::Graphics::Sprite backSprite;
        Lava::UI::Button backButton;
        Board::BoardManager boardManager;

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