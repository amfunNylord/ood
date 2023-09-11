#ifndef IDANCEBEHAVIOR_H
#define IDANCEBEHAVIOR_H

struct IDanceBehavior
{
	virtual void Dance() = 0;
	virtual ~IDanceBehavior() {}
};

#endif