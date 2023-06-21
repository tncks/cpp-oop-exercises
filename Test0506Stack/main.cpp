#include <iostream>  // 272p ex8
using namespace std;

class MyIntStack {
	int* p;
	int size;
	int tos; 
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s); // copy constructor
	~MyIntStack();
	bool push(int n); 
	bool pop(int& n); 
};


MyIntStack::MyIntStack() {}


MyIntStack::MyIntStack(int size) {
	this->size = size;
	tos = -1;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = 0;
}
MyIntStack::MyIntStack(MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->p[i] = s.p[i];
}
MyIntStack::~MyIntStack() {
	delete [] p;
}




bool MyIntStack::push(int n) {
	if (tos == size - 1) return false;


	tos++;
	p[tos] = n;
	return true;

}

bool MyIntStack::pop(int& n) {

	if (tos == -1) return false;

	n = p[tos];
	tos--;
	return true;

}


int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값: " << n << endl;


	b.pop(n);
	cout << "스택 b에서 팝한 값: " << n << endl;
	
	cout << endl;
	return 0;
}



