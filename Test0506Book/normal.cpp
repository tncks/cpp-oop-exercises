#include <iostream>  // 274p ex11 (4), string class copy style
#include <string>

using namespace std;


class Book {
	string  title;
	int price;
public:
	Book(Book& b);
	Book(string  title, int price);
	void set(string  title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
};

Book::Book(Book& b) {
	this->price = b.price;
	this->title = b.title;
}

Book::Book(const string  title, int price) {
	this->price = price;
	this->title = title;

}


void Book::set(const string  title, int price) {

	this->price = price;
	this->title = title;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();

	return 0;
}