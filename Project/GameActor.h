#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <iostream>
#include <string>

class GameActor
{
public:
	GameActor(const std::string &sName, int nX = 0, int nY = 0)
		: m_sName(sName)
		, m_nX(nX)
		, m_nY(nY)
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

	void moveTo(int nX, int nY)
	{
		std::cout << "Actor " << m_sName << " moved from (" << m_nX << ", " << m_nY << ") to (" << nX << ", " << nY << ")\n";
		
		// set the members
		m_nX = nX;
		m_nY = nY;
	}

	int x() const
	{
		return m_nX;
	}

	int y() const
	{
		return m_nY;
	}

private:
	const std::string m_sName;
	int m_nX { 0 };
	int m_nY { 0 };
};

#endif // !GAME_ACTOR_H
