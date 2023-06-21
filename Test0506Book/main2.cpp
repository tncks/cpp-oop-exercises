#include <iostream>  // 274p ex11
#include <string>
#include <cstring>
using namespace std;


class Book {
	char* title;
	int price;
public:
	Book(Book& b);
	Book(const char* title, int price);
	~Book();
	void set(const char *title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(Book& b) {
	this->price = b.price;
	this->title = new char[strlen(b.title)];
	for (int i = 0; i < strlen(b.title) - 1; i++)
		this->title[i] = b.title[i];
}

Book::Book(const char* title, int price) {
	this->price = price;
	this->title = new char[strlen(title)];
	for (int i = 0; i < strlen(title) - 1; i++)
		this->title[i] = title[i];

}

Book::~Book() {
	delete [] title;
}

void Book::set(const char* title, int price) {

	/*if (this->title && this->title != NULL) {
		delete[] title;
	}


	this->price = price;
	this->title = new char[strlen(title)];
	for (int i = 0; i < strlen(title) - 1; i++)
		this->title[i] = title[i];*/
}

int main() {
	Book cpp("명품C++", 10000);
	/*Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();*/

	return 0;
}