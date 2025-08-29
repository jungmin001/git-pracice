#pragma once

#include <iostream>
#include "Item.h"
#include <algorithm>

using namespace std;

template <typename T>
class Inventory 
{

private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10) {
		if (0 >= capacity) {
			capacity = 1;
		}

		pItems_ = new T[capacity];
		capacity_ = capacity;
		size_ = 0;
	}

	Inventory(const Inventory<T>& other) {
		Assign(other);

		cout << "인벤토리 복사 완료" << endl;
	}

	~Inventory() {
		delete[] pItems_;
		pItems_ = nullptr;
	}

public:
	void Assign(const Inventory<T>& other) {
		pItems_ = new T[other.capacity_];
		capacity_ = other.capacity_;
		size_ = other.size_;

		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
	}

		void AddItem(const T & item) {
			if (size_ >= capacity_) {
				Resize(capacity_ * 2);
			}
			pItems_[size_] = item;
			++size_;
		}

		void Resize(int newcapacity) {
			capacity_ = newcapacity;
			T* tempItems_ = new T[capacity_];

			for (int i = 0; i < size_; i++) {
				tempItems_[i] = pItems_[i];
			}
			delete[] pItems_;
			pItems_ = nullptr;

			pItems_ = tempItems_;
		}

		void SortItems() {
			sort(pItems_, pItems_+size_, compareItemsByPrice);
		}

		static bool compareItemsByPrice(const Item& a, const Item& b) {
			return a.GetPrice() < b.GetPrice();
		}

		void RemoveLastItem() {
			if (0 >= size_) {
				cout << "인벤토리가 비어있습니다." << endl;
				return;
			}

			--size_;
		}

		int GetSize() const {
			return size_;
		}

		int GetCapacity() const {
			return capacity_;
		}

		void PrintAllItems() const {
			if (0 >= size_) {
				cout << "비어있음" << endl;
			}

			for (int i = 0; i < size_; i++) {
				Item* item = dynamic_cast<Item*>(&pItems_[i]);

				if (nullptr != item) {
					item->PrintInfo();
				}
			}
		}
};