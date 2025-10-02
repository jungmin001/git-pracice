#include<iostream>
#include"Inventory.h"
#include"Item.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Inventory<Item> inv(5);

	inv.AddItem(Item("2", 13));
	inv.AddItem(Item("롱소드", 50));
	inv.AddItem(Item("체력 포션", 32));
	inv.AddItem(Item("1", 14));
	inv.AddItem(Item("마나 포션", 55));
	inv.AddItem(Item("4", 11));
	inv.AddItem(Item("3", 12));

	cout << "=== 아이템 목록 ===" << endl;
	inv.PrintAllItems();

	inv.RemoveLastItem();

	cout << "=== 아이템 제거 후 ===" << endl;
	inv.PrintAllItems();

	Inventory<Item> inv1(inv);

	cout << "=== 새 인벤토리 복사 생성 후 ===" << endl;
	inv1.PrintAllItems();
	inv.Resize(10);
	cout << "=== 인벤토리 용량 변경 후 ===" << endl;
	inv.PrintAllItems();
	cout << "인벤토리 용량: " << inv.GetCapacity() << endl;
	inv.SortItems();
	cout << "=== 아이템 정렬 후 ===" << endl;
	inv.PrintAllItems();

	system("pause");

	return 0;
}