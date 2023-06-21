// ������:  C++ ����5 - ���� �Ҵ�/����, ��ü Ȱ��
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: Ư�� ���ǿ� �ش�Ǵ� �˻� ����� �����ִ� �ڵ� �ۼ� ������ �� �� �� �־�����,
//		�پ��� ����ó���� ������ �� �� �־��� ���������ϴ�. ���� ������ �Ǿ����ϴ�.

#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->radius = radius;
	this->name = name;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}
string Circle::getName() {
	return name;
}

class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	Circle* getCircle();
	void searchByName();
	void searchByArea();
};

CircleManager::CircleManager(int size) {
	p = new Circle[size];
	this->size = size;

	if (!p) {
		cout << "�޸� �Ҵ� �۾��� �����Ͽ����ϴ�." << endl;
	}
}
CircleManager::~CircleManager() {
	delete[] p;
}
Circle* CircleManager::getCircle() {
	return p;
}

void CircleManager::searchByName() {
	bool isSearchFailed = true;
	string searchName;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> searchName;

	for (int i = 0; i < size; i++) {
		if (p[i].getName() == searchName) {
			cout << searchName << "�� ������ " << p[i].getArea() << endl;
			isSearchFailed = false;
			break;
		}
	}

	if (isSearchFailed) {
		cout << "ã���ô� �̸��� ���� ��� �ȿ� �������� �ʽ��ϴ�." << endl;
	}
}
void CircleManager::searchByArea() {

	bool isSearchFailed = true;

	int minimumAreaSize;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> minimumAreaSize;

	cout << minimumAreaSize << "���� ū ���� �˻��մϴ�." << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > minimumAreaSize) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ',';
			isSearchFailed = false;
		}

	}

	if (isSearchFailed)
		cout << minimumAreaSize << " �������� ū ���� ��� �ȿ� �������� �ʽ��ϴ�.";

	cout << endl;

}

int main() {

	int n;

	do {
		cout << "���� ���� >> ";
		cin >> n;
	} while (n <= 0);

	CircleManager circleManager(n);

	string circleName;
	int radius;

	for (int i = 0; i < n; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> circleName >> radius;
		circleManager.getCircle()[i].setCircle(circleName, radius);

	}

	circleManager.searchByName();

	circleManager.searchByArea();


	return 0;
}