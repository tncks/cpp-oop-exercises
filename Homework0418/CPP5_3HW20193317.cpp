// 과제명:  C++ 과제5 - 동적 할당/해제, 객체 활용
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: 선택 과제를 하면서 C++ 문법과 코딩 실력을 키우는 데 도움이 많이 된 것 같습니다.

#include <iostream>

#define COFFEE 0
#define WATER 1
#define SUGAR 2

using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() {
		size--;
	}
	int getSize() { return size; }
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
		tong[i].fill();
}

void CoffeeVendingMachine::selectEspresso() {
	if (tong[COFFEE].getSize() - 1 < 0 || tong[WATER].getSize() - 1 < 0) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	cout << "에스프레소 드세요..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[COFFEE].getSize() - 1 < 0 || tong[WATER].getSize() - 2 < 0) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	cout << "아메리카노 드세요..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
	tong[WATER].consume();
}
void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[COFFEE].getSize() - 1 < 0 || tong[WATER].getSize() - 2 < 0 || tong[SUGAR].getSize() - 1 < 0) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	cout << "설탕커피 드세요..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
	tong[WATER].consume();
	tong[SUGAR].consume();
}
void CoffeeVendingMachine::show() {
	cout << "커피:" << tong[COFFEE].getSize() << " 물:" << tong[WATER].getSize() << " 설탕:" << tong[SUGAR].getSize() << endl << endl;
}

void CoffeeVendingMachine::run() {
	cout << "************* 커피자판기를 작동합니다. *************" << endl;

	int menu = 1;
	while (menu!=0) {
		cout << "메뉴를 눌러주세요(0:종료, 1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >>";
		cin >> menu;
		switch (menu) {
		case 0:
			cout << "************* 종료합니다. *************" << endl;
			break;
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			show();
			break;
		default:
			break;
		}
	}
}


int main() {
	CoffeeVendingMachine coffeeVendingMachine;

	coffeeVendingMachine.run();

	return 0;
}