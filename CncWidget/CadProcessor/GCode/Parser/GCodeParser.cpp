#include <algorithm>
#include <regex>
#include <iostream>
#include "CadProcessor/GCode/Math/Expression.h"
#include "GCodeParser.h"

#include <functional>

std::shared_ptr<GCodeParser> GCodeParser::ms_parser = nullptr;
std::vector<double> GCodeParser::ms_parameter = std::vector<double>();
GCodeParser::GCodeParser(void) : 
	ParserBase()
{

	
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::formatChecker, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::commentExtraction, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::whitespaceRemover, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::parameterInputReplacement, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::numberExpressionExtraction, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::parameterOutputExtraction, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeParser::checkModality, this, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::feedRateModeExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&FCodeProcessor::feedRateExtraction, &m_fProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&SCodeProcessor::spindleSpeedExtraction, &m_sProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&TCodeProcessor::toolSelectExtraction, &m_tProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&MCodeProcessor::changeToolExtraction, &m_mProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&MCodeProcessor::spindleStateExtraction, &m_mProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&MCodeProcessor::coolantStateExtraction, &m_mProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&MCodeProcessor::overidesExtraction, &m_mProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::dwellExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::activePlaneExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::setUnitExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::cutterRadiusCompStateExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::cutterLengthCompStateExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::coordSysSelectExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::pathControlExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::distanceModeExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::retractModeExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::coordPresetExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&GCodeProcessor::motionExtraction, &m_gProc, std::placeholders::_1));
	m_orderOfExecVec.push_back(std::bind(&MCodeProcessor::stopCmdExtraction, &m_mProc, std::placeholders::_1));

	ms_parameter.resize(MAX_PARAM);
	for (uint32_t i = 0; i < MAX_PARAM; i++)
	{
		ms_parameter[i] = 0;
	}
}



GCodeParser::~GCodeParser(void)
{


}

std::shared_ptr<GCodeParser> GCodeParser::getGCodeParser()
{
	if (nullptr == ms_parser)
	{
		struct make_shared_enabler : public GCodeParser {};
		ms_parser = std::make_shared<make_shared_enabler>();
	}
	return ms_parser;
}

bool GCodeParser::readInstructions(std::string& filePath)
{
	return false;
}

bool GCodeParser::processInstruction(std::string& instr)
{

	bool ret = false;
	
	ExtractionFuncVec_t::iterator it(m_orderOfExecVec.begin());
	ExtractionFuncVec_t::iterator endIt(m_orderOfExecVec.end());

	// Loop through every extraction function
	while (it != endIt)
	{

		if (nullptr != (*it))
		{
			// Run ordered extraction function:

			ErrorSeverity_t procErr = (*it)(instr);



			// Handle any possible errors that occurred
			switch (procErr) 
			{
			case NO_ERR:
				break; // No action needed
			case MINOR_ERR:
				remediateMinorError();
				break;
			case MODERATE_ERR:
				remediateModerateError();
				break;
			case MAJOR_ERR:
				remediateMajorError();
				break;
			case EMERGENCY_ERR:
				remediateEmergencyError();
				break;
			default:
				// If invalid error code given then act as
				// if something inately horrible has happened
				// but not so horrible that we cut power abruptly.
				remediateMajorError();
			}



		}
		it++;
	}
	std::cout << instr << std::endl;
	// Return true for successful processing
	return ret;
}


Code_t GCodeParser::extractCode(const std::string& instr)
{
	// Checks if first letter in instruction
	// is valid and returns Code_t enum for that letter
	// If it is not valid then it returns INVALID_CODE
	Code_t ret = INVALID_CODE;
	if (instr.empty())
	{

	}
	else
	{

		if (instr.at(0) >= A && instr.at(0) <= Z)
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



ErrorSeverity_t GCodeParser::commentExtraction(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;
	size_t endStr = instr.size() - 1;

	std::string newInstr = instr;

	size_t commentStart = instr.find('(');
	std::string comment = "";
	while (std::string::npos != commentStart)
	{
		size_t nextEnd = instr.find(')', commentStart + 1);
		size_t nextStart = instr.find('(', commentStart + 1);

		if (nextEnd < nextStart)
		{
			comment = instr.substr(commentStart, nextEnd - commentStart + 1);
			// Process Comment
			std::regex exp("^\\(\\s*(msg)\\s", std::regex_constants::icase);
			std::smatch match;
			
			if (std::regex_search(comment, match, exp))
			{
				// This is a display message
				size_t msgStart = match.position() + match[0].length();
				size_t msgSize = comment.size() - match[0].length() - 1;
				std::string message = comment.substr(msgStart, msgSize);
				printMessage(message);
				
			}


			// Need to add escape charater before paren so that we can replace
			// entire comment through regex_replace
			comment = std::regex_replace(comment, std::regex("\\("), "\\(");
			comment = std::regex_replace(comment, std::regex("\\)"), "\\)");
			newInstr = std::regex_replace(newInstr, std::regex(comment), "");
		}
		else
		{
			// Error found in instruction
			// Do not print anything to console
			ret = MINOR_ERR;
			break;
		}
		
		commentStart = nextStart;

	}
	if (NO_ERR == ret)
	{
		instr = newInstr;
	}
	return ret;
}

void GCodeParser::printMessage(const std::string& msg)
{
	std::cout << msg << std::endl;
}

ErrorSeverity_t GCodeParser::formatChecker(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;
	// First group checks for one or more "\" characters with an optional number of space
	// characters inbetween
	// Second group checks for line number range from 0 to 99999 with a max of 5 chacters and min of 1 character
	// and the option for spaces inbetween (unfortunately this is the standard as I interpret it)
	// Third group is a non-digit/non end of line character (or arbitrarily many of them)
	// Fourth group is an arbirary number of characters
	// Fifth group is a newline, carriage return or both.
	std::regex exp("^([\\/]?)\\s*(N\\s*(([\\d]\\s*){1,5}))?([^N\\d\\n\\r]+)(.*)(\\n?\\r?)", std::regex_constants::icase);

	std::smatch match;

	if (!std::regex_match(instr, match, exp))
	{
		ret = MINOR_ERR;
	}

	
	return ret;
}

ErrorSeverity_t GCodeParser::whitespaceRemover(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;
	instr = std::regex_replace(instr, std::regex("(\\s)*"), "");
	std::cout << instr << std::endl;
	return ret;
}



ErrorSeverity_t GCodeParser::numberExpressionExtraction(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;

	Expression exp;
	exp.parseExpression(instr);
	return ret;
}

ErrorSeverity_t GCodeParser::parameterInputReplacement(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;

	std::regex exp("(\\[.*(\\#(\\d+)).*\\])", std::regex_constants::icase);
	std::smatch match;

	while (std::regex_search(instr, match, exp))
	{

		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };

		std::string numStr = match.str(3);
		double num = getParam(static_cast<uint16_t>(atoi(numStr.c_str())));

		std::string sanitized = std::regex_replace(match.str(2), specialChars, R"(\$&)");


		instr = std::regex_replace(instr, std::regex(sanitized), std::to_string(num));
	}

	return ret;

}

ErrorSeverity_t GCodeParser::parameterOutputExtraction(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;
	std::string numberExpStr = "([+-]?(\\d+\\.\\d+|\\d+|\\.\\d+|\\d+\\.))";

	std::regex exp("(\\#(\\d+)=(" + numberExpStr + "))", std::regex_constants::icase);
	std::smatch match;

	while (std::regex_search(instr, match, exp))
	{

		// matches any characters that need to be escaped in RegEx
		std::regex specialChars{ R"([-[\]{}()*+?.,\^$|#\s])" };

		std::string numStr = match.str(2);
		setParam(static_cast<uint16_t>(atoi(numStr.c_str())), atof(match.str(3).c_str()));

		std::string sanitized = std::regex_replace(match.str(0), specialChars, R"(\$&)");


		instr = std::regex_replace(instr, std::regex(sanitized), "");
	}

	return ret;
}

ErrorSeverity_t GCodeParser::checkModality(std::string& instr)
{
	ErrorSeverity_t ret = NO_ERR;

	//GroupCollection_t::iterator *it(AllModalGroups.cbegin());
	
	return ret;
}

void GCodeParser::remediateMinorError()
{
	std::cout << "Minor Error Detected!" << std::endl;
}

void GCodeParser::remediateModerateError()
{
}

void GCodeParser::remediateMajorError()
{
}

void GCodeParser::remediateEmergencyError()
{
}

double GCodeParser::getParam(uint16_t index)
{
	double ret = 0.0;
	if (index <= MAX_PARAM)
	{
		ret = ms_parameter.at(index - 1);
	}
	return ret;
}

void GCodeParser::setParam(uint16_t index, double val)
{
	if (index <= MAX_PARAM)
	{
		ms_parameter.at(index - 1) = val;
	}

}

void GCodeParser::getToolFile(void)
{
}

void GCodeParser::getParamFile(void)
{
}

std::istream& operator>>(std::istream& is, GCodeParser& parser)
{
	// TODO: insert return statement here
	std::string s(std::istreambuf_iterator<char>(is), {});
	parser.processInstruction(s);
	return is;
}

void operator<<(GCodeParser& parser, std::string str)
{
	parser.processInstruction(str);
}
