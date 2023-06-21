#include <iostream>
#include <string>
using namespace std;

class Board {
public:
	static int articleNumber;
	static string article[100];
	static void add(string subNotice) {
		if (articleNumber == 0) {
			article[articleNumber].append("****** �Խ����Դϴ�. ******\n");
			articleNumber++;
		}
		--articleNumber;
		article[articleNumber].append(to_string(articleNumber++)).append(": ").append(subNotice);
		articleNumber++;
	}

	static void print() {
		for (int i = 0; i < articleNumber + 1; i++) {
			cout << article[i];
			if (i != 0) cout << endl;
		}
	}
};

int Board::articleNumber = 0;
string Board::article[100] = { string(""),};

int main() {

	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();

	return 0;
}