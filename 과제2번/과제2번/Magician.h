#pragma once
#include "Player.h"
#include "Monster.h"

class Magician : public Player {
public:
    Magician();
    Magician(string nickname);

    void attack() override;
    void attack(Monster* monster) override;
};
