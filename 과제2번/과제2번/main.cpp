#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
using namespace std;

int main() {
    string jobs[4] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;
    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "����: ";
    cin >> job_choice;

    if (job_choice == 1) {
        player = new Warrior(nickname);
    }
    else if (job_choice == 2) {
        player = new Magician(nickname);
    }
    else if (job_choice == 3) {
        player = new Thief(nickname);
    }
    else if (job_choice == 4) {
        player = new Archer(nickname);
    }
    else {
        cout << "�߸��� �Է��Դϴ�." << endl;
        return 1;
    }

    player->printPlayerStatus();

    cout << "���Ͱ� �����˴ϴ�." << endl;
    Monster* monster = new Monster();


    player->attack(monster);
    monster->attack(player);

    delete player;
    delete monster;
    return 0;
}

