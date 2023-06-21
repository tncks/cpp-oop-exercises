#include <iostream> // 275p ex12
#include <string>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(Dept& dept);
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index) {
		if (scores[index] > 60) return true;
		else return false;
	}
};

void Dept::read() {
	cout << size << "개 점수 입력>> ";
	for (int i = 0; i < size; i++)
		cin >> scores[i];
}

Dept::Dept(Dept& dept) {
	this->size = dept.size;
	this->scores = new int[dept.size];
	for (int i = 0; i < dept.size; i++)
		this->scores[i] = dept.scores[i];
}

Dept::~Dept() {
	delete[] scores;
}

int countPass(Dept &d) {
	int cnt = 0;
	for (int i = 0; i < d.getSize(); i++)
		if (d.isOver60(i)) cnt++;

	return cnt;
}

int main() {

	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";



	return 0;
}