#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>

class Observer;

class Subject
{
public:
	void addObserver(Observer *o) { m_observers.push_back(o); }
	void removeObserver(Observer *o) { m_observers.remove(o); }

protected:
	void notify(const Entity &entity, Event event)
	{
		for (auto obs : m_observers)
			obs->onNotify(entity, event);
	}

private:
	std::list<Observer *> m_observers;
};

class Physics : public Subject
{
public:
	void updateEntity(Entity &entity)
	{
		std::cout << "Updating...\n";
		notify(entity, Event::ENTITY_FELL);
	}
};

#endif // !SUBJECT_H
