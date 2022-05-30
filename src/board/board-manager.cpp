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
        delete texture;
    }

    void BoardManager::init()
    {
        texture = new Texture("res/texture/start-button.png");
        sprite = new Sprite(glm::vec3(100, 100, 0), glm::vec3(100, 100, 1), *texture);
    }

    void BoardManager::tick()
    {
        if(InputSystem::getInstance()->getKey(GLFW_KEY_RIGHT))
        {
            sprite->translate(glm::vec2(1, 0) * speed);
        }
        if(InputSystem::getInstance()->getKey(GLFW_KEY_LEFT))
        {
            sprite->translate(glm::vec2(-1, 0) * speed);
        }

        Renderer::getInstance()->draw(*sprite);
    }
}