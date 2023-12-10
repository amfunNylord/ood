#include <cmath>
#include <iostream>

#include "drawer.h"

constexpr int STAR_COUNT = 20;

int main()
{
	{
		Image img = LoadImage(
			" CCCC             \n"
			"CC  CC   ##    ## \n"
			"CC      ####  ####\n"
			"CC  CC   ##    ## \n"
			" CCCC             \n");
		Print(img, std::cout);
	}

	{
		Image img{ { 30, 20 }, '.' };

		DrawLine(img, { 3, 2 }, { 26, 5 }, '#');
		DrawLine(img, { 26, 5 }, { 21, 18 }, '#');
		DrawLine(img, { 21, 18 }, { 3, 2 }, '#');

		Print(img, std::cout);
	}

	{
		Image img = LoadImage(
			"....................\n"
			"....................\n"
			"........##..........\n"
			".......#..#.........\n"
			"......#....#........\n"
			"....##########......\n"
			"....#........#......\n"
			"....#...##...#......\n"
			"....#........#......\n"
			"....##########......\n");
		Print(img, std::cout);
	}

	{
		Image img{ { 31, 31 }, '.' };

		DrawCircle(img, { 15, 15 }, 10, '#');
		
		Print(img, std::cout);
	}

	{
		Image img{ { 31, 31 }, '.' };

		FillCircle(img, { 15, 15 }, 10, '#');

		Print(img, std::cout);
	}
}
