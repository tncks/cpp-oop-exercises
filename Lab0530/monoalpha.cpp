#include "monoalpha.h"
#include <fstream>
#include <iostream>

void MonoAlpha::encrypt(const char* plainFile, const char* cipherFile) {
    ifstream istrm(plainFile, ios::in);
    ofstream ostrm(cipherFile, ios::out);
    char c1, c2;
    while (istrm.get(c1)) {
        c2 = searchEncrypt(c1);
        ostrm.put(c2);
    }
    istrm.close();
    ostrm.close();

    cout << "암호화 및 복호화 기본 작업 완료, 파일에 저장완료됨.." << endl;
}


void MonoAlpha::decrypt(const char* cipherFile, const char* plainFile) {
    ifstream istrm(cipherFile, ios::in);
    ofstream ostrm(plainFile, ios::out);
    char c1, c2;
    while (istrm.get(c1)) {
        c2 = searchDecrypt(c1);
        ostrm.put(c2);
    }
    istrm.close();
    ostrm.close();

    cout << "암호화 및 복호화 기본 작업 완료, 파일에 저장완료됨.." << endl;
}


char MonoAlpha::searchEncrypt(char c) {


    for (int i = 0; ; i++)
        if (key[i][0] == c)
            return key[i][1];

}


char MonoAlpha::searchDecrypt(char c) {

    for (int i = 0; ; i++)
        if (key[i][1] == c)
            return key[i][0];

}









const char MonoAlpha::key[][2] = { {'a', 'N'}, {'b', 'O'},
      {'c', 'A'}, {'d', 'T'}, {'e', 'R'}, {'f', 'B'}, {'g', 'E'}, {'h', 'C'},
      {'i', 'F'}, {'j', 'U'}, {'k', 'X'}, {'l', 'D'}, {'m', 'Q'}, {'n', 'G'},
      {'o', 'Y'}, {'p', 'L'}, {'q', 'K'}, {'r', 'H'}, {'s', 'V'}, {'t', 'I'},
      {'u', 'J'}, {'v', 'M'}, {'w', 'P'}, {'x', 'Z'}, {'y', 'S'}, {'z', 'W'} };