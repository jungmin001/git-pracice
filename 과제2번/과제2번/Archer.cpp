#include "Archer.h"
#include <iostream>
#include <algorithm>
using namespace std;

Archer::Archer() {
    job_name = "Archer";
}

Archer::Archer(string nickname) {
    job_name = "Archer";
    setNickname(nickname);
}

void Archer::attack() {
    cout << "Archer �� �����ߴ�." << endl;
}

void Archer::attack(Monster* monster) {
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
