// ������:  C++ ����8 - ������ �ߺ� 
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: c���� �ڷᱸ�� �ð��� ������ ������ ��������, 
//		��ü���� C++ ���ε� ������ Ŭ������ �����ϰ� ��ü �����Ͽ�
//		����� ���� �� �ٸ� ������ ���߹���� �н��� �� �־����ϴ�.

// 7�� 7���� �ƴ�
// 371p 7�� ex11 ���ð��� �����Ͽ����ϴ�.

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