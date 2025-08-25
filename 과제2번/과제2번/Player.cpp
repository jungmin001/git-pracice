#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    job_name = "Beginner";
    nickname = "Player";
    level = 1;
    HP = 100;
    MP = 100;
    power = 5;
    defence = 5;
    accuracy = 5;
    speed = 5;
}

Player::Player(string nickname) {
    this->job_name = "Beginner";
    this->nickname = nickname;
    this->level = 1;
    this->HP = 100;
    this->MP = 100;
    this->power = 5;
    this->defence = 5;
    this->accuracy = 5;
    this->speed = 5;
}

void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "직업: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}

string Player::getJobName() { return job_name; }
string Player::getNickname() { return nickname; }
int Player::getLevel() { return level; }
int Player::getHP() { return HP; }
int Player::getMP() { return MP; }
int Player::getPower() { return power; }
int Player::getDefence() { return defence; }
int Player::getAccuracy() { return accuracy; }
int Player::getSpeed() { return speed; }

void Player::setNickname(string nickname) { this->nickname = nickname; }

bool Player::setHP(int HP) {
    this->HP = HP;
    return this->HP >= 1 ? true : false;
}

bool Player::setMP(int MP) {
    this->MP = MP;
    return this->MP >= 1 ? true : false;
}

void Player::setPower(int power) { this->power = power; }
void Player::setDefence(int defence) { this->defence = defence; }
void Player::setAccuracy(int accuracy) { this->accuracy = accuracy; }
void Player::setSpeed(int speed) { this->speed = speed; }
