#include "MessageTest.h"
#include "NameServer.h"

#include <MetaLib/json.hpp>
#include "MetaLib/rapidxml_print.hpp"
bool MessageTest::runTest()
{


	Marshaller* marshall = Marshaller::getMarshaller();

	ExampleMsg msg;
	msg.m_cat = 4;
	msg.m_dog = "hello world";
	msg.m_comp.fish = 0xffff;
	msg.m_comp.cat = 0xff;

	

	NameServer* ns = NameServer::getNameServer();
	Location* nsLoc = ns->getLocation("NameServer");

	std::vector<uint8_t>* ret = marshall->toByteStream<ExampleMsg>(msg);


#if 0
	

	ExampleMsg2 person;
	person.age = 23;
	person.name = "Andy";
	person.favouriteMovies = { "Dog", "Cat", "Mat" };
	person.salary = 0; // :(
	json root = person;
	std::cout << std::setw(4) << root << std::endl;

	rapidxml::xml_document<>* doc = meta::generateXml<ExampleMsg2>(person);

	std::vector<uint8_t> bytes;
	meta::serialize(person, bytes);

	std::stringstream stream;
	std::ostream_iterator<char> iter(stream);

	rapidxml::print(iter, *doc, rapidxml::print_no_indenting);

	printf("%s\n", stream.str().c_str());
	printf("len = %d\n", stream.str().size());

	ExampleMsg2 f;
	meta::deserialize_doc(f, doc);


	ExampleMsg2 msg2;
	meta::deserializeCompact(bytes, msg2);
#endif



	ExampleMsg* msgPtr = (ExampleMsg*)(marshall->extractMessage(*ret, Format_t::XML));
	return false;
}
