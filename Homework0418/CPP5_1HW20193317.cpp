// ������:  C++ ����5 - ���� �Ҵ�/����, ��ü Ȱ��
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: ���� C���� malloc �Լ��� free �Լ��� ���ٰ� ���Ӱ� ��� new �� delete �����ڸ� ����غ��� ���ϰ� ���ҽ��ϴ�.

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
	cout << "���� ū ���� " << s.big() << endl;

	return 0;
}