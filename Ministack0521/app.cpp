#include <iostream>
#include "stack.cpp"

//using namespace std;
typedef Stack<int> iStack;

int main() {

	iStack stack(10);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(3);

	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop();


	return 0;
}