#pragma once
#include <string>

namespace MathUtils
{

	bool isDigit(const std::string& str);
	bool isNumeric(const std::string& str);
	bool isHex(const std::string& str);

	int32_t getDigit(const std::string& str);
	double getFloat(const std::string& str);






}