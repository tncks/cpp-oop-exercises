#include <iostream> // 204p open challenge 4
#include <string>

using namespace std;

class Player {
	string name;
public:
	Player();
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

Player::Player() {

}

class WordGame {
	Player* players;
public:
	WordGame();
	~WordGame();
	void run();
};

WordGame::WordGame() {

}

WordGame::~WordGame() {
	delete[] players;
}

void WordGame::run() {
	int n;
	cout << "끝말 잇기 게임을 시작합니다" << endl;
	cout << "게임에 참가하는 인원은 몇명입니까?";
	cin >> n;

	players = new Player[n];

	string name;
	for (int i = 0; i < n; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
		cin >> name;
		players[i].setName(name);
	}

	cout << "시작하는 단어는 ";
	string a = "아버지";
	string b;
	cout << a << "입니다" << endl;

	int turn = 0;
	while (true) {
		cout << players[turn].getName() << ">>";
		cin >> b;
		int half_left_index = a.size() - 2;
		int half_right_index = a.size() - 1;

		if (a.at(half_left_index) == b.at(0) && a.at(half_right_index) == b.at(1)) {
			if (turn + 1 == n) {
				turn = 0;
			}
			else {
				turn++;
			}
			a = b;
		}
		else {
			break;
		}
	}

	cout << players[turn].getName() << "때문에 끝말잇기 종료! 노잼.." << endl;
}

int main(int argc, char* argv[]) {
	
	WordGame game;

	game.run();

	return 0;
}