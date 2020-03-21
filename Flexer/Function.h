#pragma once
#include "Token.h"
#include "Lexer.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Token::Words& kind) {
	static const char* const names[]{
		"Number",	   "Identifier",  "LeftParen", "RightParen",  "LeftSquare", "RightSquare",
		"LeftCurly",   "RightCurly",  "LessThan",  "GreaterThan", "Equal",      "Plus",
		"Minus",       "Asterisk",    "Slash",     "Percent",     "Colon",  "Semicolon",
		"SingleQuote", "DoubleQuote", "Comma",   "String",      "Letter",  "Keyworld",
		"Type",        "Point",       "Library",   "End",         "Unexpected",
	};
	return os << names[static_cast<int>(kind)];
}

int isletter(char a) {
	if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z')) {
		return 1;
	}
	return 0;
}

Token WordDigit(string &Line, int &LineNumber, int &Identifier) {

	int SizeSubLine = 1, TemporaryIdentifier = Identifier + 1;
	Token ob;
	while (isdigit(Line[TemporaryIdentifier])) {
		TemporaryIdentifier++;
		SizeSubLine++;
	}
	ob.SetTypeToken(Token::Words::Number);
	ob.SetString(Line.substr(Identifier, SizeSubLine));
	cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << ob.GetString() << "'" << endl;
	Identifier = TemporaryIdentifier - 1;

	return ob;
}

Token WordString(string &Line, int &LineNumber, int &Size, int &Identifier, int &ÑharacterReadMode) {
	Token ob;
	int SizeSubLine, TemporaryIdentifier;
	switch (ÑharacterReadMode) {
	case 1:
		ob.SetTypeToken(Token::Words::Letter);
		ob.SetString(Line.substr(Identifier, 1));
		cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << Line[Identifier] << "'" << endl;
		ÑharacterReadMode = 0;
		break;
	case 0:
		SizeSubLine = 1;
		TemporaryIdentifier = Identifier + 1;
		
		while (isletter(Line[TemporaryIdentifier])) {
			SizeSubLine++;
			TemporaryIdentifier++;
		}
		ob.SetString(Line.substr(Identifier, SizeSubLine));

		if (ob.GetString() == "using") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "class") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "static") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "for") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "if") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "new") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "for") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "return") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "else") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "for") {
			ob.SetTypeToken(Token::Words::Keyworld);
		}
		else if (ob.GetString() == "System") {
			ob.SetTypeToken(Token::Words::Library);
		}
		else if (ob.GetString() == "void") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else if (ob.GetString() == "var") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else if (ob.GetString() == "int") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else if (ob.GetString() == "char") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else if (ob.GetString() == "float") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else if (ob.GetString() == "double") {
			ob.SetTypeToken(Token::Words::Type);
		}
		else {
			ob.SetTypeToken(Token::Words::Identifier);
		}
		cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << ob.GetString() << "'" << endl;
		Identifier = TemporaryIdentifier - 1;
		break;
	}
	return ob;
}

Token WordZnak(string &Line, int &LineNumber, int &Size, int &Identifier) {
	Token ob;
	switch (Line[Identifier]) {
	case '+':
		ob.SetTypeToken(Token::Words::Plus);
		ob.SetString("+");
		break;
	case '-':
		ob.SetTypeToken(Token::Words::Minus);
		ob.SetString("-");
		break;
	case '/':
		if (Identifier + 1 < Size)
			if (Line.at(Identifier + 1) == '/') {
				Identifier = Size;
			}
		ob.SetTypeToken(Token::Words::Slash);
		ob.SetString("/");
		break;
	case '*':
		ob.SetTypeToken(Token::Words::Asterisk);
		ob.SetString("*");
		break;
	case '%':
		ob.SetTypeToken(Token::Words::Percent);
		ob.SetString("%");
		break;
	case '=':
		ob.SetTypeToken(Token::Words::Equal);
		ob.SetString("=");
		break;
	case '(':
		ob.SetTypeToken(Token::Words::LeftParen);
		ob.SetString("(");
		break;
	case ')':
		ob.SetTypeToken(Token::Words::RightParen);
		ob.SetString(")");
		break;
	case '[':
		ob.SetTypeToken(Token::Words::LeftSquare);
		ob.SetString("[");
		break;
	case ']':
		ob.SetTypeToken(Token::Words::RightSquare);
		ob.SetString("]");
		break;
	case '{':
		ob.SetTypeToken(Token::Words::LeftCurly);
		ob.SetString("{");
		break;
	case '}':
		ob.SetTypeToken(Token::Words::RightCurly);
		ob.SetString("}");
		break;
	case ';':
		ob.SetTypeToken(Token::Words::Semicolon);
		ob.SetString(";");
		break;
	case '.':
		ob.SetTypeToken(Token::Words::Point);
		ob.SetString(".");
		break;
	case ':':
		ob.SetTypeToken(Token::Words::Colon);
		ob.SetString(":");
		break;
	case '<':
		ob.SetTypeToken(Token::Words::LessThan);
		ob.SetString("<");
		break;
	case '>':
		ob.SetTypeToken(Token::Words::GreaterThan);
		ob.SetString(">");
		break;
	case ',':
		ob.SetTypeToken(Token::Words::Comma);
		ob.SetString(",");
		break;
	}

	if (Identifier != Size)
		cout << "Loc<" << LineNumber << ":" << (Identifier + 1) << "> " << ob.GetTypeToken() << " '" << ob.GetString() << "'" << endl;
	return ob;
}