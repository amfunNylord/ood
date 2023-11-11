#pragma once

#include "ICommand_fwd.h"

class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Unexecute() = 0;

	virtual ~ICommand() = default;
};