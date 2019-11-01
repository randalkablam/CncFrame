// In JSON map keys can only be strings, so here's a class which makes conversion to/from string easy
#pragma once

#include <string>
#include <type_traits>
#include "magic_enum.hpp"



template <typename T>
std::string castToString(const T& value);

// template specializations

std::string castToString(const bool& value);
std::string castToString(const int8_t& value);
std::string castToString(const int16_t& value);
std::string castToString(const int32_t& value);
std::string castToString(const int64_t& value);
std::string castToString(const uint8_t& value);
std::string castToString(const uint16_t& value);
std::string castToString(const uint32_t& value);
std::string castToString(const uint64_t& value);
std::string castToString(const float& value);
std::string castToString(const std::string& value);
std::string castToString(const double& value);

template<typename T>
std::string castToStringEnum(const T& value, std::true_type);

template<typename T>
std::string castToStringEnum(const T& value, std::false_type);

template<typename T>
std::string castToStringEnum(const T& value, std::true_type)
{
	auto str = magic_enum::enum_name(value);
	return std::string(str);
}

template<typename T>
std::string castToStringEnum(const T& value, std::false_type)
{
	// Should never be called
	return std::string();
}

template <typename T,
	bool isEnum = std::is_enum<T>::value>
T fromString(const std::string& value);

template <>
bool fromString(const std::string& valueStr);

template <>
uint8_t fromString(const std::string& valueStr);

template <>
uint16_t fromString(const std::string& valueStr);

template <>
uint32_t fromString(const std::string& valueStr);

template <>
uint64_t fromString(const std::string& valueStr);

template <>
int8_t fromString(const std::string& valueStr);

template <>
int16_t fromString(const std::string& valueStr);

template <>
int32_t fromString(const std::string& valueStr);

template <>
int64_t fromString(const std::string& valueStr);

template <>
float fromString(const std::string& valueStr);

template<>
double fromString(const std::string& valueStr);

template <>
std::string fromString(const std::string& valueStr);

template<typename T>
T fromStringEnum(const std::string& valueStr, std::true_type);
template<typename T>
T fromStringEnum(const std::string& valueStr, std::false_type);

template<typename T>
T fromStringEnum(const std::string& valueStr, std::true_type)
{
	return T();// magic_enum::enum_cast<T>(valueStr);
}

template<typename T>
T fromStringEnum(const std::string& valueStr, std::false_type)
{
	// Should never be called
	return T();
}
// return empty string if no conversion possible
template <typename T >
std::string castToString(const T&  value )
{
	if (std::is_enum<T>::value)
	{
		return castToStringEnum <T>(value, std::integral_constant<bool, std::is_enum<T>::value>{});
		//return castToString <T, std::integral_constant<bool, std::is_enum<T>::value>{}>(value, std::integral_constant<bool, std::is_enum<T>::value>{});
	}
	else
	{
		return std::string();
	}
}

template <typename T,
	bool isEnum = std::is_enum<T>::value >
T fromString(const std::string& value )
{
	if (std::is_enum<T>::value)
	{
		return fromStringEnum < T >(value, std::integral_constant<bool, isEnum>{});
		//return fromString < T, std::integral_constant<bool, std::is_enum<T>::value>{}>(value, std::integral_constant<bool, std::is_enum<T>::value>{});

	}	
	else
	{
		return T();
	}
}