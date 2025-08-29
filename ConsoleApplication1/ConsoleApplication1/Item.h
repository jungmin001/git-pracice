#pragma once
#include<string>

using namespace std;

class Item {
private:
	string name_;
	int price_;

public:
	Item() {
		name_ = "";
		price_ = 0;
	}

	Item(string name, int price) {
		name_ = name;
		price_ = price;
	}

	void PrintInfo() const {
		cout << "이름: " << name_ << ", 가격: " << price_ << "g" << endl;
	}

	int GetPrice() const {
		return price_;
	}
};