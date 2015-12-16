#include "Building.h"
using namespace std;

int Building::getWait()
{
	int wait = minVisit + rand() % (maxVisit + 1 - minVisit);
	return wait;
}

//FIXME: update totals, reset resident travel time -1
void Building::update(int clock, Simulation *sim)
{
	Resident *me;
	for (int i = 0; i <= 1; i++)
	{
		DestRoad *source = sources[i];
		bool done = false;
		do {
			me = source->front();
			if (me->timeHere < clock - me->timeIn) //if resident has been on road long enough
			{
				visitor.push_back(source->pop(clock));
				me->timeIn = clock;
				me->timeHere = this->getWait();
			}
			else done = true;
		} while (!done);
	}

	int addVisits = 0;
	int addTime = 0;

	for (int i = 0; i < visitor.size(); i++)
	{
		me = visitor[i];
		if (me->timeHere >= clock - me->timeIn)
		{
			visitor.erase(visitor.begin() + i);
			//finalize info for "me"
			me->pastDestinations.push_back(this);
			me->visits++;
			addVisits++;
			addTime += me->travelTime;

		}

	}
}

