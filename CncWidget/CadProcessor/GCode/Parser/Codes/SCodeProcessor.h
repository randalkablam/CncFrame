#pragma once
#include <string>
#include "CadProcessor/GCode/GCodeDefs.h"


// Parses Codes for setting spindle speeds
class SCodeProcessor : public ParserBase
{
public:
	SCodeProcessor(void);
	~SCodeProcessor(void);

	ErrorSeverity_t spindleSpeedExtraction(std::string& instr); // S Code


};