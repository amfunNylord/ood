#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../MultiGumballMachineState/CMultiGumballMachine.h"

std::string MakeState(unsigned ballsCount, unsigned quartersCount, const std::string state)
{
	return "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\nInventory: " + std::to_string(ballsCount) + 
		   " gumball" + (ballsCount != 1 ? "s" : "") + "\nQuarters count: " + std::to_string(quartersCount) + "\nMachine is " + state;
}

SCENARIO("CHasQuarterState test all functions")
{
	GIVEN("Gumball machine with 3 gum")
	{
		CMultiGumballMachine gumballMachine(3);
		gumballMachine.InsertQuarter();
		REQUIRE(gumballMachine.ToString() == MakeState(3, 1, "waiting for turn of crank"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("inserted 2 quarters")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, 2, "waiting for turn of crank"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("quarter will be ejected")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, 0, "waiting for quarter"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("gumball will be delivered")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(2, 0, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("CNoQuarterState test all functions")
{
	GIVEN("Gumball machine with 3 gum")
	{
		CMultiGumballMachine gumballMachine(3);
		REQUIRE(gumballMachine.ToString() == MakeState(3, 0, "waiting for quarter"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("quarter will be inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, 1, "waiting for turn of crank"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("quarter won't be ejected")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, 0, "waiting for quarter"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("gumball won't be delivered")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, 0, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("CSoldOutState test all functions")
{
	GIVEN("Empty gumball machine")
	{
		CMultiGumballMachine gumballMachine(0);
		REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("can't insert, because all gumballs sold out")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("can't eject, quarter not inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("can't turn crank, quarter not inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));
			}
		}
	}

	GIVEN("Gumball machine with 1 gum")
	{
		CMultiGumballMachine gumballMachine(1);
		REQUIRE(gumballMachine.ToString() == MakeState(1, 0, "waiting for quarter"));

		WHEN("by 1 gumball")
		{
			gumballMachine.InsertQuarter();
			gumballMachine.TurnCrank();

			THEN("gumball machine will be empty after delivering")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));
			}
		}
	}
}

SCENARIO("CSoldState test all functions")
{
	GIVEN("Gumball machine with 1 gum")
	{
		CMultiGumballMachine gumballMachine(-1);
		REQUIRE(gumballMachine.ToString() == MakeState(1, 0, "delivering a gumball"));

		WHEN("We try to insert quarter")
		{
			gumballMachine.InsertQuarter();
			THEN("can't insert because already inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(1, 0, "delivering a gumball"));
			}
		}

		WHEN("We try to eject quarter")
		{
			gumballMachine.EjectQuarter();
			THEN("can't eject quarter because turned the crank")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(1, 0, "delivering a gumball"));
			}
		}
	}
}

SCENARIO("CHasMaxQuarters test all functions")
{
	GIVEN("Gumball machine with 5")
	{
		CMultiGumballMachine gumballMachine(5);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		REQUIRE(gumballMachine.ToString() == MakeState(5, 5, "full of quarters"));
		WHEN("We try to insert quarter")
		{
			gumballMachine.InsertQuarter();
			THEN("can't insert quarter")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(5, 5, "full of quarters"));
			}
		}
		WHEN("We try to eject quarter")
		{
			gumballMachine.EjectQuarter();
			THEN("0 quarters in machine")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(5, 0, "waiting for quarter"));
			}
		}
		WHEN("We try to turn crank")
		{
			gumballMachine.TurnCrank();
			THEN("4 quarter and 4 gum in machine")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(4, 4, "waiting for turn of crank"));
			}
		}
		WHEN("machine doesn't have gum but has quarters, we want to eject quarters")
		{
			gumballMachine.TurnCrank();
			gumballMachine.InsertQuarter();
			gumballMachine.TurnCrank();
			gumballMachine.TurnCrank();
			gumballMachine.TurnCrank();
			gumballMachine.TurnCrank();
			gumballMachine.EjectQuarter();
			THEN("Quarters are ejected")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, 0, "sold out"));
			}
		}
	}
}