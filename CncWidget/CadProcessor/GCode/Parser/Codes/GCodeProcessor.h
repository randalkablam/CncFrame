#pragma once
#include <string>
#include "CadProcessor/GCode/GCodeDefs.h"

class GCodeProcessor : public ParserBase
{
public:
    GCodeProcessor(void);
    ~GCodeProcessor(void);
    uint32_t processOperation(const std::string& op);
	ErrorSeverity_t feedRateModeExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t dwellExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t activePlaneExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t setUnitExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t cutterRadiusCompStateExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t cutterLengthCompStateExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t coordSysSelectExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t pathControlExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t distanceModeExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t retractModeExtraction(std::string& instr); // G Code Groups 
	ErrorSeverity_t coordPresetExtraction(std::string& instr); // G Code Groups
	ErrorSeverity_t motionExtraction(std::string& instr); // G Code Groups
private:
	
};