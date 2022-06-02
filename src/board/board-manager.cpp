#include "board-manager.h"
#include <graphics/renderer.h>
#include <input/input-system.h>

using namespace Lava::Graphics;
using namespace Lava::Input;

namespace Board
{
    BoardManager::~BoardManager()
    {
        delete sprite;
        delete tex2;
        delete tex4;
        delete tex8;
        delete tex16;
        delete tex32;
        delete tex64;
        delete tex128;
        delete tex256;
        delete tex512;
    }

    void BoardManager::init()
    {
        tex2 = new Texture("res/texture/numbers/2.png");
        tex4 = new Texture("res/texture/numbers/4.png");
        tex8 = new Texture("res/texture/numbers/8.png");
        tex16 = new Texture("res/texture/numbers/16.png");
        tex32 = new Texture("res/texture/numbers/32.png");
        tex64 = new Texture("res/texture/numbers/64.png");
        tex128 = new Texture("res/texture/numbers/128.png");
        tex256 = new Texture("res/texture/numbers/256.png");
        tex512 = new Texture("res/texture/numbers/512.png");
        sprite = new Sprite(glm::vec3(50, 50, 0), glm::vec3(100, 100, 1), *tex2);

        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                board[j][i] = 0;
            }
        }

        board[0][0] = 1;
        board[2][2] = 1;
    }

    void BoardManager::tick()
    {
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[j][i] != 0)
                {
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    Renderer::getInstance()->draw(*sprite);
                }
            }
        }
    }
}