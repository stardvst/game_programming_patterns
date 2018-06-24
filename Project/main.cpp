#include <iostream>
#include "Observer.h"
#include "Subject.h"

int main()
{
	Achievements ob1;
	Achievements ob2;
	Achievements ob3;

	Physics subj;
	subj.addObserver(&ob1);
	subj.addObserver(&ob2);
	subj.addObserver(&ob3);

	Entity e;

	subj.updateEntity(e);

	std::cin.get();
	return 0;
}