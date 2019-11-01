#include "XmlCast.h"


namespace meta
{

	/////////////////// SERIALIZATION

	template <typename Class,
		typename>
		rapidxml::xml_node<>* serialize(const Class& obj, rapidxml::xml_document<>* doc)
	{
		rapidxml::xml_node<>* value = doc->allocate_node(rapidxml::node_element, "message");
		meta::doForAllMembers<Class>(
			[&obj, &value, &doc](auto& member)
			{
				rapidxml::xml_node<>* mem_node = nullptr;
				if (member.canGetConstRef()) {
					mem_node = serialize(member.get(obj), doc);

				}
				else if (member.hasGetter()) {
					mem_node = serialize(member.getCopy(obj), doc); // passing copy as const ref, it's okay
				}
				if (nullptr != mem_node)
				{
					value->append_node(mem_node);
					std::string nameStr = member.getName();
					char* namexStr = doc->allocate_string(nameStr.c_str());

					mem_node->name(namexStr);
				}

			}
		);
		return value;
	}

	template <typename Class,
		typename, typename>
		rapidxml::xml_node<>* serialize(const Class& obj, rapidxml::xml_document<>* doc)
	{
		return serialize_basic(obj, doc);
	}

	template <typename Class>
	rapidxml::xml_node<>* serialize_basic(const Class& obj, rapidxml::xml_document<>* doc)
	{
		std::string val = castToString(obj);
		rapidxml::xml_node<>* child = doc->allocate_node(rapidxml::node_element, "node");
		char* valxStr = doc->allocate_string(val.c_str());
		child->value(valxStr);
		return child;
	}

	// specialization for std::vector
	template <typename T>
	rapidxml::xml_node<>* serialize_basic(const std::vector<T>& obj, rapidxml::xml_document<>* doc)
	{
		rapidxml::xml_node<>* vecRoot = doc->allocate_node(rapidxml::node_element, "vec");

		int i = 0;
		for (auto& elem : obj) {
			rapidxml::xml_node<>* vecElem = serialize_basic(elem, doc);

			vecRoot->append_node(vecElem);
			++i;
		}
		std::string nodeCntStr = castToString(i);
		char* nodeCntxStr = doc->allocate_string(nodeCntStr.c_str());

		vecRoot->append_attribute(doc->allocate_attribute("count", nodeCntxStr));
		return vecRoot;
	}

	// specialization for std::unordered_map
	template <typename K, typename V>
	rapidxml::xml_node<>* serialize_basic(const std::unordered_map<K, V>& obj, rapidxml::xml_document<>* doc)
	{



		rapidxml::xml_node<>* mapRoot = doc->allocate_node(rapidxml::node_element, "map");

		int i = 0;
		for (auto& elem : obj) {
			rapidxml::xml_node<>* mapElem = doc->allocate_node(rapidxml::node_element, "elem");
			rapidxml::xml_node<>* elemKey = serialize_basic<K>(elem.first, doc);
			rapidxml::xml_node<>* elemVal = serialize_basic<V>(elem.second, doc);
			char* nameKeyxStr = doc->allocate_string("key");
			char* nameValuexStr = doc->allocate_string("value");

			elemKey->name(nameKeyxStr);
			elemVal->name(nameValuexStr);

			mapElem->append_node(elemKey);
			mapElem->append_node(elemVal);


			mapRoot->append_node(mapElem);
			++i;
		}
		std::string nodeCntStr = castToString(i);
		char* nodeCntxStr = doc->allocate_string(nodeCntStr.c_str());

		mapRoot->append_attribute(doc->allocate_attribute("count", nodeCntxStr));
		return mapRoot;

	}
	template <typename Class,
		typename>
		rapidxml::xml_document<>* generateXml(const Class& obj)
	{
		rapidxml::xml_document<>* doc = new rapidxml::xml_document<>();
		rapidxml::xml_node<>* decl = doc->allocate_node(rapidxml::node_declaration);
		decl->append_attribute(doc->allocate_attribute("version", "1.0"));
		decl->append_attribute(doc->allocate_attribute("encoding", "UTF-8"));
		doc->append_node(decl);
		rapidxml::xml_node<>* msg_node = serialize(obj, doc);
		doc->append_node(msg_node);


		return doc;
	}
	/////////////////// DESERIALIZATION

	template <typename Class>
	Class deserialize(const rapidxml::xml_node<>* obj)
	{
		Class c;
		deserialize(c, obj);
		return c;
	}

	template <typename Class,
		typename>
		void deserialize(Class& obj, const rapidxml::xml_node<>* object)
	{
		//if (object.is_object()) {
		std::vector<rapidxml::xml_node<>*> nodeVec;
		meta::doForAllMembers<Class>(
			[&obj, &object, &nodeVec](auto& member)
			{
				//auto& objName = object[member.getName()];
				rapidxml::xml_node<>* node = object->first_node(member.getName());
				for (int32_t i = 0; i < nodeVec.size() && node != nullptr; i++)
				{
					if (nodeVec.at(i) == node)
					{
						node = node->next_sibling(member.getName());
					}
				}
				//if (!objName.is_null()) {
				if (nullptr != node)
				{
					using MemberT = meta::get_member_type<decltype(member)>;
					if (member.hasSetter()) {
						MemberT mem = deserialize<MemberT>(node);
						member.set(obj, mem);
					}
					else if (member.canGetRef()) {
						deserialize(member.getRef(obj), node);
					}
					else {
						throw std::runtime_error("Error: can't deserialize member because it's read only");
					}
					//}
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
		void deserialize(Class& obj, const rapidxml::xml_node<>* object)
	{
		obj = fromString<Class>(object->value());

	}

	// specialization for std::vector
	template <typename T>
	void deserialize(std::vector<T>& obj, const rapidxml::xml_node<>* object)
	{


		rapidxml::xml_node<>* data_node = object->first_node("elem");

		while (nullptr != data_node)
		{


			obj.push_back(deserialize<T>(data_node));

			data_node = data_node->next_sibling();
		}
	}

	// specialization for std::unodered_map
	template <typename K, typename V>
	void deserialize(std::unordered_map<K, V>& obj, const rapidxml::xml_node<>* object)
	{




		rapidxml::xml_node<>* data_node = object->first_node("elem");

		while (nullptr != data_node)
		{
			rapidxml::xml_node<>* key_node = data_node->first_node("key");
			rapidxml::xml_node<>* val_node = data_node->first_node("value");

			obj.emplace(deserialize<K>(key_node), deserialize<V>(val_node));

			data_node = data_node->next_sibling();
		}

	}
	template <typename Class,
		typename>
		void deserialize_doc(Class& obj, const rapidxml::xml_document<>* object)
	{
		rapidxml::xml_node<>* msg_node = object->first_node("message");
		obj = deserialize<Class>(msg_node);
	}
}
