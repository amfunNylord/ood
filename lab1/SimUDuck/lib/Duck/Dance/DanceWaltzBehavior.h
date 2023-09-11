#ifndef DANCEWALTZBEHAVIOR_H
#define DANCEWALTZBEHAVIOR_H

#include "IDanceBehavior.h"
#include <iostream>

class DanceWaltzBehavior : public IDanceBehavior
{
	void Dance() override
	{
		std::cout << "I am dancing waltz" << std::endl;
	}
};

#endif 
