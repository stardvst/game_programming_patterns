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

	Command *handleInput()
	{
		if (isPressed(Buttons::BUTTON_X)) return m_pButtonX;
		if (isPressed(Buttons::BUTTON_Y)) return m_pButtonY;
		if (isPressed(Buttons::BUTTON_A)) return m_pButtonA;
		if (isPressed(Buttons::BUTTON_B)) return m_pButtonB;
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
