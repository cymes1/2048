#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <lava.h>
#include <main/domains/game-domain.h>

class MainMenuState : public Lava::Core::BaseAppState
{
private:
    GameDomain* gameDomain;

public:
    explicit MainMenuState(Lava::Core::BaseAppStateMachine* _stateMachine, Lava::Core::DomainManager* _domainManager);
    ~MainMenuState() override;

    void init() override;
    void deinit() override;
    void tick() override;
};


#endif