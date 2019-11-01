#pragma once
#include "CadProcessor/GCode/GCodeDefs.h"
#include <string>
#include <vector>
#include <istream>

#include "Codes/FCodeProcessor.h"
#include "Codes/GCodeProcessor.h"
#include "Codes/MCodeProcessor.h"
#include "Codes/SCodeProcessor.h"
#include "Codes/TCodeProcessor.h"

#include <functional>

class GCodeParser : public ParserBase
{

public:
	static std::shared_ptr <GCodeParser> getGCodeParser();

    // Parsing instrution list from file (.gcode or similar)
    bool readInstructions(std::string& filePath);

    // Incrementally adding instructions to parser
    friend std::istream & operator >> (std::istream &is, GCodeParser& parser);
	friend void operator << (GCodeParser& parser, std::string str);

	double getParam(uint16_t index);

//
private:
	~GCodeParser(void);
	GCodeParser(void);

    typedef std::pair<uint32_t, std::string> Instruction_t;
    typedef std::vector<Instruction_t> InstructionList_t;
    
    InstructionList_t m_instructions;

    bool processInstruction(std::string& instr);
    Code_t extractCode(const std::string& instr);

    bool removeOperationStr(std::string& instr, uint32_t numRem);

	ErrorSeverity_t parameterInputReplacement(std::string& instr);


	ErrorSeverity_t commentExtraction(std::string& instr);
	void printMessage(const std::string& msg);

	ErrorSeverity_t formatChecker(std::string& instr);
	ErrorSeverity_t whitespaceRemover(std::string& instr);
	ErrorSeverity_t numberExpressionExtraction(std::string& instr);
	ErrorSeverity_t parameterOutputExtraction(std::string& instr);
	ErrorSeverity_t checkModality(std::string& instr);


	FCodeProcessor m_fProc;
	GCodeProcessor m_gProc;
	MCodeProcessor m_mProc;
	SCodeProcessor m_sProc;
	TCodeProcessor m_tProc;

	static std::shared_ptr<GCodeParser> ms_parser;

	//typedef ErrorSeverity_t(ParserBase::*ExtractionFunc_t)(std::string&);
	typedef std::function<ErrorSeverity_t(std::string&)> ExtractionFunc_t;
	typedef enum ProcName
	{
		BASE,
		FPROC,
		GPROC,
		MPROC,
		SPROC,
		TPROC
	} ProcName_t;


	typedef std::vector<ExtractionFunc_t> ExtractionFuncVec_t;
	ExtractionFuncVec_t m_orderOfExecVec;

	// Remediation Functions
	void remediateMinorError();
	void remediateModerateError();
	void remediateMajorError();
	void remediateEmergencyError();

	static const uint32_t MAX_PARAM = 5400;

	static std::vector<double> ms_parameter;

	void setParam(uint16_t index, double val);

	void getToolFile(void);
	void getParamFile(void);



};
