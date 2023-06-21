// ������:  C++ ����5 - ���� �Ҵ�/����, ��ü Ȱ��
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: string ��ü�� clear �޼ҵ�, empty �޼ҵ带 ó�� ����� ���Ҵµ�,
//		���ڿ� �ٷ�⸦ �پ��ϰ� ������ �� �� �־ ���ҽ��ϴ�.


#include <iostream>
#include <string>

#define P_NUM 3

using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {

	Person contact[P_NUM];
	string gName, gTel;

	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
	
	for (int i = 0; i < P_NUM; i++) {
		cout << "��� " << i + 1 << ">> ";
		cin >> gName >> gTel;
		contact[i].set(gName, gTel);
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < P_NUM; i++)
		cout << contact[i].getName() << ' ';

	cout << endl << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> gName;

	gTel.clear();
	for (int i = 0; i < P_NUM; i++)
		if (gName == contact[i].getName()) {
			gTel = contact[i].getTel();
			cout << "��ȭ ��ȣ�� " << gTel << endl;
			break;
		}

	if (gTel.empty())
		cout << "ã���ô� �̸��� ����� �����ϴ�." << endl;


	return 0;
}