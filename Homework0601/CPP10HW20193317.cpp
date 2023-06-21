//----------------------------------------------------
// 과제명:  C++ 과제10 - 그래픽 편집기 
// 작성자: 노수찬
// 개발도구: VisualStudio 2022
// 소감: C++의 다양한 기능들을 적용해보면서, 객체 지향의
//		 강력함을 많이 느낄 수 있었습니다.
//		 상속과 다형성, 캡슐화 개념을 더 잘 이해하게 되었습니다.
//		 그리고 리스트 데이터 추가 및 삭제 기능을 구현하는
//		 과정에서 연결 리스트에 대한 개념을 손으로 그려보며
//		 구체적으로 파고 들어가보고, 다시 복습할 수 있었습니다. 
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


//-------------   UI 클래스 (사용자 입력 처리를 위한 static 함수들로만 구성) -----------------
//
class UI {
public:
	static void Introduce() { cout << endl << " 그래픽에디터입니다." << endl; }
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
	cout << endl << " 삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
}
void MenuManager::printAddDetailMenu() { cout << " 선:1, 삼각형:2, 사각형:3 >> "; }
void MenuManager::printRemoveDetailMenu() { cout << endl << " 삭제하고 싶은 데이터의 행의 번호 입력 >> "; }

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




//-------------  GraphicEditor 클래스 (도형 리스트 관리하며 Run() 함수로 편집기 실행)  ------------------
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

	cout << pStart;  // 연산자 오버로딩

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

	return cur;   // pos 위치의 요소 리턴
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

	// 처음 삽입하는 경우와 그렇지 않은 경우를 나누어서 처리

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
		pre->next = itemPtr->next;  // friend 이용
	}

	delete itemPtr;  // 가리키고 있는 대상 바로 삭제
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
			innerDelLogic(getEntry(pStart, n), n);   // n 위치의 데이터를 del
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
