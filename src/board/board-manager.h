#ifndef BOARD_MANAGER_H
#define BOARD_MANAGER_H

#include <graphics/sprite.h>
#include <graphics/texture.h>

namespace Board
{
    class BoardManager
    {
    private:
        Lava::Graphics::Texture* texture;
        Lava::Graphics::Sprite* sprite;

        float speed = 0.01f;

    public:
        ~BoardManager();

        void init();
        void tick();
    };
}

#endif