#include "Expression.h"
#include <iostream>
#include "CadProcessor/GCode/Parser/GCodeParser.h"

void Expression::parseExpression(std::string& exp)
{	


	convertUnaryBracket(exp);
	parseBrackets(exp);	
	parseUnaryOperator(exp);

}



void Expression::parseBrackets(std::string& instr)
{

	// Check for nested brackets
	std::regex exp("(\\[[^\\[]*?\\])", std::regex_constants::icase);
	std::smatch match;

	while (std::regex_search(instr, match, exp))
	{


		std::string sub = match.str(0);

		sub = sub.substr(1, sub.size() - 2); // remove brackets

		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


		std::string sanitized = std::regex_replace(match.str(0), specialChars, R"(\$&)");

		parseBrackets(sub);
		instr = std::regex_replace(instr, std::regex(sanitized), sub);


	}

	parseBinaryOperators(instr);

}

void Expression::parseUnaryOperator(std::string & instr)
{
	// TODO This function doesn't properly handle nested paren... results in messed up results
	// under certain conditions...std::regex can't handle irregular expressions so I need to 
	// make a balancing function ... sigh

	std::string operators = "(ATAN|ACOS|ASIN|ABS|COS|EXP|FIX|FUP|LN|ROUND|SIN|SQRT|TAN)";
	std::string divideExpStr = "(\\(.*?\\)+\/\\(.*?\\)+)";
	std::string singleExpStr = "(\\((.*?\\))+)";
	std::string argExpStr = "(" + divideExpStr + "|" + singleExpStr + ")";
	

	//std::regex exp(operators + argExpStr, std::regex_constants::icase);
	std::regex singleExp(operators + singleExpStr, std::regex_constants::icase);
	std::regex divideExp(operators + divideExpStr, std::regex_constants::icase);
	std::smatch match;
	
	if (std::regex_search(instr, match, singleExp))
	{

		std::string sub = match.str(0);
		std::smatch argMatch;
		std::regex argExp(singleExpStr);
		if (std::regex_search(sub, argMatch, argExp))
		{
			// First match will be the largest since regex is greedy
			std::string argSubStr = match.str(2);
			size_t endParen = balanceBrackets(argSubStr, 0, '(', ')', '(', ')');
			argSubStr = argSubStr.substr(0, endParen);
			parseBrackets(argSubStr);
			double op = atof(argSubStr.substr(1,argSubStr.size() - 2).c_str());
			// matches any characters that need to be escaped in RegEx
			std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


			std::string sanitized = std::regex_replace(match.str(0), specialChars, R"(\$&)");

			std::string opStr = match.str(1);
			double res = processUniOperator(op, opStr);
			instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(res));


		}

	}
	if (std::regex_search(instr, match, divideExp))
	{

		std::string sub = match.str(0);
		std::smatch argMatch;
		std::regex argExp(divideExpStr);
		if (std::regex_search(sub, argMatch, argExp))
		{
			// First match will be the largest since regex is greedy
			std::string argSubStr = match.str(2);

			parseBrackets(argSubStr);
			double op = atof(argSubStr.substr(1, argSubStr.size() - 2).c_str());
			// matches any characters that need to be escaped in RegEx
			std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


			std::string sanitized = std::regex_replace(match.str(0), specialChars, R"(\$&)");

			std::string opStr = match.str(1);
			double res = processUniOperator(op, opStr);

			if (std::trunc(res) == res)
			{
				int32_t truncRes = static_cast<int32_t>(res);
				instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(truncRes));
			}
			else
			{
				instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(res));
			}




		}

	}


}

void replaceParam(std::string& instr)
{
	std::regex exp("((\\#(\\d+)))", std::regex_constants::icase);
	std::smatch match;
	std::shared_ptr<GCodeParser> parser = GCodeParser::getGCodeParser();

	while (std::regex_search(instr, match, exp))
	{

		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };

		std::string numStr = match.str(3);
		double num = parser->getParam(static_cast<uint16_t>(atoi(numStr.c_str())));

		std::string sanitized = std::regex_replace(match.str(2), specialChars, R"(\$&)");


		instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(num));
	}
}


void Expression::parseBinaryOperators(std::string & instr)
{
	//std::shared_ptr<GCodeParser> parser = GCodeParser::getGCodeParser();
	//parser->parameterInputReplacement(instr);
	parseUnaryOperator(instr);
	parseGroup1(instr); // exponents
	parseGroup2(instr); // multiply, divide, modulus
	parseGroup3(instr); // addition, subtraction, logical operators
	

	// String should be a number at this point://TODO not true


}


void Expression::parseGroup(std::string & instr, const std::string operatorExp)
{

	std::string number = "([+-]?(\\d+\\.\\d+|\\d+|\\.\\d+|\\d+\\.))";
	std::string number2 = "([+-]{1}(\\d+\\.\\d+|\\d+|\\.\\d+|\\d+\\.))";

	//std::string number = "(((+|-))?(\\d+\\.\\d+|\\d+|\\.\\d+|\\d+\\.))";
	std::string doubleNumber = number + number2;


	std::regex exp(doubleNumber + operatorExp + number, std::regex_constants::icase);
	std::regex exp2(number + operatorExp + number, std::regex_constants::icase);

	std::smatch match;



	if (std::regex_search(instr, match, exp))
	{
		std::string op1 = match.str(4);
		std::string op2 = match.str(6);


		std::string opStr = match.str(5);

		double res = processOperator(atof(op1.c_str()), atof(op2.c_str()), opStr);


		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


		std::string sanitized = std::regex_replace(op1 + opStr + op2, specialChars, R"(\$&)");
		if (std::trunc(res) == res)
		{
			int32_t truncRes = static_cast<int32_t>(res);
			instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(truncRes));
		}
		else
		{
			instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(res));
		}
		


		parseBinaryOperators(instr);



	}
	else if (std::regex_search(instr, match, exp2))
	{
		std::string op1 = match.str(1);
		std::string op2 = match.str(4);


		std::string opStr = match.str(3);

		double res = processOperator(atof(op1.c_str()), atof(op2.c_str()), opStr);


		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


		std::string sanitized = std::regex_replace(match.str(0), specialChars, R"(\$&)");

		if (std::trunc(res) == res)
		{
			int32_t truncRes = static_cast<int32_t>(res);
			instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(truncRes));
		}
		else
		{
			instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(res));
		}


		parseBinaryOperators(instr);
	}

}

size_t Expression::balanceBrackets(std::string& arg, size_t startPos, char startChar, char endChar, char replaceStart, char replaceEnd)
{

	size_t origStart = startPos;
	size_t ret = 0;
	std::string processedArg = "";
	if (startChar == arg.at(startPos))
	{
		uint32_t startCnt = 1;
		uint32_t endCnt = 0;
		size_t endPos = 0;
		while (startPos < arg.size())
		{
			size_t nextStart = arg.find(startChar, startPos + 1);
			size_t nextEnd = arg.find(endChar, startPos + 1);
			if (nextEnd == endPos)
			{
				nextEnd = arg.find(endChar, endPos + 1);
			}
			if (std::string::npos == nextEnd)
			{
				processedArg = "";
				break;
			}
			if (nextEnd < nextStart) // if nextStart is npos this is still true
			{
				endCnt++;
				if (endCnt == startCnt)
				{
					processedArg = arg.substr(0, nextEnd + 1);
					break;
				}
				if (std::string::npos != nextStart)
				{
					startCnt++;

					startPos = nextStart;
				}
				else
				{
					startPos = nextEnd + 1;
				}
			}
			else
			{
				startPos = nextStart;
				startCnt++;
				endCnt++;
			}
			endPos = nextEnd;
		}
		if (endCnt != startCnt)
		{
			processedArg = "";
		}
		if (!processedArg.empty())
		{
			std::string origArg = processedArg;
			processedArg.at(origStart) = replaceStart;
			processedArg.at(processedArg.size() - 1) = replaceEnd;
			ret = processedArg.size();

			// matches any characters that need to be escaped in RegEx
			std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


			std::string sanitized = std::regex_replace(origArg, specialChars, R"(\$&)");

			arg = std::regex_replace(arg, std::regex(sanitized), processedArg);
		}
	}
	else
	{
	}
	return ret;
}

void Expression::convertUnaryBracket(std::string& instr)
{

	std::string operators = "(ATAN|ACOS|ASIN|ABS|COS|EXP|FIX|FUP|LN|ROUND|SIN|SQRT|TAN)";



	std::regex exp(operators + "(\\[.*\\])", std::regex_constants::icase);

	std::smatch match;

	while (std::regex_search(instr, match, exp))
	{

		std::string arg = match.str(2);
		size_t end = balanceBrackets(arg, 0, '[', ']', '(', ')');
		if ('/' == arg.at(end))
		{
			balanceBrackets(arg, end + 1, '[', ']', '(', ')');
		}
		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };


		std::string sanitized = std::regex_replace(match.str(2), specialChars, R"(\$&)");

		instr = std::regex_replace(instr, std::regex(sanitized), arg);

	}
}

void Expression::parseGroup1(std::string & instr)
{

	std::string operators = "(\\*\\*)";
	parseGroup(instr, operators);
}

void Expression::parseGroup2(std::string & instr)
{
	std::string operators = "([\\/|\\*|MOD])";
	parseGroup(instr, operators);
}

void Expression::parseGroup3(std::string & instr)
{
	std::string operators = "([\\-|\\+|XOR|OR|AND|EQ|NE|GT|GE|LT|LE])";
	parseGroup(instr, operators);

}

double Expression::processOperator(double op1, double op2, const std::string & op)
{
	double ret = 0;
	std::string upOp = "";
	for (int i = 0; i < op.length(); i++)
	{
		if (op[i] >= 'a' && op[i] <= 'z')
		{
			upOp += op[i] + ('A' - 'a');
		}
		else
		{
			upOp += op[i];
		}
	}
	if ("**" == upOp)
	{
		ret = pow(op1, op2);
	}
	else if ("MOD" == upOp)
	{

		ret = fmod(op1, op2);

	}
	else if ("/" == upOp)
	{
		ret = op1 / op2;
	}
	else if ("*" == upOp)
	{
		ret = op1 * op2;
	}
	else if ("+" == upOp)
	{
		ret = op1 + op2;
	}
	else if ("-" == upOp)
	{
		ret = op1 - op2;
	}
	else if ("EQ" == upOp)
	{
		ret = (op1 == op2);
	}
	else if ("NE" == upOp)
	{
		ret = (op1 != op2);
	}
	else if ("GT" == upOp)
	{
		ret = (op1 > op2);
	}
	else if ("GE" == upOp)
	{
		ret = (op1 >= op2);
	}
	else if ("LT" == upOp)
	{
		ret = (op1 < op2);
	}
	else if ("LE" == upOp)
	{
		ret = (op1 <= op2);
	}
	else if ("XOR" == upOp)
	{
		uint8_t binOp1 = 0;
		uint8_t binOp2 = 0;
		if (0 != op1)
		{
			binOp1 = 1;
		}
		if (0 != op2)
		{
			binOp2 = 1;
		}
		ret = static_cast<double>(binOp1 ^ binOp2);
	}
	else if ("OR" == upOp)
	{
		uint8_t binOp1 = 0;
		uint8_t binOp2 = 0;
		if (0 != op1)
		{
			binOp1 = 1;
		}
		if (0 != op2)
		{
			binOp2 = 1;
		}
		ret = static_cast<double>(binOp1 | binOp2);
	}
	else if ("AND" == upOp)
	{
		uint8_t binOp1 = 0;
		uint8_t binOp2 = 0;
		if (0 != op1)
		{
			binOp1 = 1;
		}
		if (0 != op2)
		{
			binOp2 = 1;
		}
		ret = static_cast<double>(binOp1 & binOp2);
	}
	else
	{
		std::cout << "Expression : Invalid Operation." << std::endl;
	}
	return ret;
}

double Expression::processUniOperator(double op1, const std::string & op)
{

	const double PI = 3.1415926535;

	double ret = 0.0;
	std::string upOp = "";
	for (int i = 0; i < op.length(); i++)
	{
		if (op[i] >= 'a' && op[i] <= 'z')
		{
			upOp += op[i] + ('A' - 'a');
		}
		else
		{
			upOp += op[i];
		}
	}
	// ATAN|ACOS|ASIN|ABS|COS|EXP|FIX|FUP|LN|ROUND|SIN|SQRT|TAN
	if ("ATAN" == upOp)
	{
		ret = atan(op1) * 180 / PI;

	}
	else if ("ACOS" == upOp)
	{
		ret = acos(op1) * 180 / PI;

	}
	else if ("ASIN" == upOp)
	{
		ret = asin(op1) * 180 / PI;

	}
	else if ("ABS" == upOp)
	{
		ret = abs(op1);

	}
	else if ("COS" == upOp)
	{
		ret = cos(op1 * PI / 180);

	}
	else if ("EXP" == upOp)
	{
		ret = exp(op1);

	}
	else if ("FIX" == upOp)
	{
		ret = floor(op1);

	}
	else if ("FUP" == upOp)
	{
		ret = ceil(op1);

	}
	else if ("LN" == upOp)
	{
		ret = log(op1);

	}
	else if ("ROUND" == upOp)
	{
		ret = round(op1);

	}
	else if ("SIN" == upOp)
	{
		ret = sin(op1 * PI / 180);

	}
	else if ("SQRT" == upOp)
	{
		ret = sqrt(op1);

	}
	else if ("TAN" == upOp)
	{
		ret = tan(op1 * PI / 180);

	}
	else
	{
		std::cout << "Expression : Invalid Unary Operation." << std::endl;


	}
	return ret;
}
