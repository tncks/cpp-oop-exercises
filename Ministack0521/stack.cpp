#include "stack.h"

#ifndef STACK_CPP
#define STACK_CPP

template<typename T>
Stack<T>::Stack(int cap)
	: capacity(cap), size(0)
{
	ptr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] ptr;
}

template<typename T>
void Stack<T>::push(const T& element) {
	if (size < capacity) {
		ptr[size++] = element;
	}
	else {
		cout << "������ �� ���� ���̻� ������ �� �����ϴ�." << endl;
		assert(false);
	}
}
template<typename T>
T Stack<T>::pop() {
	if (size > 0) {
		T temp = ptr[size - 1];
		size--;
		return temp;
	}
	else {
		cout << "������ �� ���̻� pop�� �� �����ϴ�." << endl;
		assert(false);
	}
}

#endif