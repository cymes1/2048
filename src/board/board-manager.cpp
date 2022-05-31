#include "board-manager.h"
#include <graphics/renderer.h>
#include <input/input-system.h>
#include <time/time.h>

using namespace Lava::Graphics;
using namespace Lava::Input;
using namespace Lava::Time;

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
        if(InputSystem::getInstance()->getKey(GLFW_KEY_UP))
        {
            sprite->translate(glm::vec2(0, 1) * speed * (float)Time::getInstance()->getDeltaTime());
        }
        if(InputSystem::getInstance()->getKey(GLFW_KEY_DOWN))
        {
            sprite->translate(glm::vec2(0, -1) * speed * (float)Time::getInstance()->getDeltaTime());
        }
        if(InputSystem::getInstance()->getKey(GLFW_KEY_RIGHT))
        {
            sprite->translate(glm::vec2(1, 0) * speed * (float)Time::getInstance()->getDeltaTime());
        }
        if(InputSystem::getInstance()->getKey(GLFW_KEY_LEFT))
        {
            sprite->translate(glm::vec2(-1, 0) * speed * (float)Time::getInstance()->getDeltaTime());
        }

        Renderer::getInstance()->draw(*sprite);
    }
}