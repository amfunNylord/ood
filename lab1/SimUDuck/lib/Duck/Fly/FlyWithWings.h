#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

// как сделать так чтобы после смены количества вылетов утка не забывала сколько раз она летала если летала крыльями а потом на тяге запоминала

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
