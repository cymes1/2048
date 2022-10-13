#include "game-initializer.h"

void GameInitializer::onPreWindowCreation()
{
    windowCreateInfo.title = "2048";
    windowCreateInfo.width = 1920;
    windowCreateInfo.height = 1080;
}