#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		std::cout << "I'm flying with wings!!" << std::endl;
		m_countOfFlies++;
		std::cout << "My flight number is " << m_countOfFlies << std::endl;
	}

private:
	int m_countOfFlies = 0;
};

#endif
