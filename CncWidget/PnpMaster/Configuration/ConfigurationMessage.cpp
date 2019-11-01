#include "ConfigurationMessage.h"
#include "Marshaller.h"

ConfigurationMessage::ConfigurationMessage() 
{

	setName("ConfigurationMessage");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<ConfigurationMessage>(*this, (NewMessage_t*)& getNewMessage<ConfigurationMessage>);


}