#include <iostream>
#include "Monster.h"

int main()
{
	auto ghostPrototype = new Ghost{ 15,3 };
	auto ghostSpawner = new Spawner1(ghostPrototype);

	auto newGhost = ghostSpawner->spawnMonster();
	auto newGhost2 = ghostSpawner->spawnMonster();

	std::cout << "Monsters are:\n"
		<< "1. " << ghostPrototype << ", " << ghostPrototype->health() << ", " << ghostPrototype->speed() << '\n'
		<< "2. " << newGhost << ", " << newGhost->health() << ", " << newGhost->speed() << '\n'
		<< "3. " << newGhost2 << ", " << newGhost2->health() << ", " << newGhost2->speed() << '\n';

	//////////////////////////////////////////////////////////////////////////

	auto ghostSpawner2 = new Spawner2(spawnGhost);
	auto newGhost3 = ghostSpawner2->spawnMonster();
	std::cout << "Spawned a new ghost: " << newGhost3 << ", " << newGhost3->health() << ", " << newGhost3->speed() << '\n';

	//////////////////////////////////////////////////////////////////////////

	Spawner *ghostSpawnerFor = new SpawnerFor<Ghost>{};
	auto newGhost4 = ghostSpawnerFor->spawneMonster();
	std::cout << "Spawned another ghost: " << newGhost4 << ", " << newGhost4->health() << ", " << newGhost4->speed() << '\n';

	std::cin.get();
	return 0;
}