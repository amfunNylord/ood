#ifndef DUCK_H
#define DUCK_H

#include "DanceBehavior.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <cassert>
#include <iostream>
#include <memory>

class Duck
{
public:
	Duck(const FlyBehavior& flyBehavior, const QuackBehavior& quackBehavior, const DanceBehavior& danceBehavior)
		: m_quackBehavior(quackBehavior)
	{
		SetFlyBehavior(flyBehavior);
		SetDanceBehavior(danceBehavior);
	}

	void Quack() const
	{
		m_quackBehavior();
	}

	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly()
	{
		m_flyBehavior();
	}

	virtual void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(const FlyBehavior& flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}

	void SetDanceBehavior(const DanceBehavior& danceBehavior)
	{
		m_danceBehavior = danceBehavior;
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	FlyBehavior m_flyBehavior;
	QuackBehavior m_quackBehavior;
	DanceBehavior m_danceBehavior;
};

#endif