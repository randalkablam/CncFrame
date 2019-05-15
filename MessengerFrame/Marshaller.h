#pragma once
class Marshaller
{
public:
	static Marshaller* getMarshaller();
private:
	static Marshaller* m_marshallerPtr;
	Marshaller();
	~Marshaller();


};

