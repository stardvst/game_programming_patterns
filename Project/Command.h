#ifndef COMMAND_H
#define COMMAND_H

#include "GameActor.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};

class NullCommand : public Command
{
public:
	void execute() override
	{
	}

	void undo() override
	{
	}

	void redo() override
	{
	}
};

/*
 * Note how the actor is bind to the command. This is to support undo/redo.
 **/
class MoveActorCommand : public Command
{
public:
	MoveActorCommand(GameActor *pActor, int nX, int nY)
		: m_pActor(pActor)
		, m_nX(nX)
		, m_nY(nY)
	{
	}

	void execute() override
	{
		// remember previous state so we can restore it
		m_nXBefore = m_pActor->x();
		m_nYBefore = m_pActor->y();

		m_pActor->moveTo(m_nX, m_nY);
	}

	void undo() override
	{
		// remember previous state so we can redo
		auto nXBefore = m_pActor->x();
		auto nYBefore = m_pActor->y();

		m_pActor->moveTo(m_nXBefore, m_nYBefore);
		
		m_nXBefore = nXBefore;
		m_nYBefore = nYBefore;
	}

	void redo() override
	{
		// remember previous state so we can undo
		auto nXBefore = m_pActor->x();
		auto nYBefore = m_pActor->y();

		m_pActor->moveTo(m_nXBefore, m_nYBefore);

		m_nXBefore = nXBefore;
		m_nYBefore = nYBefore;
	}

private:
	GameActor *m_pActor { nullptr };
	int m_nXBefore { 0 };
	int m_nYBefore { 0 };
	int m_nX { 0 };
	int m_nY { 0 };
};

#endif // !COMMAND_H
