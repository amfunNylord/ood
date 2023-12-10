#include <cmath>
#include <iostream>
#include <fstream>

#include "drawer.h"

constexpr int STAR_COUNT = 20;

int main()
{
	std::cout << "Write name of output file: ";
	std::string outputFileName;
	std::cin >> outputFileName;
	std::ofstream outfile(outputFileName);

	{
		Image img{ { 100, 100 }, 0xFFFFFF };

		DrawLine(img, { 3, 2 }, { 26, 5 }, 0x0000FF);
		DrawLine(img, { 26, 5 }, { 21, 18 }, 0x0000FF);
		DrawLine(img, { 21, 18 }, { 3, 2 }, 0x0000FF);

		DrawCircle(img, { 15, 15 }, 10, 0xFF0000);

		FillCircle(img, { 50, 50 }, 15, 0x00FF00);

		Print(img, outfile);
	}
}


