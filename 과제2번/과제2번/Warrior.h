#pragma once
#include "Player.h"
#include "Monster.h"

class Warrior : public Player {
public:
    Warrior();
    Warrior(string nickname);

    void attack() override;
    void attack(Monster* monster) override;
};
