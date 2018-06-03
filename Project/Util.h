#ifndef UTIL_H
#define UTIL_H

#include <iostream>

#include "Buttons.h"

Buttons pressedButton = Buttons::NO_BUTTON;

GameActor *pSelectedActor = nullptr;

void pressButton(Buttons button)
{
	pressedButton = button;
}

bool isPressed(Buttons button)
{
	return pressedButton == button;
}

void selectActor(GameActor *pActor)
{
	pSelectedActor = pActor;
}

GameActor *getSelectedActor()
{
	return pSelectedActor;
}

#endif // !UTIL_H
