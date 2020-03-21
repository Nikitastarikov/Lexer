#include <iostream>
#include <fstream>
#include <string>

#include "Token.h"
#include "Lexer.h"
#include "Function.h"

using namespace std;

void Lexer::GetNextToken(string Line, int LineNumber, int EndFileId) {
	
	int Identifier = 0;
	int Size = Line.size();
	СharacterReadMode = 0; // Флаг, сигнализирующий о том, что идет считывание из ковычек

	if (EndFileId) { // Проверка на конец файла
		Token ob;
		ob.SetTypeToken(Token::Words::End);
		ob.SetString("\0");
		cout << "Loc<" << LineNumber << ":" << 1 << "> " << ob.GetTypeToken() << " '" << ob.GetString() << "'" << endl;
	}
	else {
		while (Identifier < Size) {
			while (СharacterReadMode != 2 && isspace(Line[Identifier])) { // Пропускаем все пробелы
				Identifier++;
			}

			if (СharacterReadMode == 2) { // Считываем строку пока не встретим знак " или строка не закончится
				Token ob;
				int SizeSubLine = 0;
				int TemporaryIdentifier = Identifier;
				while (Line[TemporaryIdentifier] != '"' && TemporaryIdentifier < Size - 1) {
					TemporaryIdentifier++;
					SizeSubLine++;
				}
				ob.SetTypeToken(Token::Words::String);
				ob.SetString(Line.substr(Identifier, SizeSubLine));
				cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << ob.GetString() << "'" << endl;
				Identifier = TemporaryIdentifier - 1;
				СharacterReadMode = 0;
				break;
			}
			else if (strchr("+-/*%=()[]{}<>;.:,", Line[Identifier])) { // Считывание операторов
				WordZnak(Line, LineNumber, Size, Identifier);
			}
			else if (isletter(Line[Identifier])) { // Считывание ключевых слов
				WordString(Line, LineNumber, Size, Identifier, СharacterReadMode);
			}
			else if (isdigit(Line[Identifier])) { // Считывание чисел
				WordDigit(Line, LineNumber, Identifier);
			}
			else if (Line[Identifier] == '\'') { // Считывание значения из одинарных ковычек
				Token ob;
				ob.SetTypeToken(Token::Words::SingleQuote);
				cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << "'" << "'" << endl;
				СharacterReadMode = 1; 
			}
			else if (Line[Identifier] == '\"') { // Начинаем считывать значение из двойных ковычек 
				Token ob;
				ob.SetTypeToken(Token::Words::DoubleQuote);
				cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << '\"' << "'" << endl;
				СharacterReadMode = 2; 
			}
			Identifier++;

		}
	}
}


int main() {
	//setlocale(LC_ALL, "RUS");
	ifstream fileinput("MIN.cs", ios::in || ios::binary);
	if (!fileinput) {
		fileinput.close();
		cerr << "Fileinput open error" << endl;
		return -1;
	}

	Lexer Lex;
	string Line;
	int LineNumber = 1;
	while (!fileinput.eof()) {
		getline(fileinput, Line);
		Lex.GetNextToken(Line, LineNumber, 0);
		LineNumber++;
	}
	Lex.GetNextToken(Line, LineNumber, 1);
	fileinput.close();

	system("pause");
	return 0;
}