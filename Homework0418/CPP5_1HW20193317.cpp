// 과제명:  C++ 과제5 - 동적 할당/해제, 객체 활용
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: 기존 C언어에서 malloc 함수와 free 함수를 쓰다가 새롭게 배운 new 와 delete 연산자를 사용해보니 편리하고 좋았습니다.

#include <iostream>

using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++)
		cin >> p[i];
}
void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}
int Sample::big() {
	int max = p[0];

	for (int i = 1; i < size; i++)
		if (max < p[i])
			max = p[i];

	return max;
}

Sample::~Sample() {
	delete[] p;
}

int main() {

	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;

	return 0;
}