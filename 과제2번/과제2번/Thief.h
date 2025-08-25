#pragma once
#include "Player.h"
#include "Monster.h"

class Thief : public Player {
public:
    Thief();
    Thief(string nickname);

    void attack() override;
    void attack(Monster* monster) override;
};
