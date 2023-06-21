// 과제명:  C++ 과제8 - 연산자 중복 
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: c언어로 자료구조 시간에 스택을 구현해 보았지만, 
//		객체지향 C++ 으로도 스택을 클래스로 설계하고 객체 생성하여
//		만들어 보니 또 다른 관점의 개발방법을 학습할 수 있었습니다.

// 7장 7번이 아닌
// 371p 7장 ex11 선택과제 진행하였습니다.

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack;

typedef int element;

Stack& operator<<(Stack& stack, element item);
void operator>>(Stack& stack, element& result_repository_var);
bool operator!(Stack stack);


class Stack {
private:
	element data_flow[MAX_SIZE];
	int top;
	void init_stack_logic() {
		top = -1;
		for (int i = 0; i < MAX_SIZE; i++)
			data_flow[i] = 0;
	}
public:
	Stack() {
		init_stack_logic();
	}
	~Stack() {}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_SIZE - 1; }
	friend Stack& operator<<(Stack& stack, element item);
	friend void operator>>(Stack& stack, element& result_repository_var);
	friend bool operator!(Stack stack);
};

Stack& operator<<(Stack& stack, element item) {
	if (stack.isFull()) {
		return stack;
	}
	else {
		stack.data_flow[++(stack.top)] = item;
		return stack;
	}
}
void operator>>(Stack& stack, element& result_repository_var) {
	if (stack.isEmpty()) {
		result_repository_var = -1;
		return;
	}
	else {
		result_repository_var = stack.data_flow[(stack.top)--];
	}
}

bool operator!(Stack stack) {
	return stack.top == -1;
}

int main() {
	Stack stack;

	stack << 3 << 5 << 10;

	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;


	return 0;
}