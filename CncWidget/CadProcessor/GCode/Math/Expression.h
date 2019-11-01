#pragma once
#include <string>
#include <regex>

class Expression
{

public:
	Expression(void) {}

	~Expression(void) {}

	void parseExpression(std::string& exp);

private:


	void parseBrackets(std::string& instr);

	void parseUnaryOperator(std::string& instr);

	void parseBinaryOperators(std::string& instr);

	void parseGroup(std::string& instr, const std::string operatorExp);

	void convertUnaryBracket(std::string& instr);
	size_t balanceBrackets(std::string& arg, size_t startPos, char startChar, char endChar, char replaceStart, char replaceEnd);



	void parseGroup1(std::string& instr);
	void parseGroup2(std::string& instr);
	void parseGroup3(std::string& instr);

	double processOperator(double op1, double op2, const std::string& op);
	double processUniOperator(double op1, const std::string& op);
};