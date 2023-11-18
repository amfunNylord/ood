#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab6_colored/AdapterModernGraphicsObjectPro.h"
#include "../lab6_colored/shape_drawing_lib.h"
#include "../lab6_colored/AdapterModernGraphicsClassPro.h"

SCENARIO("Object adapter tests")
{
	std::ostringstream output;
	modern_graphics_lib_pro::CModernGraphicsRenderer renderer(output);
	WHEN("We want to draw line from the default start point to point with coordinates (100, 100) with default color")
	{
		CAdapterModernGraphicsObjectPro adapter(renderer);
		renderer.BeginDraw();
		adapter.LineTo(100, 100);
		renderer.EndDraw();
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"0\" fromY=\"0\" toX=\"100\" toY=\"100\"/>\n"
									"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw line from the custom start point (20, 20) to point with coordinates (200, 300) with default color")
	{
		CAdapterModernGraphicsObjectPro adapter(renderer);
		renderer.BeginDraw();
		adapter.MoveTo(20, 20);
		adapter.LineTo(200, 300);
		renderer.EndDraw();
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"200\" toY=\"300\"/>\n"
									"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw line from the custom start point (20, 20) to point with coordinates (200, 300) with custom color #C54B53")
	{
		CAdapterModernGraphicsObjectPro adapter(renderer);
		renderer.BeginDraw();
		adapter.MoveTo(20, 20);
		adapter.SetColor(0xC54B53);
		adapter.LineTo(200, 300);
		renderer.EndDraw();
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"200\" toY=\"300\"/>\n"
									"    <color r=\"0.772549\" g=\"0.294118\" b=\"0.32549\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	CAdapterModernGraphicsObjectPro adapter(renderer);
	renderer.BeginDraw();
	shape_drawing_lib::CCanvasPainter painter(adapter);
	WHEN("We want to draw the triangle with coordinates (20, 20), (30, 10), (10, 10) with color #ffffff")
	{
		shape_drawing_lib::CTriangle triangle({ 20, 20 }, { 30, 10 }, { 10, 10 }, 0xffffff);
		painter.Draw(triangle);
		renderer.EndDraw();
		THEN("We get right message of drawing triangle")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"30\" toY=\"10\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"30\" fromY=\"10\" toX=\"10\" toY=\"10\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"10\" fromY=\"10\" toX=\"20\" toY=\"20\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw the rectangle with left top coordinates (400, 400), width 200, height 400, color #F12FFF")
	{
		shape_drawing_lib::CRectangle rectangle({ 400, 400 }, 200, 400, 0xf12fff);
		painter.Draw(rectangle);
		renderer.EndDraw();
		THEN("We get right message of drawing rectangle")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"400\" fromY=\"400\" toX=\"600\" toY=\"400\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"600\" fromY=\"400\" toX=\"600\" toY=\"800\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"600\" fromY=\"800\" toX=\"400\" toY=\"800\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"400\" fromY=\"800\" toX=\"400\" toY=\"400\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
}

SCENARIO("Class adapter tests")
{
	std::ostringstream output;
	WHEN("We want to draw line from the default start point to point with coordinates (100, 100) with default color")
	{
		{
			CAdapterModernGraphicsClassPro adapter(output);
			adapter.LineTo(100, 100);
		}
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"0\" fromY=\"0\" toX=\"100\" toY=\"100\"/>\n"
									"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw line from the custom start point (20, 20) to point with coordinates (200, 300) with default color")
	{
		{
			CAdapterModernGraphicsClassPro adapter(output);
			adapter.MoveTo(20, 20);
			adapter.LineTo(200, 300);
		}
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"200\" toY=\"300\"/>\n"
									"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw line from the custom start point (20, 20) to point with coordinates (200, 300) with custom color #C54B53")
	{
		{
			CAdapterModernGraphicsClassPro adapter(output);
			adapter.MoveTo(20, 20);
			adapter.SetColor(0xC54B53);
			adapter.LineTo(200, 300);
		}
		THEN("We get right message of drawing line")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"200\" toY=\"300\"/>\n"
									"    <color r=\"0.772549\" g=\"0.294118\" b=\"0.32549\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw the triangle with coordinates (20, 20), (30, 10), (10, 10) with color #ffffff")
	{
		{
			CAdapterModernGraphicsClassPro adapter(output);
			shape_drawing_lib::CCanvasPainter painter(adapter);
			shape_drawing_lib::CTriangle triangle({ 20, 20 }, { 30, 10 }, { 10, 10 }, 0xffffff);
			painter.Draw(triangle);
		}
		THEN("We get right message of drawing triangle")
		{
			REQUIRE(output.str() =="<draw>\n"
									"  <line fromX=\"20\" fromY=\"20\" toX=\"30\" toY=\"10\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"30\" fromY=\"10\" toX=\"10\" toY=\"10\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"10\" fromY=\"10\" toX=\"20\" toY=\"20\"/>\n"
									"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
	WHEN("We want to draw the rectangle with left top coordinates (400, 400), width 200, height 400, color #F12FFF")
	{
		{
			CAdapterModernGraphicsClassPro adapter(output);
			shape_drawing_lib::CCanvasPainter painter(adapter);
			shape_drawing_lib::CRectangle rectangle({ 400, 400 }, 200, 400, 0xf12fff);
			painter.Draw(rectangle);
		}
		THEN("We get right message of drawing rectangle")
		{
			REQUIRE(output.str() == "<draw>\n"
									"  <line fromX=\"400\" fromY=\"400\" toX=\"600\" toY=\"400\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"600\" fromY=\"400\" toX=\"600\" toY=\"800\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"600\" fromY=\"800\" toX=\"400\" toY=\"800\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"  <line fromX=\"400\" fromY=\"800\" toX=\"400\" toY=\"400\"/>\n"
									"    <color r=\"0.945098\" g=\"0.184314\" b=\"1\" a=\"1\" />\n"
									"  </line>\n"
									"</draw>\n");
		}
	}
}