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
    cout << "Magician �� �����ߴ�." << endl;
}

void Magician::attack(Monster* monster) {
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
