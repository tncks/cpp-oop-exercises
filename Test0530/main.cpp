#include <iostream>
#include <string>
#include <cstring>
// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2015 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

 // 17.4.1.2 Headers

 // C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

string plainText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string encoder(string key) {

	string encoded;
	bool arr[26] = { 0 };

	for (int i = 0; i < key.size(); i++) {
		if (key[i] >= 'A' && key[i] <= 'Z') {

			if (arr[key[i] - 65] == 0) {
				encoded += key[i];
				arr[key[i] - 65] = 1;
			}
		}
		else if (key[i] >= 'a' && key[i] <= 'z') {

			if (arr[key[i] - 97] == 0) {
				encoded += key[i] - 32;
				arr[key[i] - 97] = 1;
			}

		}
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
			encoded += char(i + 65);
		}

	}

	return encoded;

}

string decipherdIt(string msg, string encoded) {

	map<char, int> enc;
	for (int i = 0; i < encoded.size(); i++) {
		enc[encoded[i]] = i;
	}

	string decipher;

	for (int i = 0; i < msg.size(); i++) {
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			int pos = enc[msg[i] - 32];
			decipher += plainText[pos];

		}
		else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			int pos = enc[msg[i]];
			decipher += plainText[pos];
		}
		else {
			decipher += msg[i];
		}
	}

	return decipher;

}

int main() {

	string key;
	key = "Computer";
	cout << "Keyword : " << key << endl;

	string encoded = encoder(key);

	string misteriousMessage = "EUUDN TIL EUUDN";
	cout << "M b D : " << misteriousMessage << endl;

	cout << "Ciphered Text: " << decipherdIt(misteriousMessage, encoded);

	cout << endl << endl << "Press Enter Twice! :) Enter Enter gogo" << endl;
	getchar();
	getchar();
	cout << endl;

	/*---------------------------------------------------*/
	/*---------------------------------------------------*/
	/*---------------------------------------------------*/

	std::vector<char> all_alpha{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	std::string keyword = "Star War";
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	std::vector<char> keyword1;

	for (char c : keyword) {
		if (std::find(keyword1.begin(), keyword1.end(), c) == keyword1.end()) {
			keyword1.push_back(c);
		}
	}


	std::string ciphertext = "SPPSAGRSVJ";
	std::transform(ciphertext.begin(), ciphertext.end(),
		ciphertext.begin(), ::toupper);
	std::vector<char> ct;
	for (char c : ciphertext) {
		if (c != ' ') {
			ct.push_back(c);
		}
	}

	std::vector<char> encrypting = keyword1;
	for (char c : all_alpha) {
		if (std::find(encrypting.begin(), encrypting.end(), c) == encrypting.end()) {
			encrypting.push_back(c);
		}
	}

	encrypting.erase(std::remove(encrypting.begin(), encrypting.end(), ' '), encrypting.end());

	std::string message;
	for (char c : ct) {
		if (c != ' ') {
			auto it = std::find(encrypting.begin(), encrypting.end(), c);

			int index = std::distance(encrypting.begin(), it);

			message += all_alpha[index];
		}
		else {
			message += ' ';
		}
	}

	std::cout << "Keyword : " << keyword << std::endl;
	std::cout << "Ciphered Text : " << ciphertext
		<< std::endl;
	std::cout << "Message before Ciphering : " << message
		<< std::endl;



	cout << endl << endl << "Now,, exit program.. bye!" << endl;

	return 0;
}