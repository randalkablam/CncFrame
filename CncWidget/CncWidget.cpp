// CncWidget.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CadProcessor/GCode/Parser/GCodeParser.h"
#include <time.h>

int main()
{
    std::cout << "Hello World!\n"; 
	clock_t tStart = clock();

	for (int i = 0; i < 10; i++)
	{
		std::string testComment = "   (Msg hello) F1 #4=[SIN[6 * [4+1] * cos[#43**1]] * 3**[1 / cos[60]] + TAN[45]/[1]] i sA (Hello!) #[5 + 4 + 2 ** 3] (msg f)\n";
		std::string invalidComment = " ((f))";
		std::shared_ptr<GCodeParser> parser = GCodeParser::getGCodeParser();
		*parser << testComment;
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//*parser << invalidComment;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
