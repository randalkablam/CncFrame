
#include "GCodeParser.h"


    GCodeParser::GCodeParser(void)
    {



    }

    GCodeParser::~GCodeParser(void)
    {


    }

    bool GCodeParser::processInstruction(std::string& instr)
    {

        bool ret = false;
        while(!instr.empty())
        {
            Code_t code = extractCode(instr);
            if(INVALID_CODE != code)
            {
                CodeProcessorMap_t::iterator it = m_codeProcessors.find(code);
                
                if(m_codeProcessors.end() != it)
                {
                    CodeProc_t processor = it->second;
                    if(nullptr != processor.procPtr)
                    {
                        uint32_t removedInstr = processor.procPtr(instr);
                        removeOperationStr(instr, removedInstr);
                    }

                }
                else
                {
                    // No processor found for given (valid) code.
                    // Log occurrence and remove bad instruction. TODO
                    removeOperationStr(instr, 1);
                }
                
            }
            else
            {
                // Bad operation code given
                // Remove bad op from instruction
                removeOperationStr(instr, 1);
            }
            
        }
        // Return true for successful processing
        return ret;
    }


    Code_t GCodeParser::extractCode(const std::string& instr)
    {
        // Checks if first letter in instruction
        // is valid and returns Code_t enum for that letter
        // If it is not valid then it returns INVALID_CODE
        Code_t ret = INVALID_CODE;
        if(instr.empty())
        {

        }
        else
        {
            
            if(instr.at(0) >= A && instr.at(0) <= Z)
            {
                ret = static_cast<Code_t>(instr.at(0));

            }
        }
        
        return ret;
    }

    bool GCodeParser::removeOperationStr(std::string& instr, uint32_t numRem)
    {
        bool ret = false;


        return ret;
    }


    void GCodeParser::populateProcessorMap()
    {


    }
