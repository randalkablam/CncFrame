#pragma once
#include <map>
#include <string>
#include <vector>
// This file will contain definitions used
// in GCode Parsing

typedef enum
{
	NO_ERR = 0, // No action req
	MINOR_ERR = 1, // Log only
	MODERATE_ERR = 2, // Correctable error
	MAJOR_ERR = 4, // Gracefully stop all processing, manual intervention req
	EMERGENCY_ERR = 8 // Kill Power to machine components
}  ErrorSeverity_t;



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




typedef std::vector<Code_t> Argument_t;

typedef struct
{
	Argument_t reqArg;
	Argument_t optionalArg;
} ArgumentGroup_t;

typedef std::vector<ArgumentGroup_t> ArgumentGroupList_t;

const Argument_t NULL_ARG = {};

typedef struct
{
	Code_t code;
	double spec;
	ArgumentGroupList_t argumentSpec;
} Command_t;

// Modal Groups
typedef std::vector<Command_t> CodeGroup_t;


// Argument Variations

const ArgumentGroupList_t NULL_ARG_LIST =
{
	{NULL_ARG, NULL_ARG}
};


// One Axis Required
const ArgumentGroupList_t ONE_AXIS_REQ_ARG =
{
	{{X}, {Y, Z, A, B, C}},
	{{Y}, {X, Z, A, B, C}},
	{{Z}, {X, Y, A, B, C}},
	{{A}, {X, Y, Z, B, C}},
	{{B}, {X, Y, Z, A, C}},
	{{C}, {X, Y, Z, A, B}}
};

const ArgumentGroupList_t ONE_LINEAR_AXIS_REQ_ARG =
{
	{{X}, {Y, Z, A, B, C}},
	{{Y}, {X, Z, A, B, C}},
	{{Z}, {X, Y, A, B, C}}
};

const ArgumentGroupList_t FEED_RATE_ARC_ARG =
{
	// Radius Format Arc
	{{R, X}, {Y, Z, A, B, C}},
	{{R, Y}, {X, Z, A, B, C}},
	{{R, Z}, {X, Y, A, B, C}},
	{{R, A}, {X, Y, Z, B, C}},
	{{R, B}, {X, Y, Z, A, C}},
	{{R, C}, {X, Y, Z, A, B}},
	// Center Format Arc
	// XY Plane Selected
	{{I, X}, {Y, Z, A, B, C, J, K}},
	{{I, Y}, {X, Z, A, B, C, J, K}},
	{{J, X}, {Y, Z, A, B, C, I, K}},
	{{J, Y}, {X, Z, A, B, C, I, K}},
	// XZ Plane Selected
	{{I, X}, {Y, Z, A, B, C, J, K}},
	{{I, Z}, {X, Y, A, B, C, J, K}},
	{{K, X}, {Y, Z, A, B, C, I, J}},
	{{K, Z}, {X, Y, A, B, C, I, J}},
	// YZ Plane Selected
	{{J, Y}, {X, Z, A, B, C, I, K}},
	{{J, Z}, {X, Y, A, B, C, I, K}},
	{{K, Y}, {X, Z, A, B, C, I, J}},
	{{K, Z}, {X, Y, A, B, C, I, J}}
	
};



const ArgumentGroupList_t OPTIONAL_AXIS_ARG =
{
	{NULL_ARG, {X, Y, Z, A, B, C}}
};

const ArgumentGroupList_t PERIOD_ARG =
{
	{{P}, NULL_ARG}
};


const ArgumentGroupList_t COORDINATE_SYS_DATA_ARG =
{
	{{P, L}, NULL_ARG}
};


const ArgumentGroupList_t OPTIONAL_DIAMETER_ARG =
{
	{NULL_ARG, {D}}
};

const ArgumentGroupList_t TOOL_LENGTH_OFFSET_ARG =
{
	{{H}, NULL_ARG}
};

const ArgumentGroupList_t CANNED_CYCLE_1_ARG =
{
	{{R, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_2_ARG =
{
	{{R, P, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_3_ARG =
{
	{{R, Q, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_4_ARG =
{
	{{R, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_5_ARG =
{
	{{R, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_6_ARG =
{
	{{R, P, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_7_ARG =
{
	{{I, J, K, R, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_8_ARG =
{
	{{I, J, K, R, P, Z}, {X, Y, A, B, C, L}}
};
const ArgumentGroupList_t CANNED_CYCLE_9_ARG =
{
	{{R, P, Z}, {X, Y, A, B, C, L}}
};
// Non-Modal Groups (Misc)
// It is an error to put a G-code from group 1 and a G-code from group 0 on the same line if both of
// them use axis words
const CodeGroup_t GCodeGroup0 =
{
	{G, 4, PERIOD_ARG},
	{G, 10, COORDINATE_SYS_DATA_ARG}, // Axis word user
	{G, 28, OPTIONAL_AXIS_ARG}, // Axis word user: home position 1
	{G, 30, OPTIONAL_AXIS_ARG}, // Axis word user: home position 2
	{G, 53, ONE_AXIS_REQ_ARG},
	{G, 92, ONE_AXIS_REQ_ARG}, // Axis word user
	{G, 92.1, ONE_AXIS_REQ_ARG},
	{G, 92.2, ONE_AXIS_REQ_ARG},
	{G, 92.3, ONE_AXIS_REQ_ARG}
};

// Modal Groups
// Motion
const CodeGroup_t GCodeGroup1 =
{
	{G, 0, ONE_AXIS_REQ_ARG}, // Rapid Linear Motion
	{G, 1, ONE_AXIS_REQ_ARG}, // Linear Motion Feedrate
	{G, 2, FEED_RATE_ARC_ARG}, // Clockwise arc
	{G, 3, FEED_RATE_ARC_ARG}, // Counterclockwise arc
	{G, 38.2, ONE_LINEAR_AXIS_REQ_ARG},
	{G, 80, NULL_ARG_LIST},
	{G, 81, CANNED_CYCLE_1_ARG},// Canned Cycle
	{G, 82, CANNED_CYCLE_2_ARG},// Canned Cycle
	{G, 83, CANNED_CYCLE_3_ARG},// Canned Cycle
	{G, 84, CANNED_CYCLE_4_ARG},// Canned Cycle
	{G, 85, CANNED_CYCLE_5_ARG},// Canned Cycle
	{G, 86, CANNED_CYCLE_6_ARG},// Canned Cycle
	{G, 87, CANNED_CYCLE_7_ARG},// Canned Cycle
	{G, 88, CANNED_CYCLE_8_ARG},// Canned Cycle
	{G, 89, CANNED_CYCLE_9_ARG} // Canned Cycle
};

// Plane Selection
const CodeGroup_t GCodeGroup2 =
{
	{G, 17, NULL_ARG_LIST},
	{G, 18, NULL_ARG_LIST},
	{G, 19, NULL_ARG_LIST}
};

// Distance Mode
const CodeGroup_t GCodeGroup3 =
{
	{G, 90, NULL_ARG_LIST},
	{G, 91, NULL_ARG_LIST}
};

// Feed Rate Mode
const CodeGroup_t GCodeGroup5 =
{
	{G, 93, NULL_ARG_LIST}, // Inverse Time
	{G, 94, NULL_ARG_LIST} // Units per minute
};

//Units
const CodeGroup_t GCodeGroup6 =
{
	{G, 20, NULL_ARG_LIST},
	{G, 21, NULL_ARG_LIST}
};

// Cutter Radius Compensation
const CodeGroup_t GCodeGroup7 =
{
	{G, 40, OPTIONAL_DIAMETER_ARG},
	{G, 41, OPTIONAL_DIAMETER_ARG},
	{G, 42, OPTIONAL_DIAMETER_ARG}
};

// Tool Length Offset
const CodeGroup_t GCodeGroup8 =
{
	{G, 43, TOOL_LENGTH_OFFSET_ARG},
	{G, 49, TOOL_LENGTH_OFFSET_ARG}
};

// Return Mode in Canned Cycles
const CodeGroup_t GCodeGroup10 =
{
	{G, 98, NULL_ARG_LIST},
	{G, 99, NULL_ARG_LIST}
};

//Coordinate System Selection
const CodeGroup_t GCodeGroup12 =
{
	{G, 54, NULL_ARG_LIST},
	{G, 55, NULL_ARG_LIST},
	{G, 56, NULL_ARG_LIST},
	{G, 57, NULL_ARG_LIST},
	{G, 58, NULL_ARG_LIST},
	{G, 59, NULL_ARG_LIST},
	{G, 59.1, NULL_ARG_LIST},
	{G, 59.2, NULL_ARG_LIST},
	{G, 59.3, NULL_ARG_LIST}
};

// Path Control Mode
const CodeGroup_t GCodeGroup13 =
{
	{G, 61, NULL_ARG_LIST},
	{G, 61.1, NULL_ARG_LIST},
	{G, 64, NULL_ARG_LIST}
};


// M Codes

// Stopping
const CodeGroup_t MCodeGroup4 =
{
	{M, 0, NULL_ARG_LIST},
	{M, 1, NULL_ARG_LIST},
	{M, 2, NULL_ARG_LIST},
	{M, 30, NULL_ARG_LIST},
	{M, 60, NULL_ARG_LIST}
};

// Tool Change
const CodeGroup_t MCodeGroup6 =
{
	{M, 6, NULL_ARG_LIST}
};

// Spindle Turning
const CodeGroup_t MCodeGroup7 =
{
	{M, 3, NULL_ARG_LIST},
	{M, 4, NULL_ARG_LIST},
	{M, 5, NULL_ARG_LIST}
};

// Coolant (M7 and M8 may be active at same time)
const CodeGroup_t MCodeGroup8 =
{
	{M, 7, NULL_ARG_LIST},
	{M, 8, NULL_ARG_LIST},
	{M, 9, NULL_ARG_LIST}
};

// Enable/disable feed and speed override switches
const CodeGroup_t MCodeGroup9 =
{
	{M, 48, NULL_ARG_LIST},
	{M, 49, NULL_ARG_LIST}
};

typedef std::vector<CodeGroup_t> GroupCollection_t;
const GroupCollection_t AllModalGroups =
{
	MCodeGroup4,
	MCodeGroup6,
	MCodeGroup7,
	MCodeGroup8,
	MCodeGroup9,
	GCodeGroup1,
	GCodeGroup2,
	GCodeGroup3,
	GCodeGroup5,
	GCodeGroup6,
	GCodeGroup7,
	GCodeGroup8,
	GCodeGroup10,
	GCodeGroup12,
	GCodeGroup13
};

class ParserBase
{};