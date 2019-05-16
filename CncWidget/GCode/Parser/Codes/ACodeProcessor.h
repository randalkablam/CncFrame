#pragma once
#include <string>
class ACodeProcessor
{
    ACodeProcessor(void);
    ~ACodeProcessor(void);
    static uint32_t processOperation(const std::string& op);


};