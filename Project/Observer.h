#ifndef OBSERVER_H
#define OBSERVER_H

enum class Achievement
{
	FELL_OFF_BRIDGE
};

class Entity 
{
public:
	bool isHero() const { return true; }
};

enum class Event
{
	ENTITY_FELL
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity &entity, Event event) = 0;
};

class Achievements : public Observer
{
public:
	void onNotify(const Entity &entity, Event event) override
	{
		switch (event)
		{
			case Event::ENTITY_FELL:
			{
				if (entity.isHero() && m_heroIsBrigde)
					unlock(Achievement::FELL_OFF_BRIDGE);
			}
			default:
				break;
		}
	}

private:
	void unlock(Achievement achievement)
	{
		std::cout << "Unlocked " << static_cast<int>(achievement) << '\n';
	}

	bool m_heroIsBrigde;
};

#endif
