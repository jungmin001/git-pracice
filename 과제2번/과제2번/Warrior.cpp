#include "Warrior.h"
#include <iostream>
#include <algorithm>
using namespace std;

Warrior::Warrior() {
    job_name = "Warrior";
    HP += 50;
    power += 10;
    defence += 5;
}

Warrior::Warrior(string nickname) {
    job_name = "Warrior";
    setNickname(nickname);
    HP += 50;
    power += 10;
    defence += 5;
}

void Warrior::attack() {
    cout << "Warrior �� �����ߴ�." << endl;
}

void Warrior::attack(Monster* monster) {
    if (!monster) {
        cout << "���� ����� �����ϴ�.\n";
        return;
    }
    int damage = max(1, power - monster->getDefence());
    cout << monster->getName() << "���� " << damage << "�� �������� �������ϴ�" << endl;

    int monsterHP = monster->getHP() - damage;
    if (monster->setHP(monsterHP)) {
        cout << "������ ü���� " << monster->getHP() << " �� ���ҽ��ϴ�." << endl;
    }
    else {
        cout << "������ ü���� 0�� �Ǿ����ϴ�." << endl;
        cout << "�÷��̾ �¸� �Ͽ����ϴ�." << endl;
    }
}
