#include "MathUtils.h"
#include <regex>
#include <sstream>

bool MathUtils::isDigit(const std::string& str)
{
	bool ret = false;
	std::regex exp("-?[0-9]+");

	std::smatch match;


	if (std::regex_search(str, match, exp))
	{
		ret = true;
	}
	// else return false


	return ret;
}


bool MathUtils::isNumeric(const std::string& str)
{
	bool ret = false;
	std::regex exp("-?[0-9]+([.][0-9]+)?");

	std::smatch match;


	if (std::regex_search(str, match, exp))
	{
		ret = true;
	}
	// else return false


	return ret;
}

bool MathUtils::isHex(const std::string& str)
{
	bool ret = false;
	std::regex exp("0[xX]([0-9]|[a-f]|[A-F]){2,4}");

	std::smatch match;


	if (std::regex_search(str, match, exp))
	{
		ret = true;
	}
	// else return false


	return ret;
}

int32_t MathUtils::getDigit(const std::string& str)
{
	int32_t ret = 0x80000000; // most negative 32 bit number
	if (isDigit(str))
	{
		ret = std::stoi(str);

	}
	if (isHex(str))
	{

		std::stringstream ss;
		ss << std::hex << str;
		ss >> ret;

	}

	return ret;
}

double MathUtils::getFloat(const std::string& str)
{
	double ret = std::nan("-1");

	if (isNumeric(str))
	{
		ret = std::stod(str);

	}


	return ret;
}
