#include "Magician.h"
#include <iostream>
#include <algorithm>
using namespace std;

Magician::Magician() {
    job_name = "Magician";
}

Magician::Magician(string nickname) {
    job_name = "Magician";
    setNickname(nickname);
}

void Magician::attack() {
    cout << "Magician 가 공격했다." << endl;
}

void Magician::attack(Monster* monster) {
    if (!monster) {
        cout << "공격 대상이 없습니다.\n";
        return;
    }
    int damage = max(1, power - monster->getDefence());
    cout << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다" << endl;

    int hp = monster->getHP() - damage;
    if (monster->setHP(hp)) {
        cout << "몬스터의 체력이 " << monster->getHP() << " 가 남았습니다." << endl;
    }
    else {
        cout << "몬스터의 체력이 0이 되었습니다." << endl;
        cout << "플레이어가 승리 하였습니다." << endl;
    }
}
