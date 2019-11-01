#pragma once
#include <string>
#include "CadProcessor/GCode/GCodeDefs.h"

class TCodeProcessor : public ParserBase
{
public:
	TCodeProcessor(void);
	~TCodeProcessor(void);


	ErrorSeverity_t toolSelectExtraction(std::string& instr); // T Code


};