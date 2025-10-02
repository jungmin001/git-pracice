#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
using namespace std;

int main() {
    string jobs[4] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;
    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
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
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }

    player->printPlayerStatus();

    cout << "몬스터가 생성됩니다." << endl;
    Monster* monster = new Monster();


    player->attack(monster);
    monster->attack(player);

    delete player;
    delete monster;
    return 0;
}

