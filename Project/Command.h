#ifndef COMMAND_H
#define COMMAND_H

#include "GameActor.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute(GameActor &actor) = 0;
};

class JumpCommand : public Command
{
public:
	void execute(GameActor &actor) override
	{
		actor.jump();
	}
};

class FireCommand : public Command
{
public:
	void execute(GameActor &actor) override
	{
		actor.fireGun();
	}
};

class LurchCommand : public Command
{
public:
	void execute(GameActor &actor) override
	{
		actor.lurch();
	}
};

class SwapWeaponCommand : public Command
{
public:
	void execute(GameActor &actor) override
	{
		actor.swapWeapon();
	}
};

class NullCommand : public Command
{
public:
	void execute(GameActor &/* actor */) override
	{
	}
};

#endif // !COMMAND_H
