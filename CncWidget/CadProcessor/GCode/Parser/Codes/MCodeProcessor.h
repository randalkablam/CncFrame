#pragma once
#include <string>
#include "CadProcessor/GCode/GCodeDefs.h"

class MCodeProcessor : public ParserBase
{
public:

	MCodeProcessor(void);

	~MCodeProcessor(void);


	ErrorSeverity_t changeToolExtraction(std::string& instr); // M Code Groups
	ErrorSeverity_t spindleStateExtraction(std::string& instr); // M Code Groups
	ErrorSeverity_t coolantStateExtraction(std::string& instr);  // M Code Groups
	ErrorSeverity_t overidesExtraction(std::string& instr); // M Code Groups

	ErrorSeverity_t stopCmdExtraction(std::string& instr); // M Code Group


};