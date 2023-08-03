#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <lava.h>
#include <graphics/renderer/renderer.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>
#include <ui/button.h>
#include <board/board-manager.h>

namespace States
{
class GameState : public Lava::Core::BaseAppState
    {
    private:
        Lava::Graphics::Texture backTexture;
        Lava::Graphics::Sprite backSprite;
        Lava::UI::Button backButton;
//        Board::BoardManager boardManager;

    private:
        static void onBack();

    public:
        explicit GameState(Lava::Core::BaseAppStateMachine* stateMachine);

        void init() override;
        void tick() override;
        void deinit() override;
    };
}


#endif