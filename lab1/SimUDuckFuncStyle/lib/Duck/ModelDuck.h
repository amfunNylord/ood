#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(flyNoWay, quackBehavior, danceNoWayBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm model duck" << std::endl;
	}

	void Dance() override {}
};

#endif
