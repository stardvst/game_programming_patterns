#include <iostream>
#include <random>
#include <ctime>

class Mesh {};
class Texture {};
class Vector {};
class Color {};

class TreeModel
{
private:
	Mesh m_mesh;
	Texture m_bark;
	Texture m_leaves;
};

class Tree
{
private:
	TreeModel *m_model;

	Vector m_pos;
	double m_height;
	double m_thickness;
	Color m_barkTint;
	Color m_leafTint;
};

// #2
enum class eTerrain
{
	TERRAIN_GRASS, TERRAIN_HILL, TERRAIN_RIVER
};

enum class eTexture
{
	TEXTURE_GRASS, TEXTURE_HILL, TEXTURE_RIVER
};

class Terrain
{
public:
	Terrain(int mc, int iw, eTexture t) : m_movementCost(mc), m_isWater(iw), m_texture(t) {}

	int getMovementCost() const { return m_movementCost; }
	bool isWater() const { return m_isWater; }
	eTexture getTexture() const { return m_texture; }

private:
	int m_movementCost;
	bool m_isWater;
	eTexture m_texture;
};

class World
{
public:
	World()
		: m_grassTerrain(1, false, eTexture::TEXTURE_GRASS)
		, m_hillTerrain(3, false, eTexture::TEXTURE_HILL)
		, m_riverTerrain(2, true, eTexture::TEXTURE_RIVER)
	{}

	void generateTerrain()
	{
		srand(time(nullptr));

		// fill with grass
		for (auto & tile : m_tiles)
		{
			for (auto & y : tile)
			{
				if (rand() % 10 == 0) y = &m_hillTerrain;
				else y = &m_grassTerrain;
			}
		}

		// lay a river
		int x = rand() % WIDTH;
		for (int y = 0; y < HEIGHT; ++y)
			m_tiles[x][y] = &m_riverTerrain;
	}

	const Terrain &getTile(int x, int y) const
	{
		return *m_tiles[x][y];
	}

private:
	static constexpr auto WIDTH = 100;
	static constexpr auto HEIGHT = 100;
	Terrain *m_tiles[WIDTH][HEIGHT];

	Terrain m_grassTerrain;
	Terrain m_hillTerrain;
	Terrain m_riverTerrain;
};

int main()
{
	World w;
	w.generateTerrain();

	// however, this is indirection => might hit cache miss...
	std::cout << w.getTile(3, 6).getMovementCost() << '\n';
	std::cout << w.getTile(79, 2).getMovementCost() << '\n';
	std::cout << w.getTile(5, 5).getMovementCost() << '\n';
	std::cout << w.getTile(22, 90).getMovementCost() << '\n';
	std::cout << w.getTile(56, 78).getMovementCost() << '\n';
	std::cout << w.getTile(0, 43).getMovementCost() << '\n';

	std::cin.get();
	return 0;
}