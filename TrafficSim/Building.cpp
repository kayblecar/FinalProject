#include "Building.h"
using namespace std;

int Building::getWait()
{
	int wait = minVisit + rand() % (maxVisit + 1 - minVisit);
	return wait;
}

void Building::update(int clock, int & time, int & visits)
{
	for (int i = 0; i <= 1; i++)
	{
		DestRoad *source = sources[i];
		bool done = false;
		do {
			if (source->isOccupied()) {
				Resident *me = source->front();
				if (me->timeHere < clock - me->timeIn) //if resident has been on road long enough, add it to residents in building
				{
					visitor.push_back(source->pop(clock));
					me->timeIn = clock;
					me->timeHere = this->getWait();
				}
				else done = true;
			}
			else done = true;
		} while (!done);
	}

	for (int i = 0; i < visitor.size(); i++)//check each resident to see if they have been in building long enough
	{
		Resident *me = visitor[i];
		if (me->timeHere >= clock - me->timeIn)
		{
			visitor.erase(visitor.begin() + i);
			//finalize info for "me"
			me->pastDestinations.insert(pair<string, int>(me->destination, me->travelTime));
			me->visits++;
			visits++; //updates simulation visits and total time
			time += me->travelTime;
			me->travelTime = -1;
		}

	}
}

