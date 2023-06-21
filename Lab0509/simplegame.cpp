#include <iostream>
#include <cstdlib>
#include <ctime>

#define UP false
#define DOWN true
#define NUM_MIN_RANGE 0
#define NUM_MAX_RANGE 100

using namespace std;

class UpAndDownGame {
private:
	UpAndDownGame() {}
	static int startGameFromPlayerA();
public:
	static string player_A;
	static string player_B;
	static bool A_B_switcher;
	static int hidden_num_in_range;
	static int compared_input_num;
	static int second_last_num_remember_pointer_left;
	static int second_last_num_remember_pointer_right;

	static void setUpGame() {
		player_A = "김인수";
		player_B = "오은경";

		srand((unsigned)time(0));
		hidden_num_in_range = rand() % (NUM_MAX_RANGE - 1) + 1;   // 1~99

		second_last_num_remember_pointer_left = NUM_MIN_RANGE;
		second_last_num_remember_pointer_right = NUM_MAX_RANGE - 1;

		compared_input_num = startGameFromPlayerA();
		
	}
	static bool stillContinue() {
		bool b;
		if (hidden_num_in_range == compared_input_num) {
			b = false;
		}
		else {
			b = true;

			switch (compared_input_num > hidden_num_in_range) {
			case DOWN:
				second_last_num_remember_pointer_right = compared_input_num;  // DOWN 
				break;
			case UP:
				second_last_num_remember_pointer_left = compared_input_num;   //   UP
				break;
			default:
				break;
			}

			cout << "답은 " << second_last_num_remember_pointer_left << "과 " << second_last_num_remember_pointer_right << "사이에 있습니다." << endl;
			cout << (A_B_switcher ? player_A : player_B) << ">>";
			cin >> compared_input_num;
		}
		return b;
	}
	static void finishAndOrganizeGame() {
		cout << (A_B_switcher ? player_A : player_B);
		cout << " 가 이겼습니다!!" << endl;
	}
	static void playGame() {

		setUpGame();


		do {   
			A_B_switcher = !(A_B_switcher);
		} while (stillContinue());
		A_B_switcher = !(A_B_switcher);


		finishAndOrganizeGame();

	}
};



string UpAndDownGame::player_A = "김인수";
string UpAndDownGame::player_B = "오은경";
bool UpAndDownGame::A_B_switcher = true;
int UpAndDownGame::hidden_num_in_range = NUM_MIN_RANGE;
int UpAndDownGame::compared_input_num = -1;
int UpAndDownGame::second_last_num_remember_pointer_left = -2;
int UpAndDownGame::second_last_num_remember_pointer_right = -3;


int UpAndDownGame::startGameFromPlayerA(){
	int temp;
	cout << player_A << ">>";
	cin >> temp;
	return temp;
}



int main() {

	UpAndDownGame::playGame();

	return 0;
}