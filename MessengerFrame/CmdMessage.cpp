#include "CmdMessage.h"

CmdMessage::CmdMessage() :
m_cmd("")
{
}

CmdMessage::CmdMessage(const std::string& cmd) :
	m_cmd(cmd)
{
}
