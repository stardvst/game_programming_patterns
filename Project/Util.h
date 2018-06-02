#ifndef UTIL_H
#define UTIL_H

#include <iostream>

#include "Buttons.h"

Buttons pressedButton = Buttons::NO_BUTTON;

void pressButton(Buttons button)
{
	pressedButton = button;
}

bool isPressed(Buttons button)
{
	return pressedButton == button;
}

#endif // !UTIL_H
