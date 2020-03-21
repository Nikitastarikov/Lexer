#pragma once
#include <iostream>
#include <string>

using namespace std;

class Token {
public:
	enum class Words {
		Number,
		Identifier,
		LeftParen, // (
		RightParen, // )
		LeftSquare, // [
		RightSquare, // ]
		LeftCurly, // {
		RightCurly, // }
		LessThan, // <
		GreaterThan, // >
		Equal, // =
		Plus, // +
		Minus, // -
		Asterisk, // *
		Slash, // /
		Percent, // %
		Colon, // :
		Semicolon, // ;
		SingleQuote, // ''
		DoubleQuote, // ""
		Comma, // ,
		String,
		Letter,
		Keyworld,
		Type,
		Point, // .
		Library,
		End,
		Unexpected,
	};


	Token() = default;
	Token(Words Token) : TokenType(Token) {}

	void SetTypeToken(Words Token) { TokenType = Token; }

	void SetString(string Str) { Line = Str; }

	Words GetTypeToken() noexcept { return TokenType; }

	string GetString() { return Line; }

private:
	Words TokenType{};
	string Line;
};