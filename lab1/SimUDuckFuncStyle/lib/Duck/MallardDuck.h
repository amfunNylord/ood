#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(flyWithWings, quackBehavior, danceWaltzBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

#endif
