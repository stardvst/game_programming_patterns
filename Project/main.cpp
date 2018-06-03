#include <vector>

#include "Command.h"
#include "InputHandlerh.h"
#include "GameActor.h"
#include "Buttons.h"
#include "Util.h"

int main()
{
	std::vector<Command *> actorMoves;

	auto pHandler = new InputHandler;
	Command *pMoveCommand = nullptr;

	// create two actors
	auto pActor = new GameActor("Actor1", 7, 4);

	// select the actor, and move it up
	selectActor(pActor);
	pressButton(Buttons::BUTTON_UP);
	pMoveCommand = pHandler->handleInput();
	pMoveCommand->execute();
	pMoveCommand->undo();
	pMoveCommand->redo();
	pMoveCommand->undo();
	pMoveCommand->redo();
	actorMoves.push_back(pMoveCommand);

	pressButton(Buttons::BUTTON_RIGHT);
	pMoveCommand = pHandler->handleInput();
	pMoveCommand->execute();
	actorMoves.push_back(pMoveCommand);

	// free the memory
	for (auto pCommand : actorMoves)
		delete pCommand;

	std::cin.get();
	return 0;
}