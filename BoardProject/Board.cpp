#include <iostream>
#include <string>
using namespace std;

class Board {
public:
	static int articleNumber;
	static string article[100];
	static void add(string subNotice) {
		if (articleNumber == 0) {
			article[articleNumber].append("****** 게시판입니다. ******\n");
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

	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();

	return 0;
}