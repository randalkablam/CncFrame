#pragma once
#include "Message.h"
Derive_Message_CRTP(SetFileMapping)
{
public:
	SetFileMapping();
	~SetFileMapping(void);

	inline const std::string& getFileName(void) const
	{
		return m_filename;
	}
	inline void setFileName(const std::string& name)
	{
		m_filename = name;
	}

	inline const std::string& getAlias(void) const
	{
		return m_alias;
	}
	inline void setAlias(const std::string& alias)
	{
		m_alias = alias;
	}



private:
	std::string m_filename;
	std::string m_alias;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<SetFileMapping>()
	{
		return members(
			member("m_filename", &SetFileMapping::getFileName, &SetFileMapping::setFileName),
			member("m_alias", &SetFileMapping::getAlias, &SetFileMapping::setAlias)
		);
	}

}