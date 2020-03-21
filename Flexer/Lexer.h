#pragma once
#include <iostream>
#include <string>

using namespace std;

class Lexer {

public:
	int ÑharacterReadMode = 0;
	Lexer() = default;
	~Lexer() = default;
	void GetNextToken(string line, int stroka, int last);
};