#ifndef GAME_DOMAIN_H
#define GAME_DOMAIN_H

#include <lava.h>

class GameDomain : public Lava::Core::IDomain
{
private:
    Lava::Graphics::GraphicsDomain* graphicsDomain;

public:
    explicit GameDomain(Lava::Core::DomainManager* _domainManager);
    ~GameDomain() override;

    void load() override;
    void unload() override;

    void earlyTick();
    void tick();
    void lateTick();
};

#endif
