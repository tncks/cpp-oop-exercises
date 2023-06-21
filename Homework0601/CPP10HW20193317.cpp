//----------------------------------------------------
// ������:  C++ ����10 - �׷��� ������ 
// �ۼ���: �����
// ���ߵ���: VisualStudio 2022
// �Ұ�: C++�� �پ��� ��ɵ��� �����غ��鼭, ��ü ������
//		 �������� ���� ���� �� �־����ϴ�.
//		 ��Ӱ� ������, ĸ��ȭ ������ �� �� �����ϰ� �Ǿ����ϴ�.
//		 �׸��� ����Ʈ ������ �߰� �� ���� ����� �����ϴ�
//		 �������� ���� ����Ʈ�� ���� ������ ������ �׷�����
//		 ��ü������ �İ� ������, �ٽ� ������ �� �־����ϴ�. 
//----------------------------------------------------


#include <iostream>
#include <cstdlib>
#include <ctime>

#define INSERT 1
#define REMOVE 2
#define VIEW 3
#define PROGRAM_EXIT 4


#define LINE_SHAPE 1
#define TRIANGLE_SHAPE 2
#define RECT_SHAPE 3

using namespace std;


class Shape;
class Triangle;
class Rect;
class Line;
class UI;
class MenuManager;
class GraphicEditor;




class Shape {
protected:
	int size;
	Shape* next;
	virtual void draw() = 0;
public:
	Shape(int s = 1) { size = s; next = NULL; }
	virtual ~Shape() { }
	void paint() { draw(); }
	Shape* add(Shape* p);
	Shape* getNext() { return next; }

	friend class GraphicEditor;
};

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}


class Triangle : public Shape {
protected:
	virtual void draw() { cout << "Triangle" << "(size " << size << ") " << endl; }
public:
	Triangle(int s = 1) : Shape(s) {}
};

class Rect : public Shape {
protected:
	virtual void draw() { cout << "Rectagle" << "(size " << size << ") " << endl; }
public:
	Rect(int s = 1) : Shape(s) {}
};

class Line : public Shape {
protected:
	virtual void draw() { cout << "Line" << "(size " << size << ") " << endl; }
public:
	Line(int s = 1) : Shape(s) {}
};


ostream& operator<<(ostream& os, Shape* pFirst);

Shape* getEntry(Shape* pStart, int& pos);
int getListSize(Shape* qtr);
bool isEmpty(Shape* p);


//-------------   UI Ŭ���� (����� �Է� ó���� ���� static �Լ���θ� ����) -----------------
//
class UI {
public:
	static void Introduce() { cout << endl << " �׷��ȿ������Դϴ�." << endl; }
};

 

class MenuManager {
	int userChoice;
	bool stopFlag;
public:
	MenuManager(int _userChoice = 0) : userChoice(_userChoice) { stopFlag = false; }
	bool isStopActivated() { return stopFlag; }
	int getUserChoice() { return userChoice; }

	static void printBasicMenu();
	static void printAddDetailMenu();
	static void printRemoveDetailMenu();

	void waitForMenuSelection(bool& inputValidationChecker);

	int getShapeSelection();
	int getItemSelection();
};

void MenuManager::printBasicMenu() {
	cout << endl << " ����:1, ����:2, ��κ���:3, ����:4 >> ";
}
void MenuManager::printAddDetailMenu() { cout << " ��:1, �ﰢ��:2, �簢��:3 >> "; }
void MenuManager::printRemoveDetailMenu() { cout << endl << " �����ϰ� ���� �������� ���� ��ȣ �Է� >> "; }

void MenuManager::waitForMenuSelection(bool& inputValidationChecker) {
	cin >> userChoice;
	if (userChoice == INSERT || userChoice == REMOVE || userChoice == VIEW) inputValidationChecker = false;
	else if (userChoice == PROGRAM_EXIT) {
		inputValidationChecker = true;
		stopFlag = true;
	}
	else {
		inputValidationChecker = true;
	}
}

int MenuManager::getShapeSelection() {
	int selected;

	cin >> selected;
	switch (selected)
	{
	case LINE_SHAPE:
	case TRIANGLE_SHAPE:
	case RECT_SHAPE:
		break;
	default:
		selected = LINE_SHAPE;
		break;
	}
	return selected;
}
int MenuManager::getItemSelection() { 
	int itemNumSelected;

	cin >> itemNumSelected;

	return itemNumSelected;
}




// operator Function
ostream& operator<<(ostream& os, Shape* pFirst)
{
	Shape* pCur = pFirst;

	for (int i = 0; pCur != NULL; i++) {
		os << i;
		os << ':';
		pCur->paint();
		pCur = pCur->getNext();
	}

	return os;

}




//-------------  GraphicEditor Ŭ���� (���� ����Ʈ �����ϸ� Run() �Լ��� ������ ����)  ------------------
//
class GraphicEditor
{
	Shape* pStart, * pLast;
protected:
	void innerAddLogic(Shape* sp);
	void innerDelLogic(Shape* itemPtr, int pos, bool lastDel = false);
public:
	GraphicEditor();
	~GraphicEditor();		

	void ShowAll();

	void itemAdd(int shapeForm);

	void itemDel(int n);		

	void Run();
};



GraphicEditor::GraphicEditor() {     
	pStart = pLast = NULL;
}
GraphicEditor::~GraphicEditor() {
	Shape* delPtr = pStart;

	while (delPtr != NULL) {
		Shape* q = delPtr->getNext();
		delete delPtr;
		delPtr = q;
	}
}   


void GraphicEditor::ShowAll() {

	cout << pStart;  // ������ �����ε�

	/*Shape* ptr = pStart;

	for (int i = 0; ptr != NULL; i++) {
		cout << i;
		cout << ':';
		ptr->paint();
		ptr = ptr->getNext();
	}*/
}



// Normal Function
Shape* getEntry(Shape* pStart, int& pos) {
	int i = 0;
	Shape* cur = pStart;  

	while (i != pos) {
		cur = cur->getNext();

		i++;
	}

	return cur;   // pos ��ġ�� ��� ����
}

// Normal Function
int getListSize(Shape* qtr) {
	int i;
	for (i = 0; qtr != NULL; i++) {
		qtr = qtr->getNext();
	}
	return i;
}

// Normal Function
bool isEmpty(Shape* p) {
	return getListSize(p) == 0;
}




void GraphicEditor::innerAddLogic(Shape* sp) {

	// ó�� �����ϴ� ���� �׷��� ���� ��츦 ����� ó��

	if (pStart == pLast && pLast == NULL) {
		pStart = sp;
		pLast = pStart;
	}
	else {
		pLast = pLast->add(sp);
	}

}
void GraphicEditor::itemAdd(int shapeForm) {

	if (shapeForm == LINE_SHAPE) {
		innerAddLogic(new Line(rand() % 10 + 1));
	}
	else if (shapeForm == TRIANGLE_SHAPE) {
		innerAddLogic(new Triangle(rand() % 10 + 1));
	}
	else if (shapeForm == RECT_SHAPE) {
		innerAddLogic(new Rect(rand() % 10 + 1));
	}
	else {
		;
	}

}

void GraphicEditor::innerDelLogic(Shape* itemPtr, int pos, bool lastDel) {
	int _pos = pos - 1;
	Shape* pre = getEntry(pStart, _pos);            
	
	if (lastDel) {
		pre->next = NULL;
		pLast = pre;
	}
	else {
		pre->next = itemPtr->next;  // friend �̿�
	}

	delete itemPtr;  // ����Ű�� �ִ� ��� �ٷ� ����
}
void GraphicEditor::itemDel(int n) {
	if (isEmpty(pStart) || n < 0 || n >= getListSize(pStart)) { return; }   

	if (n == 0) {
		if (getListSize(pStart) == 1) {
			Shape* itemPtr = pLast;
			delete itemPtr;
			pStart = pLast = NULL;
			return;
		}
		else {
			Shape* pUselessHead = pStart;
			Shape* qp = pStart->next;
			delete pUselessHead;
			pStart = qp;

			return;
		
		}
	}

	if (getListSize(pStart) >= 2) {

		if (n == (getListSize(pStart) - 1)) {
			bool lastDel = true;
			innerDelLogic(getEntry(pStart, n), n, lastDel);
		}
		else {
			innerDelLogic(getEntry(pStart, n), n);   // n ��ġ�� �����͸� del
		}
		
	}
}

void GraphicEditor::Run() {

	srand((unsigned) time(NULL));
	UI::Introduce();

	MenuManager menuManager;

	bool inputAbnormal = true;

	do {
		if (menuManager.isStopActivated() == true) break;
		menuManager.printBasicMenu();
		menuManager.waitForMenuSelection(inputAbnormal);
		if (inputAbnormal) continue;


		switch (menuManager.getUserChoice()) {
		case INSERT:
			menuManager.printAddDetailMenu();
			itemAdd(menuManager.getShapeSelection());
			break;
		case REMOVE:
			menuManager.printRemoveDetailMenu();  
			itemDel(menuManager.getItemSelection()); 
			break;
		case VIEW:
			ShowAll();
			break;
		}

	} while (true);
}







int main()
{
	GraphicEditor ge;
	
	ge.Run();

	return 0;
}
