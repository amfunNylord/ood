#ifndef DANCEMINUETBEHAVIOR_H
#define DANCEMINUETBEHAVIOR_H

#include "IDanceBehavior.h"
#include <iostream>

class DanceMinuetBehavior : public IDanceBehavior
{
	void Dance() override
	{
		std::cout << "I am dancing minuet" << std::endl;
	}
};

#endif 
