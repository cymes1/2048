#ifndef BOARD_MANAGER_H
#define BOARD_MANAGER_H

#include <lava.h>
#include <graphics/renderer/renderer.h>
#include <graphics/sprite.h>
#include <graphics/texture.h>

static const char BOARD_SIZE = 3;

namespace Board
{
    class BoardManager
    {
    private:
        Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer;

        Lava::Graphics::Texture* tex2;
        Lava::Graphics::Texture* tex4;
        Lava::Graphics::Texture* tex8;
        Lava::Graphics::Texture* tex16;
        Lava::Graphics::Texture* tex32;
        Lava::Graphics::Texture* tex64;
        Lava::Graphics::Texture* tex128;
        Lava::Graphics::Texture* tex256;
        Lava::Graphics::Texture* tex512;
        Lava::Graphics::Sprite* sprite;

        short board[BOARD_SIZE][BOARD_SIZE];

    public:
        BoardManager(Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer);
        ~BoardManager();

        void init();
        void tick();

    private:
        void generateTile();
    };
}

#endif