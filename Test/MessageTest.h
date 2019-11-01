#pragma once
#include "Message.h"
#include "Marshaller.h"


class MessageTest
{
public:
	Derive_Message_CRTP(ExampleMsg)
	{
	public:
		ExampleMsg() :
			MessageCRTP(Format_t::XML),
			m_cat(),
			m_dog()
		{
			setName("ExampleMsg");
			Marshaller* marshall = Marshaller::getMarshaller();

			marshall->registerMessageName<ExampleMsg>(*this, (NewMessage_t*)& getNewMessage<ExampleMsg>);


		}
		class ExampleComponent
		{

		public:
			ExampleComponent() {}

			uint8_t cat;
			uint16_t fish;

		};
		ExampleComponent m_comp;
		std::string m_dog;
		int m_cat;
	};
	bool runTest();



};

class ExampleMsg2
{
public:
	ExampleMsg2()
	{



	}


	std::vector<std::string> favouriteMovies;
	double salary;
	std::string name;
	uint8_t age;
	class Stepper
	{
	public:
		uint8_t dir = 0;
		std::string name = "xaxis";

		class speed
		{
		public:
			uint8_t m_speed = 54;
		};
		speed m_s;
	};
	Stepper stepper;
	std::unordered_map<uint8_t, double> f =
	{
		{4, 4.0},
	{14, 15.4},
	{3, 0}

	};

};
#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<MessageTest::ExampleMsg>()
	{
		return members(
			member("MESSAGE", &MessageTest::ExampleMsg::getMsg, &MessageTest::ExampleMsg::setMsg),
			member("m_dog", &MessageTest::ExampleMsg::m_dog), // access through getter/setter only!
			member("m_cat", &MessageTest::ExampleMsg::m_cat), // same, but ref getter/setter
			member("m_comp", &MessageTest::ExampleMsg::m_comp)

		);
	}

	template <>
	inline auto registerMembers<MessageTest::ExampleMsg::ExampleComponent>()
	{
		return members(
			member("cat", &MessageTest::ExampleMsg::ExampleComponent::cat), // access through getter/setter only!
			member("fish", &MessageTest::ExampleMsg::ExampleComponent::fish) // same, but ref getter/setter

		);
	}

	template <>
	inline auto registerMembers<ExampleMsg2>()
	{
		return members(
			member("age", &ExampleMsg2::age), // access through getter/setter only!
			member("name", &ExampleMsg2::name), // same, but ref getter/setter
			member("salary", &ExampleMsg2::salary),
			member("favouriteMovies", &ExampleMsg2::favouriteMovies),
			member("stepper", &ExampleMsg2::stepper),
			member("map", &ExampleMsg2::f)
			

		);
	}
	template <>
	inline auto registerMembers<ExampleMsg2::Stepper>()
	{
		return members(
			member("dir", &ExampleMsg2::Stepper::dir), // access through getter/setter only!
			member("name", &ExampleMsg2::Stepper::name), // same, but ref getter/setter
			member("speed", &ExampleMsg2::Stepper::m_s)



		);
	}
	template <>
	inline auto registerMembers<ExampleMsg2::Stepper::speed>()
	{
		return members(
			member("m_speed", &ExampleMsg2::Stepper::speed::m_speed)



		);
	}
} // end of namespace meta


