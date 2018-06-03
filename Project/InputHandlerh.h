#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Command.h"
#include "Buttons.h"
#include "Util.h"

class InputHandler
{
public:
	InputHandler()
		: m_pNullButton(new NullCommand)
	{
	}

	Command *handleInput()
	{
		auto pActor = getSelectedActor();
		if (!pActor) return m_pNullButton;

		if (isPressed(Buttons::BUTTON_UP))
			return new MoveActorCommand(pActor, pActor->x(), pActor->y() - 1);
	
		if (isPressed(Buttons::BUTTON_DOWN))
			return new MoveActorCommand(pActor, pActor->x(), pActor->y() + 1);

		if (isPressed(Buttons::BUTTON_LEFT))
			return new MoveActorCommand(pActor, pActor->x() + 1, pActor->y());

		if (isPressed(Buttons::BUTTON_RIGHT))
			return new MoveActorCommand(pActor, pActor->x() - 1, pActor->y());

		return m_pNullButton;
	}

private:
	Command *m_pButtonX;
	Command *m_pButtonY;
	Command *m_pButtonA;
	Command *m_pButtonB;
	Command *m_pNullButton;
};

#endif // !INPUT_HANDLER_H
