// ������:  C++ ����5 - ���� �Ҵ�/����, ��ü Ȱ��
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: ���� ������ �ϸ鼭 C++ ������ �ڵ� �Ƿ��� Ű��� �� ������ ���� �� �� �����ϴ�.

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
		cout << "���ᰡ �����մϴ�." << endl;
		return;
	}
	cout << "���������� �弼��..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[COFFEE].getSize() - 1 < 0 || tong[WATER].getSize() - 2 < 0) {
		cout << "���ᰡ �����մϴ�." << endl;
		return;
	}
	cout << "�Ƹ޸�ī�� �弼��..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
	tong[WATER].consume();
}
void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[COFFEE].getSize() - 1 < 0 || tong[WATER].getSize() - 2 < 0 || tong[SUGAR].getSize() - 1 < 0) {
		cout << "���ᰡ �����մϴ�." << endl;
		return;
	}
	cout << "����Ŀ�� �弼��..." << endl << endl;
	tong[COFFEE].consume();
	tong[WATER].consume();
	tong[WATER].consume();
	tong[SUGAR].consume();
}
void CoffeeVendingMachine::show() {
	cout << "Ŀ��:" << tong[COFFEE].getSize() << " ��:" << tong[WATER].getSize() << " ����:" << tong[SUGAR].getSize() << endl << endl;
}

void CoffeeVendingMachine::run() {
	cout << "************* Ŀ�����Ǳ⸦ �۵��մϴ�. *************" << endl;

	int menu = 1;
	while (menu!=0) {
		cout << "�޴��� �����ּ���(0:����, 1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���) >>";
		cin >> menu;
		switch (menu) {
		case 0:
			cout << "************* �����մϴ�. *************" << endl;
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