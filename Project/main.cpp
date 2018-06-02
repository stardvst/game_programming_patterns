#include "Command.h"
#include "InputHandlerh.h"
#include "GameActor.h"
#include "Buttons.h"
#include "Util.h"

int main()
{
	auto pHandler = new InputHandler;
	Command *pCommand = nullptr;

	// create two actors
	GameActor actor1("Actor1");
	GameActor actor2("Actor2");

	// this does nothing
	pCommand = pHandler->handleInput();
	pCommand->execute(actor1);

	// start "game"
	pressButton(Buttons::BUTTON_X);
 	pCommand = pHandler->handleInput();
	pCommand->execute(actor1);

	pressButton(Buttons::BUTTON_A);
	pCommand = pHandler->handleInput();
	pCommand->execute(actor1);

	pressButton(Buttons::BUTTON_Y);
	pCommand = pHandler->handleInput();
	pCommand->execute(actor2);

	pressButton(Buttons::BUTTON_B);
	pCommand = pHandler->handleInput();
	pCommand->execute(actor2);

	pressButton(Buttons::BUTTON_A);
	pCommand = pHandler->handleInput();
	pCommand->execute(actor1);

	std::cin.get();
	return 0;
}