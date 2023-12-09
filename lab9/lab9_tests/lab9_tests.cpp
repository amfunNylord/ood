#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include <stdexcept>
#include "../lab9/tile.h"
#include "../lab9/image.h"

SCENARIO("Class Tile tests")
{
	WHEN("Just created tile without color")
	{
		Tile tile;
		THEN("Color is deafult")
		{
			for (int i = 0; i < Tile::SIZE; i++)
			{
				for (int j = 0; j < Tile::SIZE; j++)
				{
					REQUIRE(tile.GetPixel({ j, i }) == ' ');
				}
			}
		}
	}
	WHEN("Just created tile with color")
	{
		Tile tile('h');
		THEN("Color is that was given")
		{
			for (int i = 0; i < Tile::SIZE; i++)
			{
				for (int j = 0; j < Tile::SIZE; j++)
				{
					REQUIRE(tile.GetPixel({ j, i }) == 'h');
				}
			}
		}
	}
	GIVEN("Just created tile without color")
	{
		Tile tile;
		WHEN("We want change color of (5, 3) to \'l\'")
		{
			tile.SetPixel({ 4, 2 }, 'l');
			THEN("We changed color to \'l\' in (5, 3)")
			{
				REQUIRE(tile.GetPixel({ 4, 2 }) == 'l');
			}
		}
	}
	GIVEN("Tile with color - \'h\'")
	{
		Tile tile('h');
		WHEN("We want to get color which coordinates are out of tile")
		{
			THEN("We get space")
			{
				REQUIRE(tile.GetPixel({ 4, 10 }) == ' ');
			}
		}
	}
}

SCENARIO("Class Image tests")
{
	WHEN("We try to create image with negative width or height")
	{
		THEN("We get exception out_of_range")
		{
			REQUIRE_THROWS_AS(Image({ -100, 500 }, 'c'), std::out_of_range);
		}
	}

	WHEN("We create image 64x64, color \'h\'")
	{
		Image img({ 64, 64 }, 'h');
		THEN("It has 1 tile")
		{
			REQUIRE(img.GetSize().width == 64);
			REQUIRE(img.GetSize().height == 64);
			REQUIRE(Tile::GetInstanceCount() == 1);
		}
	}

	GIVEN("Image 64x64, color \'h\'")
	{
		Image img({ 64, 64 }, 'h');
		WHEN("We change color of 1 pixel")
		{
			img.SetPixel({ 2, 2 }, 'c');
			THEN("Image has 2 tile")
			{
				REQUIRE(Tile::GetInstanceCount() == 2);
			}
		}
	}

	GIVEN("Image 64x64, color \'h\', with 1 changed pixel")
	{
		Image img({ 64, 64 }, 'h');
		img.SetPixel({ 2, 2 }, 'c');
		WHEN("We change color of 1 pixel other tile")
		{
			img.SetPixel({ 10, 10 }, 'l');
			THEN("Image has 3 tiles")
			{
				REQUIRE(Tile::GetInstanceCount() == 3);
			}
		}
		WHEN("We change color of 1 pixel tile that has been already changed")
		{
			img.SetPixel({ 1, 1 }, 'l');
			THEN("Image has 2 tiles")
			{
				REQUIRE(Tile::GetInstanceCount() == 2);
			}
		}
		/*WHEN("We change color of 1 pixel other tile but the same pos and color as already changed")
		{
			img.SetPixel({ 10, 10 }, 'c');
			THEN("Image has 2 tiles")
			{
				REQUIRE(Tile::GetInstanceCount() == 2);
			}
		}*/
	}
}