#include "Command.h"
#include "InputHandlerh.h"
#include "Buttons.h"
#include "Util.h"

int main()
{
	auto pHandler = new InputHandler;

	pHandler->handleInput();

	// start "game"
	pressButton(Buttons::BUTTON_X);
	pHandler->handleInput();

	pressButton(Buttons::BUTTON_A);
	pHandler->handleInput();

	pressButton(Buttons::BUTTON_Y);
	pHandler->handleInput();

	pressButton(Buttons::BUTTON_B);
	pHandler->handleInput();

	pressButton(Buttons::BUTTON_A);
	pHandler->handleInput();

	std::cin.get();
	return 0;
}