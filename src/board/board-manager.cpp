#include "board-manager.h"
#include <random>
#include <graphics/renderer/renderer.h>
#include <input/input-system.h>
#include <iostream>

using namespace Lava::Memory;
using namespace Lava::Graphics;
using namespace Lava::Input;

namespace Board
{
    BoardManager::BoardManager(Lava::Memory::BorrowedMemory<Lava::Graphics::Renderer> renderer)
        : renderer(renderer)
    {}

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

        board[0][0] = 2;
        board[2][2] = 2;
        board[0][2] = 4;
        board[1][2] = 4;
    }

    void BoardManager::tick()
    {
        glm::vec2 dir(0, 0);
        if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_RIGHT))
            dir.x = 1;
        else if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_LEFT))
            dir.x = -1;
        else if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_UP))
            dir.y = 1;
        else if(InputSystem::getInstance()->getKeyDown(GLFW_KEY_DOWN))
            dir.y = -1;

        if(dir.x == 1)
        {
            for (int i = BOARD_SIZE - 2; i >= 0; i--)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    short& current = board[i][j];
                    short& right = board[i + 1][j];
                    if(current != 0 && (right == 0 || current == right))
                    {
                        right += current;
                        current = 0;
                    }
                }
            }
        }
        if(dir.x == -1)
        {
            for (int i = 1; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    short& current = board[i][j];
                    short& left = board[i - 1][j];
                    if(current != 0 && (left == 0 || current == left))
                    {
                        left += current;
                        current = 0;
                    }
                }
            }
        }
        if(dir.y == 1)
        {
            for (int i = BOARD_SIZE - 2; i >= 0; i--)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    short& current = board[j][i];
                    short& up = board[j][i + 1];
                    if(current != 0 && (up == 0 || current == up))
                    {
                        up += current;
                        current = 0;
                    }
                }
            }
        }
        if(dir.y == -1)
        {
            for (int i = 1; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    short& current = board[j][i];
                    short& down = board[j][i - 1];
                    if(current != 0 && (down == 0 || current == down))
                    {
                        down += current;
                        current = 0;
                    }
                }
            }
        }

        if (dir.x != 0 || dir.y != 0)
            generateTile();

        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                if(board[j][i] == 2)
                {
                    sprite->setTexture(*tex2);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 4)
                {
                    sprite->setTexture(*tex4);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 8)
                {
                    sprite->setTexture(*tex8);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 16)
                {
                    sprite->setTexture(*tex16);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 32)
                {
                    sprite->setTexture(*tex32);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 64)
                {
                    sprite->setTexture(*tex64);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 128)
                {
                    sprite->setTexture(*tex128);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 256)
                {
                    sprite->setTexture(*tex256);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] == 512)
                {
                    sprite->setTexture(*tex512);
                    sprite->setPosition({ 50 + j * 100, 50 + i * 100});
                    renderer.get().draw(*sprite);
                }
                else if(board[j][i] != 0)
                {
                    std::cout << "unknown: " << (int)board[j][i];
                }
            }
        }
    }

    void BoardManager::generateTile()
    {
        char count = 0;
        for(char i = 0; i < BOARD_SIZE; i++)
        {
            for(char j = 0; j < BOARD_SIZE; j++)
            {
                if(board[j][i] == 0)
                {
                    count++;
                }
            }
        }
        if(count == 0)
        {
            std::cout << "full" << std::endl;
            return;
        }

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<char> dist(0, count - 1);
        char genIndex = dist(mt);

        for(char i = 0; i < BOARD_SIZE; i++)
        {
            for(char j = 0; j < BOARD_SIZE; j++)
            {
                if(board[j][i] != 0)
                    continue;

                if(genIndex == 0)
                {
                    board[j][i] = 2;
                    return;
                }
                genIndex--;
            }
        }

        std::cout << "space not found" << std::endl;
    }
}