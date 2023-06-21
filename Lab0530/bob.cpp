#include "monoalpha.h"
#include <iostream>
#include <fstream>

void fileHelperMethod(const char * fileName) {
	ifstream istrm(fileName, ios::in);
	char data;

	std::cout << "[파일이 성공적으로 열렸고, 내부 텍스트 내용을 가져왔습니다..]" << std::endl;
	std::cout << "--- 파일 내용 ------------------------" << std::endl << std::endl;
	while (istrm.get(data)) {
		std::cout << data;
	}
	std::cout << std::endl << std::endl;
	std::cout << "--- 더이상의 데이터가 없습니다, 끝 ---" << std::endl;
	istrm.close();
}

int main() {

	MonoAlpha textFileDecrypterManager;
	char openChoice;

	textFileDecrypterManager.decrypt("privateCommunicationFileBetweenAliceAndBob", "decryptionResultFromHerSecret");

	std::cout << std::endl << std::endl;

	std::cout << "지금 바로 해독된 문서를 열람하시겠습니까? [y/n] >> ";
	std::cin >> openChoice;

	std::cout << std::endl << std::endl;

	switch (openChoice)
	{
	case 'y':
	case 'Y':
		std::cout << "해독된 문서를 여는 중입니다..." << std::endl << std::endl;
		fileHelperMethod("decryptionResultFromHerSecret");
		std::cout << std::endl << std::endl;
		break;
	case 'n':
	case 'N':
		std::cout << std::endl << std::endl;
		break;
	default:
		std::cout << std::endl << std::endl;
		std::cout << "program error.." << std::endl;
		break;
	}

	std::cout << "더 할 일이 없으므로, 프로그램 종료합니다. Bye.." << std::endl;

	return 0;
}