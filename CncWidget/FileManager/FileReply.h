#pragma once
#include "Message.h"
Derive_Message_CRTP(FileReply)
{
public:
	FileReply();
	~FileReply(void);

	inline const std::string& getFileName(void) const
	{
		return m_filename;
	}
	inline void setFileName(const std::string& name)
	{
		m_filename = name;
	}
	inline const std::vector<uint8_t>& getRawData(void) const
	{
		return m_rawData;
	}
	inline void setRawData(const std::vector<uint8_t>& name)
	{
		m_rawData = name;
	}
	inline const uint32_t& getSizeRequested(void) const
	{
		return m_sizeRequested;
	}
	inline void setSizeRequested(const uint32_t& size)
	{
		m_sizeRequested = size;
	}



private:
	std::string m_filename;
	std::vector<uint8_t> m_rawData;
	uint32_t m_sizeRequested;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<FileReply>()
	{
		return members(
			member("m_filename", &FileReply::getFileName, &FileReply::setFileName),
			member("m_rawData", &FileReply::getRawData, &FileReply::setRawData),
			member("m_sizeRequested", &FileReply::getSizeRequested, &FileReply::setSizeRequested)
		);
	}

}