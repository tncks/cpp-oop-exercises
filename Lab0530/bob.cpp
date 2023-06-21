#include "monoalpha.h"
#include <iostream>
#include <fstream>

void fileHelperMethod(const char * fileName) {
	ifstream istrm(fileName, ios::in);
	char data;

	std::cout << "[������ ���������� ���Ȱ�, ���� �ؽ�Ʈ ������ �����Խ��ϴ�..]" << std::endl;
	std::cout << "--- ���� ���� ------------------------" << std::endl << std::endl;
	while (istrm.get(data)) {
		std::cout << data;
	}
	std::cout << std::endl << std::endl;
	std::cout << "--- ���̻��� �����Ͱ� �����ϴ�, �� ---" << std::endl;
	istrm.close();
}

int main() {

	MonoAlpha textFileDecrypterManager;
	char openChoice;

	textFileDecrypterManager.decrypt("privateCommunicationFileBetweenAliceAndBob", "decryptionResultFromHerSecret");

	std::cout << std::endl << std::endl;

	std::cout << "���� �ٷ� �ص��� ������ �����Ͻðڽ��ϱ�? [y/n] >> ";
	std::cin >> openChoice;

	std::cout << std::endl << std::endl;

	switch (openChoice)
	{
	case 'y':
	case 'Y':
		std::cout << "�ص��� ������ ���� ���Դϴ�..." << std::endl << std::endl;
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

	std::cout << "�� �� ���� �����Ƿ�, ���α׷� �����մϴ�. Bye.." << std::endl;

	return 0;
}