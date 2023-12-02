#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab8/CGumballMachine.h"

std::string MakeState(unsigned count, const std::string state)
{
	 return "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\nInventory: " + 
			std::to_string(count) + " gumball" + (count != 1 ? "s" : "") + "\nMachine is " + state;
}


SCENARIO("CHasQuarterState test all functions")
{
	GIVEN("Gumball machine with 3 gum")
	{
		CGumballMachine gumballMachine(3);
		gumballMachine.InsertQuarter();
		REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for turn of crank"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("quarter already inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for turn of crank"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("quarter will be ejected")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for quarter"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("gumball will be delivered")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(2, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("CNoQuarterState test all functions")
{
	GIVEN("Gumball machine with 3 gum")
	{
		CGumballMachine gumballMachine(3);
		REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for quarter"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("quarter will be inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for turn of crank"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("quarter won't be ejected")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for quarter"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("gumball won't be delivered")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(3, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("CSoldOutState test all functions")
{
	GIVEN("Empty gumball machine")
	{
		CGumballMachine gumballMachine(0);
		REQUIRE(gumballMachine.ToString() == MakeState(0, "sold out"));

		WHEN("try to insert quarter")
		{
			gumballMachine.InsertQuarter();

			THEN("can't insert, because all gumballs sold out")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, "sold out"));
			}
		}

		WHEN("try to eject quarter")
		{
			gumballMachine.EjectQuarter();

			THEN("can't eject, quarter not inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, "sold out"));
			}
		}

		WHEN("try to turn crank")
		{
			gumballMachine.TurnCrank();

			THEN("can't turn crank, quarter not inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, "sold out"));
			}
		}
	}

	GIVEN("Gumball machine with 1 gumball")
	{
		CGumballMachine gumballMachine(1);
		REQUIRE(gumballMachine.ToString() == MakeState(1, "waiting for quarter"));

		WHEN("by 1 gumball")
		{
			gumballMachine.InsertQuarter();
			gumballMachine.TurnCrank();

			THEN("gumball machine will be empty after delivering")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(0, "sold out"));
			}
		}
	}
}

// gumball mahcine + soldstate

SCENARIO("CSoldState test all functions")
{
	GIVEN("Gumball machine with ")
	{
		CGumballMachine gumballMachine(-1);
		REQUIRE(gumballMachine.ToString() == MakeState(1, "delivering a gumball"));

		WHEN("We try to insert quarter")
		{
			gumballMachine.InsertQuarter();
			THEN("can't insert because already inserted")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(1, "delivering a gumball"));
			}
		}

		WHEN("We try to eject quarter")
		{
			gumballMachine.EjectQuarter();
			THEN("can't eject quarter because turned the crank")
			{
				REQUIRE(gumballMachine.ToString() == MakeState(1, "delivering a gumball"));
			}
		}
	}
}