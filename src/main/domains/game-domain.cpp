#include "game-domain.h"

using namespace Lava::Graphics;

GameDomain::GameDomain(Lava::Core::DomainManager* _domainManager)
    : IDomain(_domainManager), graphicsDomain()
{}

GameDomain::~GameDomain() = default;

void GameDomain::load()
{
    graphicsDomain = domainManager->getDomain<GraphicsDomain>();
}

void GameDomain::unload()
{
    graphicsDomain = nullptr;
}

void GameDomain::earlyTick()
{}

void GameDomain::tick()
{
    Sprite sprite({0.0f, 0.0f}, {1.0f, 1.0f});
    graphicsDomain->getRenderer().get().draw(sprite);
}

void GameDomain::lateTick()
{}
