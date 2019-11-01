#include "StringCast.h"

std::string castToString(const bool& value)
{
	return value ? "true" : "false";
}

std::string castToString(const int8_t& value)
{
	return std::to_string(value);
}

std::string castToString(const int16_t& value)
{
	return std::to_string(value);
}

std::string castToString(const int32_t& value)
{
	return std::to_string(value);
}

std::string castToString(const int64_t& value)
{
	return std::to_string(value);
}

std::string castToString(const uint8_t& value)
{
	return std::to_string(value);
}

std::string castToString(const uint16_t& value)
{
	return std::to_string(value);
}

std::string castToString(const uint32_t& value)
{
	return std::to_string(value);
}

std::string castToString(const uint64_t& value)
{
	return std::to_string(value);
}

std::string castToString(const float& value)
{
	return std::to_string(value);
}

std::string castToString(const std::string& value)
{
	return value;
}

std::string castToString(const double& value)
{
	return std::to_string(value);
}


// from string

template <>
bool fromString(const std::string& valueStr)
{
	if (valueStr == "true") {
		return true;
	}
	else if (valueStr == "false") {
		return false;
	}
}



template <>
uint8_t fromString(const std::string& valueStr)
{

	return std::stoul(valueStr);
}

template <>
uint16_t fromString(const std::string& valueStr)
{
	return std::stoul(valueStr);


}

template <>
uint32_t fromString(const std::string& valueStr)
{
	return std::stoll(valueStr);


}

template <>
uint64_t fromString(const std::string& valueStr)
{
	return std::stoll(valueStr);


}

template <>
int8_t fromString(const std::string& valueStr)
{

	return std::stoi(valueStr);

}

template <>
int16_t fromString(const std::string& valueStr)
{
	return std::stoi(valueStr);


}

template <>
int32_t fromString(const std::string& valueStr)
{
	return std::stol(valueStr);

}

template <>
int64_t fromString(const std::string& valueStr)
{
	return std::stol(valueStr);

}



template <>
double fromString(const std::string& valueStr)
{
	return std::stof(valueStr);
}

template <>
float fromString(const std::string& valueStr)
{
	return std::stof(valueStr);
}

template <>
std::string fromString(const std::string& valueStr)
{
	return valueStr;
}

