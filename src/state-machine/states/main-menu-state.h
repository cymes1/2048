#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <lava.h>

class MainMenuState : public Lava::Core::BaseAppState
{
public:
    explicit MainMenuState(Lava::Core::BaseAppStateMachine* _stateMachine);
    ~MainMenuState() override;

    void init() override;
    void deinit() override;
    void tick() override;
};


#endif