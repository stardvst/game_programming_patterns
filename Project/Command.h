#ifndef COMMAND_H
#define COMMAND_H

#include "Util.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

class JumpCommand : public Command
{
public:
	void execute() override
	{
		jump();
	}
};

class FireCommand : public Command
{
public:
	void execute() override
	{
		fireGun();
	}
};

class LurchCommand : public Command
{
public:
	void execute() override
	{
		lurch();
	}
};

class SwapWeaponCommand : public Command
{
public:
	void execute() override
	{
		swapWeapon();
	}
};

class NullCommand : public Command
{
public:
	void execute() override
	{
	}
};

#endif // !COMMAND_H
