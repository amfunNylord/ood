#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab7/CEllipse.h"
#include "../lab7/CGroup.h"
#include "../lab7/CRectangle.h"
#include "../lab7/CTriangle.h"

SCENARIO("Testing empty group")
{
	CGroup group;
	WHEN("We try to get shapes count")
	{
		size_t countOfShapes = group.GetShapesCount();
		THEN("We get zero")
		{
			REQUIRE(countOfShapes == 0);
		}
	}
}

SCENARIO("Testing inserting shapes")
{
	CGroup group;
	WHEN("We try to insert nullptr")
	{
		THEN("We get exception \"logic_error\"")
		{
			REQUIRE_THROWS_AS(group.InsertShape(nullptr, 0), std::logic_error);
		}
	}
	WHEN("We try to insert some shape in invalid position")
	{
		auto triangle = std::make_shared<CTriangle>(PointD(10, 10), PointD(20, 10), PointD(50, 30));
		THEN("We get exception \"logic_error\"")
		{
			REQUIRE_THROWS_AS(group.InsertShape(triangle, -10), std::logic_error);
			REQUIRE_THROWS_AS(group.InsertShape(triangle, 10), std::logic_error);
		}
	}
	WHEN("We try insert some shape in right position")
	{
		auto rectangle = std::make_shared<CRectangle>(50, 40, 200, 400);
		group.InsertShape(rectangle, 0);
		THEN("Count of shapes became 1 and shape is rectangle")
		{
			REQUIRE(group.GetShapesCount() == 1);
			auto shape = group.GetShapeAtIndex(0)->GetFrame().value();
			REQUIRE(shape.left == 50);
			REQUIRE(shape.top == 40);
			REQUIRE(shape.width == 200);
			REQUIRE(shape.height == 400);
		}

	}
	WHEN("We try insert two shapes")
	{
		auto rectangle = std::make_shared<CRectangle>(50, 40, 200, 400);
		group.InsertShape(rectangle, 0);
		auto rectangle2 = std::make_shared<CRectangle>(80, 60, 250, 500);
		group.InsertShape(rectangle2, 1);
		THEN("Count of shapes became 2 and both shapes are rectangles")
		{
			REQUIRE(group.GetShapesCount() == 2);
			auto shape = group.GetShapeAtIndex(0)->GetFrame().value();
			REQUIRE(shape.left == 50);
			REQUIRE(shape.top == 40);
			REQUIRE(shape.width == 200);
			REQUIRE(shape.height == 400);

			auto shape2 = group.GetShapeAtIndex(1)->GetFrame().value();
			REQUIRE(shape2.left == 80);
			REQUIRE(shape2.top == 60);
			REQUIRE(shape2.width == 250);
			REQUIRE(shape2.height == 500);
		}
	}
}

SCENARIO("Testing removing shapes")
{
	CGroup group;
	WHEN("We try to remove shape with invalid index")
	{
		THEN("We get exception \"logic_error\"")
		{
			REQUIRE_THROWS_AS(group.RemoveShapeAtIndex(0), std::logic_error);
			REQUIRE_THROWS_AS(group.RemoveShapeAtIndex(-10), std::logic_error);
		}
	}
	
	WHEN("We try to remove shape from start position from group with 3 shapes")
	{
		auto rectangle1 = std::make_shared<CRectangle>(30, 40, 50, 60);
		group.InsertShape(rectangle1, 0);
		auto rectangle2 = std::make_shared<CRectangle>(40, 50, 60, 70);
		group.InsertShape(rectangle2, 1);
		auto rectangle3 = std::make_shared<CRectangle>(50, 60, 70, 80);
		group.InsertShape(rectangle3, 2);
		REQUIRE(group.GetShapesCount() == 3);
		group.RemoveShapeAtIndex(0);
		THEN("Count of shapes 2 and shapes are rectangle2 and rectangle3")
		{
			REQUIRE(group.GetShapesCount() == 2);
			auto shape1 = group.GetShapeAtIndex(0)->GetFrame().value();
			REQUIRE(shape1.left == 40);
			REQUIRE(shape1.top == 50);
			REQUIRE(shape1.width == 60);
			REQUIRE(shape1.height == 70);
			auto shape2 = group.GetShapeAtIndex(1)->GetFrame().value();
			REQUIRE(shape2.left == 50);
			REQUIRE(shape2.top == 60);
			REQUIRE(shape2.width == 70);
			REQUIRE(shape2.height == 80);
		}
	}
	WHEN("We try to remove shape from end position")
	{
		auto rectangle1 = std::make_shared<CRectangle>(30, 40, 50, 60);
		group.InsertShape(rectangle1, 0);
		auto rectangle2 = std::make_shared<CRectangle>(40, 50, 60, 70);
		group.InsertShape(rectangle2, 1);
		auto rectangle3 = std::make_shared<CRectangle>(50, 60, 70, 80);
		group.InsertShape(rectangle3, 2);
		REQUIRE(group.GetShapesCount() == 3);
		group.RemoveShapeAtIndex(2);
		THEN("Count of shapes 2 and shapes are rectangle1 and rectangle2")
		{
			REQUIRE(group.GetShapesCount() == 2);
			auto shape1 = group.GetShapeAtIndex(0)->GetFrame().value();
			REQUIRE(shape1.left == 30);
			REQUIRE(shape1.top == 40);
			REQUIRE(shape1.width == 50);
			REQUIRE(shape1.height == 60);
			auto shape2 = group.GetShapeAtIndex(1)->GetFrame().value();
			REQUIRE(shape2.left == 40);
			REQUIRE(shape2.top == 50);
			REQUIRE(shape2.width == 60);
			REQUIRE(shape2.height == 70);
		}
	}
	WHEN("We try to remove shape from mid position")
	{
		auto rectangle1 = std::make_shared<CRectangle>(30, 40, 50, 60);
		group.InsertShape(rectangle1, 0);
		auto rectangle2 = std::make_shared<CRectangle>(40, 50, 60, 70);
		group.InsertShape(rectangle2, 1);
		auto rectangle3 = std::make_shared<CRectangle>(50, 60, 70, 80);
		group.InsertShape(rectangle3, 2);
		REQUIRE(group.GetShapesCount() == 3);
		group.RemoveShapeAtIndex(1);
		THEN("Count of shapes 2 and shapes are rectangle1 and rectangle3")
		{
			REQUIRE(group.GetShapesCount() == 2);
			auto shape1 = group.GetShapeAtIndex(0)->GetFrame().value();
			REQUIRE(shape1.left == 30);
			REQUIRE(shape1.top == 40);
			REQUIRE(shape1.width == 50);
			REQUIRE(shape1.height == 60);
			auto shape2 = group.GetShapeAtIndex(1)->GetFrame().value();
			REQUIRE(shape2.left == 50);
			REQUIRE(shape2.top == 60);
			REQUIRE(shape2.width == 70);
			REQUIRE(shape2.height == 80);
		}
	}
}

SCENARIO("Test styling functions")
{
	CGroup group;
	auto rectangle = std::make_shared<CRectangle>(30, 40, 50, 60);
	rectangle->GetFillStyle()->Enable();
	rectangle->GetFillStyle()->SetColor(0xFF2312FF);
	rectangle->GetLineStyle()->Enable();
	rectangle->GetLineStyle()->SetThickness(2);
	rectangle->GetLineStyle()->SetColor(0xAA3123FF);

	auto ellipse = std::make_shared<CEllipse>(PointD(100, 100), 100, 200);
	ellipse->GetFillStyle()->Disable();
	ellipse->GetFillStyle()->SetColor(0x23FF12FF);
	ellipse->GetLineStyle()->Disable();
	ellipse->GetLineStyle()->SetThickness(4);
	ellipse->GetLineStyle()->SetColor(0x22AAFFFF);
	
	group.InsertShape(rectangle, 0);
	group.InsertShape(ellipse, 1);

	WHEN("We want to get styles of group, shapes have different styles")
	{
		THEN("Styles are default")
		{
			REQUIRE(group.GetFillStyle()->IsEnabled() == false);
			REQUIRE(group.GetLineStyle()->IsEnabled() == false);
			REQUIRE(group.GetFillStyle()->GetColor() == std::nullopt);
			REQUIRE(group.GetLineStyle()->GetColor() == std::nullopt);
			REQUIRE(group.GetLineStyle()->GetThickness() == std::nullopt);
		}
	}
	auto triangle = std::make_shared<CTriangle>(PointD(50, 50), PointD(50, 100), PointD(75, 200));
	triangle->GetFillStyle()->Enable();
	triangle->GetFillStyle()->SetColor(0x11BB23FF);
	triangle->GetLineStyle()->Enable();
	triangle->GetLineStyle()->SetThickness(3);
	triangle->GetLineStyle()->SetColor(0x33CC12FF);
	
	group.InsertShape(triangle, 2);
	WHEN("We want to set styles of group")
	{
		group.GetFillStyle()->Enable();
		group.GetFillStyle()->SetColor(0xFFFFFFFF);
		group.GetLineStyle()->Enable();
		group.GetLineStyle()->SetColor(0x000000FF);
		group.GetLineStyle()->SetThickness(1);
		THEN("Group has the same styles and every shape has the same style")
		{
			REQUIRE(group.GetFillStyle()->IsEnabled() == true);
			REQUIRE(group.GetFillStyle()->GetColor() == 0xFFFFFFFF);
			REQUIRE(group.GetLineStyle()->IsEnabled() == true);
			REQUIRE(group.GetLineStyle()->GetThickness() == 1);
			REQUIRE(group.GetLineStyle()->GetColor() == 0x000000FF);

			REQUIRE(group.GetShapeAtIndex(0)->GetFillStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(0)->GetFillStyle()->GetColor() == 0xFFFFFFFF);
			REQUIRE(group.GetShapeAtIndex(0)->GetLineStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(0)->GetLineStyle()->GetThickness() == 1);
			REQUIRE(group.GetShapeAtIndex(0)->GetLineStyle()->GetColor() == 0x000000FF);

			REQUIRE(group.GetShapeAtIndex(1)->GetFillStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(1)->GetFillStyle()->GetColor() == 0xFFFFFFFF);
			REQUIRE(group.GetShapeAtIndex(1)->GetLineStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(1)->GetLineStyle()->GetThickness() == 1);
			REQUIRE(group.GetShapeAtIndex(1)->GetLineStyle()->GetColor() == 0x000000FF);

			REQUIRE(group.GetShapeAtIndex(2)->GetFillStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(2)->GetFillStyle()->GetColor() == 0xFFFFFFFF);
			REQUIRE(group.GetShapeAtIndex(2)->GetLineStyle()->IsEnabled() == true);
			REQUIRE(group.GetShapeAtIndex(2)->GetLineStyle()->GetThickness() == 1);
			REQUIRE(group.GetShapeAtIndex(2)->GetLineStyle()->GetColor() == 0x000000FF);
		}
	}
}

SCENARIO("Test frame functions")
{
	CGroup group;
	auto rectangle = std::make_shared<CRectangle>(100, 100, 300, 200);
	auto ellipse = std::make_shared<CEllipse>(PointD(250, 200), 50, 50);
	group.InsertShape(rectangle, 0);
	group.InsertShape(ellipse, 1);
	WHEN("We want to get frame of group")
	{
		auto frameGroup = group.GetFrame().value();
		THEN("We get frame (100, 100) and 300x200")
		{
			REQUIRE(frameGroup.left == 100);
			REQUIRE(frameGroup.top == 100);
			REQUIRE(frameGroup.width == 300);
			REQUIRE(frameGroup.height == 200);
		}
	}
	WHEN("We want set new frame")
	{
		group.SetFrame(RectD(100, 100, 150, 100));
		THEN("We get frame (100, 100) and 150x100 and shapes are sized")
		{
			auto frameGroup = group.GetFrame().value();
			REQUIRE(frameGroup.left == 100);
			REQUIRE(frameGroup.top == 100);
			REQUIRE(frameGroup.width == 150);
			REQUIRE(frameGroup.height == 100);

			auto frameRectangle = rectangle->GetFrame().value();
			REQUIRE(frameRectangle.left == 100);
			REQUIRE(frameRectangle.top == 100);
			REQUIRE(frameRectangle.width == 150);
			REQUIRE(frameRectangle.height == 100);

			auto frameEllipse = ellipse->GetFrame().value();
			REQUIRE(frameEllipse.left == 150);
			REQUIRE(frameEllipse.top == 125);
			REQUIRE(frameEllipse.width == 50);
			REQUIRE(frameEllipse.height == 50);
		}
	}
}