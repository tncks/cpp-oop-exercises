// ������:  C++ ����8 - ������ �ߺ� 
// �ۼ���: 20193317 �����
// ��뵵��: VisualStudio 2022 
// �Ұ�: ������� ������� ������ �ߺ��� �˱� ������ ���� �����ڷθ� ���� �� �־��µ�, 
//		 ������ ���� ������ �����ؼ� �� ���� ���Ͽ� �����ھ��� ȥ�ջ����� ���� �� �־ ���ο����ϴ�.

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
		cout << "�����";
	else
		cout << "����� �ƴ�";

	return 0;
}