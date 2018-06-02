#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Command.h"
#include "Buttons.h"
#include "Util.h"

class InputHandler
{
public:
	InputHandler()
	{
		m_pButtonX = new JumpCommand;
		m_pButtonY = new FireCommand;
		m_pButtonA = new LurchCommand;
		m_pButtonB = new SwapWeaponCommand;
		m_pNullButton = new NullCommand;
	}

	void handleInput()
	{
		if (isPressed(Buttons::BUTTON_X)) m_pButtonX->execute();
		else if (isPressed(Buttons::BUTTON_Y)) m_pButtonY->execute();
		else if (isPressed(Buttons::BUTTON_A)) m_pButtonA->execute();
		else if (isPressed(Buttons::BUTTON_B)) m_pButtonB->execute();
		else m_pNullButton->execute();
	}

private:
	Command *m_pButtonX;
	Command *m_pButtonY;
	Command *m_pButtonA;
	Command *m_pButtonB;
	Command *m_pNullButton;
};

#endif // !INPUT_HANDLER_H
