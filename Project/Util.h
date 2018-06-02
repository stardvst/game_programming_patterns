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

//
// Actions - having "global" functions do actions isn't good.
// They have to find the doer isn't good.
// So JumpCommand only knows to make the player jump.
//
void jump()
{
	std::cout << "Some actor jumps\n";
}

void fireGun()
{
	std::cout << "Some actor fires gun\n";
}

void lurch()
{
	std::cout << "Some actor lurches\n";
}

void swapWeapon()
{
	std::cout << "Some actor swaps weapon\n";
}

#endif // !UTIL_H
