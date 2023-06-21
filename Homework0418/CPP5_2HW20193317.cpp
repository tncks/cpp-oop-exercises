// 과제명:  C++ 과제5 - 동적 할당/해제, 객체 활용
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: string 객체의 clear 메소드, empty 메소드를 처음 사용해 보았는데,
//		문자열 다루기를 다양하게 연습해 볼 수 있어서 좋았습니다.


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

	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	
	for (int i = 0; i < P_NUM; i++) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> gName >> gTel;
		contact[i].set(gName, gTel);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < P_NUM; i++)
		cout << contact[i].getName() << ' ';

	cout << endl << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> gName;

	gTel.clear();
	for (int i = 0; i < P_NUM; i++)
		if (gName == contact[i].getName()) {
			gTel = contact[i].getTel();
			cout << "전화 번호는 " << gTel << endl;
			break;
		}

	if (gTel.empty())
		cout << "찾으시는 이름의 사람이 없습니다." << endl;


	return 0;
}