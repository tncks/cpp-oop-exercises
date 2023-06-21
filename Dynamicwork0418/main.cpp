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
	cout << "���� �ձ� ������ �����մϴ�" << endl;
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�?";
	cin >> n;

	players = new Player[n];

	string name;
	for (int i = 0; i < n; i++) {
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>>";
		cin >> name;
		players[i].setName(name);
	}

	cout << "�����ϴ� �ܾ�� ";
	string a = "�ƹ���";
	string b;
	cout << a << "�Դϴ�" << endl;

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

	cout << players[turn].getName() << "������ �����ձ� ����! ����.." << endl;
}

int main(int argc, char* argv[]) {
	
	WordGame game;

	game.run();

	return 0;
}