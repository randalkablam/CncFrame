#pragma once
#include <string>
#include "CadProcessor/GCode/GCodeDefs.h"
class FCodeProcessor : public ParserBase
{
public:
	FCodeProcessor(void);
	~FCodeProcessor(void);
	ErrorSeverity_t feedRateExtraction(std::string& instr); // F Code

};