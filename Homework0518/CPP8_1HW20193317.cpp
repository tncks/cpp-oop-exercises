// 과제명:  C++ 과제8 - 연산자 중복 
// 작성자: 20193317 노수찬
// 사용도구: VisualStudio 2022 
// 소감: 보라색을 만들려면 연산자 중복을 알기 전에는 그저 생성자로만 만들 수 있었는데, 
//		 지금은 덧셈 연산을 정의해서 두 색을 더하여 생성자없이 혼합색상을 만들 수 있어서 새로웠습니다.

#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	// void setColor();
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }

	Color operator + (Color op2);
	bool operator == (Color op2);
};

Color Color::operator + (Color op2) {
	Color mixedColor;
	mixedColor.red = this->red + op2.red;
	mixedColor.green = this->green + op2.green;
	mixedColor.blue = this->blue + op2.blue;

	return mixedColor;
}

bool Color::operator == (Color op2) {
	bool b;

	if (this->red == op2.red && this->green == op2.green && this->blue == op2.blue) b = true;
	else b = false;


	return b;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색";
	else
		cout << "보라색 아님";

	return 0;
}