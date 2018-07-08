#ifndef MONSTER_H
#define MONSTER_H

//class Monster {};
//
//class Ghost : public Monster {};
//class Demon : public Monster {};
//class Sorcerer : public Monster {};
//
//struct Spawner
//{
//	virtual ~Spawner() = default;
//	virtual Monster *spawnMonster() = 0;
//};
//
//struct GhostSpawner : Spawner
//{
//	Monster *spawnMonster() override { return new Ghost; }
//};
//
//struct DemonSpawner : Spawner
//{
//	Monster *spawnMonster() override { return new Demon; }
//};
//
//struct SorcererSpawner : Spawner
//{
//	Monster *spawnMonster() override { return new Sorcerer; }
//};


struct Monster
{
	virtual ~Monster() = default;
	virtual int health() const = 0;
	virtual int speed() const = 0;

	virtual Monster *clone() = 0;
};

struct Ghost : Monster
{
	Ghost(int health = 0, int speed = 0) : m_health(health), m_speed(speed) {}
	int health() const override { return m_health; }
	int speed() const override { return m_speed; }

	Monster *clone() override { return new Ghost{ m_health, m_speed }; }

private:
	int m_health;
	int m_speed;
};

// many other monsters

struct Spawner1
{
	Spawner1(Monster *prototype) : m_prototype(prototype) {}

	Monster *spawnMonster() { return m_prototype->clone(); }

private:
	Monster * m_prototype = nullptr;
};

//////////////////////////////////////////////////////////////////////////

using SpawnCallback = Monster *(*)();

Monster *spawnGhost()
{
	return new Ghost;
}

struct Spawner2
{
	Spawner2(SpawnCallback spawn) : m_spawn(spawn) {}

	Monster *spawnMonster()
	{
		return m_spawn();
	}

private:
	SpawnCallback m_spawn;
};

//////////////////////////////////////////////////////////////////////////

struct Spawner
{
	virtual ~Spawner() = default;
	virtual Monster *spawneMonster() = 0;
};

template <typename Mnstr>
struct SpawnerFor : Spawner
{
	Monster *spawneMonster() override { return new Mnstr{}; }
};

#endif // !MONSTER_H
