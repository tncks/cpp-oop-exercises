// 과제명:  C++ 과제5 - 동적 할당/해제, 객체 활용
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: 특정 조건에 해당되는 검색 결과를 보여주는 코드 작성 연습을 해 볼 수 있었으며,
//		다양한 예외처리도 연습해 볼 수 있었던 과제였습니다. 많은 도움이 되었습니다.

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
		cout << "메모리 할당 작업이 실패하였습니다." << endl;
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
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> searchName;

	for (int i = 0; i < size; i++) {
		if (p[i].getName() == searchName) {
			cout << searchName << "의 면적은 " << p[i].getArea() << endl;
			isSearchFailed = false;
			break;
		}
	}

	if (isSearchFailed) {
		cout << "찾으시는 이름의 원이 목록 안에 존재하지 않습니다." << endl;
	}
}
void CircleManager::searchByArea() {

	bool isSearchFailed = true;

	int minimumAreaSize;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> minimumAreaSize;

	cout << minimumAreaSize << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > minimumAreaSize) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ',';
			isSearchFailed = false;
		}

	}

	if (isSearchFailed)
		cout << minimumAreaSize << " 면적보다 큰 원이 목록 안에 존재하지 않습니다.";

	cout << endl;

}

int main() {

	int n;

	do {
		cout << "원의 개수 >> ";
		cin >> n;
	} while (n <= 0);

	CircleManager circleManager(n);

	string circleName;
	int radius;

	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> circleName >> radius;
		circleManager.getCircle()[i].setCircle(circleName, radius);

	}

	circleManager.searchByName();

	circleManager.searchByArea();


	return 0;
}