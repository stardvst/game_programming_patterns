#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <iostream>
#include <string>

class GameActor
{
public:
	GameActor(const std::string &sName)
		: m_sName(sName)
	{
	}

	void jump()
	{
		std::cout << "Actor " << m_sName << " does jump\n";
	}

	void fireGun()
	{
		std::cout << "Actor " << m_sName << " fires gun\n";
	}

	void lurch()
	{
		std::cout << "Actor " << m_sName << " does lurch\n";
	}

	void swapWeapon()
	{
		std::cout << "Actor " << m_sName << " swaps weapon\n";
	}

private:
	const std::string m_sName;
};

#endif // !GAME_ACTOR_H
