#pragma once
#include "GCode/GCodeDefs.h"
#include <string>
#include <vector>
#include <istream>
class GCodeParser
{

public:
    GCodeParser(void);

    ~GCodeParser(void);

    // Parsing instrution list from file (.gcode or similar)
    bool readInstructions(std::string& filePath);

    // Incrementally adding instructions to parser
    friend std::istream & operator >> (std::istream &is, GCodeParser& parser);


private:
    typedef std::pair<uint32_t, std::string> Instruction_t;
    typedef std::vector<Instruction_t> InstructionList_t;
    
    InstructionList_t m_instructions;

    bool processInstruction(std::string& instr);
    Code_t extractCode(const std::string& instr);

    bool removeOperationStr(std::string& instr, uint32_t numRem);

    CodeProcessorMap_t m_codeProcessors;

    void populateProcessorMap();
};