#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Meta.h"
#include "StringCast.h"



namespace meta
{

	/////////////////// SERIALIZATION

	template <typename Class,
		typename = std::enable_if_t <meta::isRegistered<Class>()>>
		void serialize(const Class & obj, std::vector<uint8_t> &ret);

	template <typename Class,
		typename = std::enable_if_t <!meta::isRegistered<Class>()>,
		typename = void>
		void serialize(const Class & obj, std::vector<uint8_t> &ret);

	template <typename Class>
	void serialize_basic(const Class& obj, std::vector<uint8_t>& ret);

	// specialization for std::vector
	template <typename T>
	void serialize_basic(const std::vector<T>& obj, std::vector<uint8_t>& ret);

	// specialization for std::unodered_map
	template <typename K, typename V>
	void serialize_basic(const std::unordered_map<K, V>& obj, std::vector<uint8_t>& ret);



	/////////////////// DESERIALIZATION
	//
	//template<typename Class>


	template <typename Class,
		typename = std::enable_if_t<meta::isRegistered<Class>()>>
		void deserialize(Class & obj, const std::vector<uint8_t> & byteArray, uint16_t &index);

	template <typename Class,
		typename = std::enable_if_t<!meta::isRegistered<Class>()>,
		typename = void>
		void deserialize(Class & obj, const std::vector<uint8_t> & byteArray, uint16_t &index);

	// specialization for std::vector
	template <typename T>
	void deserialize(std::vector<T>& obj, const std::vector<uint8_t> & byteArray, uint16_t &index);

	// specialization for std::unodered_map
	template <typename K, typename V>
	void deserialize(std::unordered_map<K, V>& obj, const std::vector<uint8_t> & byteArray, uint16_t &index);

	template<typename T>
	void deserializeCompact(std::vector<uint8_t> byteArray, T& obj)
	{
		uint16_t index = 0;
		deserialize(obj, byteArray, index);
	}
}


namespace meta
{

	/////////////////// SERIALIZATION

	template<typename T>
	void exportToByteStream(std::vector<uint8_t>& byteStream, const T& val)
	{
		uint32_t index = byteStream.size();
		byteStream.resize(byteStream.size() + sizeof(T));
		memcpy(&byteStream[index], &val, sizeof(T));


	}
	template<>
	void exportToByteStream<std::string>(std::vector<uint8_t>& byteStream, const std::string& val)
	{
		if (val.length() > 0)
		{
			uint32_t index = byteStream.size();
			byteStream.resize(byteStream.size() + val.length());
			std::copy(val.c_str(), val.c_str() + val.length(), &byteStream[index]);
		}
		byteStream.push_back(0);
	}

	template <typename Class,
		typename>
		void serialize(const Class& obj, std::vector<uint8_t>& ret)
	{

		meta::doForAllMembers<Class>(
			[&obj, &ret](auto& member)
			{

				if (member.canGetConstRef()) {
					serialize(member.get(obj), ret);

				}
				else if (member.hasGetter()) {
					serialize(member.getCopy(obj), ret); // passing copy as const ref, it's okay
				}


			}
		);
	}

	template <typename Class,
		typename, typename>
		void serialize(const Class& obj, std::vector<uint8_t>& ret)
	{
		return serialize_basic(obj, ret);
	}

	template <typename Class>
	void serialize_basic(const Class& obj, std::vector<uint8_t>& ret)
	{
		exportToByteStream<Class>(ret, obj);
	}

	// specialization for std::vector
	template <typename T>
	void serialize_basic(const std::vector<T>& obj, std::vector<uint8_t>& ret)
	{
		exportToByteStream<uint16_t>(ret, obj.size());
		int i = 0;
		for (auto& elem : obj) {
			serialize_basic<T>(elem, ret);

			++i;
		}

	}

	// specialization for std::unordered_map
	template <typename K, typename V>
	void serialize_basic(const std::unordered_map<K, V>& obj, std::vector<uint8_t>& ret)
	{


		exportToByteStream<uint16_t>(ret, obj.size());
		int i = 0;
		for (auto& elem : obj) {

			serialize<V>(elem.second, ret);

			serialize<K>(elem.first, ret);

			++i;
		}

	}

	/////////////////// DESERIALIZATION

	template<typename T>
	void extractFromByteStream(const std::vector<uint8_t>& byteStream, uint16_t& index, T& val)
	{
		std::cout << (int)sizeof(T) << std::endl;
		if (sizeof(T) <= (byteStream.size() - index))
		{
			memcpy(&val, &byteStream[index], sizeof(T));
			index += sizeof(T);
		}

	}
	template<>
	void extractFromByteStream<std::string>(const std::vector<uint8_t>& byteStream, uint16_t& index, std::string& val)
	{
		val = "";
		for (; index < byteStream.size(); index++)
		{
			if (byteStream[index] == 0)
			{
				index++;
				break;
			}

			val += char(byteStream[index]);

		}
	}


	template <typename Class>
	Class deserialize(const std::vector<uint8_t>& byteArray, uint16_t& index)
	{
		Class c;
		deserialize(c, byteArray, index);
		return c;
	}

	template <typename Class,
		typename>
		void deserialize(Class& obj, const std::vector<uint8_t>& byteArray, uint16_t& index)
	{
		//if (object.is_object()) {

		meta::doForAllMembers<Class>(
			[&obj, &byteArray, &index](auto& member)
			{
				//auto& objName = object[member.getName()];



				using MemberT = meta::get_member_type<decltype(member)>;
				if (member.hasSetter()) {




					MemberT mem = deserialize<MemberT>(byteArray, index);
					member.set(obj, mem);
				}
				else if (member.canGetRef()) {
					deserialize(member.getRef(obj), byteArray, index);
				}
				else {
					throw std::runtime_error("Error: can't deserialize member because it's read only");
				}


			}
		);
		//}
		//else {
		//	throw std::runtime_error("Error: can't deserialize from Json::json to Class.");
		//}
	}

	template <typename Class,
		typename, typename>
		void deserialize(Class& obj, const std::vector<uint8_t>& byteArray, uint16_t& index)
	{

		extractFromByteStream<Class>(byteArray, index, obj);
	}

	// specialization for std::vector
	template <typename T>
	void deserialize(std::vector<T>& obj, const std::vector<uint8_t>& byteArray, uint16_t& index)
	{
		uint16_t mapSize = 0;
		extractFromByteStream<uint16_t>(byteArray, index, mapSize);
		uint16_t mapIndex = 0;
		while (mapIndex < mapSize)
		{

			// First argument should execute before second
			obj.push_back(deserialize<T>(byteArray, index));
			mapIndex++;
		}

	}

	// specialization for std::unodered_map
	template <typename K, typename V>
	void deserialize(std::unordered_map<K, V>& obj, const std::vector<uint8_t>& byteArray, uint16_t& index)
	{


		uint16_t mapSize = 0;
		extractFromByteStream<uint16_t>(byteArray, index, mapSize);
		uint16_t mapIndex = 0;
		while (mapIndex < mapSize)
		{

			// First argument should execute before second
			obj.emplace(deserialize<K>(byteArray, index), deserialize<V>(byteArray, index));

			mapIndex++;
		}

	}

}