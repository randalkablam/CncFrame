#pragma once
#include <map>
#include <string>
// This file will contain definitions used
// in GCode Parsing

enum Codes
{
    INVALID_CODE = ' ',
    A = 'A', 
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H',
    I = 'I',
    J = 'J',
    K = 'K',
    L = 'L',
    M = 'M',
    N = 'N',
    O = 'O',
    P = 'P',
    Q = 'Q',
    R = 'R',
    S = 'S',
    T = 'T',
    U = 'U',
    V = 'V',
    W = 'W',
    X = 'X',
    Y = 'Y',
    Z = 'Z'
} typedef Code_t;


typedef struct
{
    // Returns number of op's processed in instruction
    // string passed in.
	uint32_t(*procPtr)(const std::string&);
	void* param;
} CodeProc_t;

typedef std::map<Code_t, CodeProc_t> CodeProcessorMap_t;


// Preparatory Commands (Actual GCodes)
