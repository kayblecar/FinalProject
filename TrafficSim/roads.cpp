#include "Road.h"



Road::Road(int l, int c)
{
	length = l;
	capacity = c;
}

Road::~Road()
{
}

Resident* Road::pop(int clock)
{
	Resident* me = drivers.front();
	drivers.pop();
	int t = clock - me->timeIn; //total time in road
	me->travelTime += t; //update wait time
	return me;
}


Resident* Road::front()
{
	return drivers.front();
}

void Road::update(int clock)
{

}

ResidentialRoad::ResidentialRoad() : Road(0,0)
{
	
}

ResidentialRoad ::~ResidentialRoad()
{

}


void ResidentialRoad::update(int clock)
{

}

EntryRoad::EntryRoad(int l, int c, ResidentialRoad* src):Road(l,c)
{
	sourceRoad = src;
}

EntryRoad :: ~EntryRoad()
{

}


void EntryRoad::update(int clock)
{
	bool done = false;
	while (!done && drivers.size() < capacity) {
		Resident* me = sourceRoad->front();
		if (me->timeHere < clock - me->timeIn) //if resident has been on road long enough
		{
			drivers.push(sourceRoad->pop(clock));
		}
		else done = true;
	};
}

DestRoad::DestRoad(int l, int c, EntryRoad* src):Road(l,c)
{
	source = src;
}

DestRoad:: ~DestRoad()
{

}


void DestRoad::update(int clock)
{
	bool done = false;
	while (!done && drivers.size() < capacity) {
		Resident* me = source->front();
		if (me->timeHere < clock - me->timeIn) //if resident has been on road long enough
			{
				drivers.push(source->pop(clock));
			}
			else done = true;
		} ;
	}