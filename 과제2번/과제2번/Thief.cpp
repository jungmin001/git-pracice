#include "Thief.h"
#include <iostream>
#include <algorithm>
using namespace std;

Thief::Thief() {
    job_name = "Thief";
}

Thief::Thief(string nickname) {
    job_name = "Thief";
    setNickname(nickname);
}

void Thief::attack() {
    cout << "Thief �� �����ߴ�." << endl;
}

void Thief::attack(Monster* monster) {
    if (!monster) {
        cout << "���� ����� �����ϴ�.\n";
        return;
    }
    int damage = max(1, power - monster->getDefence());
    cout << monster->getName() << "���� " << damage << "�� �������� �������ϴ�" << endl;

    int hp = monster->getHP() - damage;
    if (monster->setHP(hp)) {
        cout << "������ ü���� " << monster->getHP() << " �� ���ҽ��ϴ�." << endl;
    }
    else {
        cout << "������ ü���� 0�� �Ǿ����ϴ�." << endl;
        cout << "�÷��̾ �¸� �Ͽ����ϴ�." << endl;
    }
}
