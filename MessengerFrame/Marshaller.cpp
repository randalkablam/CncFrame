#include "Marshaller.h"

Marshaller* Marshaller::m_marshallerPtr = nullptr;

Marshaller* Marshaller::getMarshaller()
{
	if (nullptr == m_marshallerPtr)
	{
		m_marshallerPtr = new Marshaller();
	}

	return m_marshallerPtr;
}

Marshaller::Marshaller()
{
}


Marshaller::~Marshaller()
{
}
