#pragma once
#include "Message.h"

Derive_Message_CRTP(FileRequest)
{
public:
	FileRequest();
	~FileRequest(void);

	inline const std::string& getFileName(void) const
	{
		return m_filename;
	}
	inline void setFileName(const std::string & name)
	{
		m_filename = name;
	}
	
	inline const uint32_t& getSizeRequested(void) const
	{
		return m_sizeRequested;
	}
	inline void setSizeRequested(const uint32_t & size)
	{
		m_sizeRequested = size;
	}


	inline const bool& getCloseIndication(void) const
	{
		return m_close;
	}

	inline void setCloseIndication(const bool& close)
	{
		m_close = close;
	
	}

private:
	std::string m_filename;
	uint32_t m_sizeRequested;
	bool m_close;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<FileRequest>()
	{
		return members(
			member("m_filename", &FileRequest::getFileName, &FileRequest::setFileName),
			member("m_sizeRequested", &FileRequest::getSizeRequested, &FileRequest::setSizeRequested),
			member("m_close", &FileRequest::getCloseIndication, &FileRequest::setCloseIndication)
		);
	}

}