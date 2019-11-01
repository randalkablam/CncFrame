#pragma once
#include "Message.h"
Derive_Message_CRTP(GetFileMapping)
{
public:
	GetFileMapping();
	~GetFileMapping(void);

	inline const std::vector<std::string>& getFileNameVec(void) const
	{
		return m_nameVec;
	}
	inline void setFileNameVec(const std::vector<std::string>& nameVec)
	{
		m_nameVec = nameVec;
	}





private:
	std::vector<std::string> m_nameVec;

};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GetFileMapping>()
	{
		return members(
			member("m_nameVec", &GetFileMapping::getFileNameVec, &GetFileMapping::setFileNameVec)
		);
	}

}