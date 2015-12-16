#include "Road.h"
using namespace std;


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

void ResidentialRoad::enter(int clock, Resident* me)
{
	drivers.push(me);
	me->timeIn = clock;
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
			me->timeIn = clock;
			me->timeHere = me->speed * length;
		}
		else done = true;
	};
}

DestRoad::DestRoad(int l, int c, EntryRoad* src, string d):Road(l,c)//Bedford: changed d to string so it can be set equal to dest
{
	source = src;
	dest = d;
}

DestRoad:: ~DestRoad()
{

}


void DestRoad::update(int clock)
{
	bool done = false;
	while (!done && drivers.size() < capacity) {
		Resident* me = source->front();
		if (me->destination == dest) {//Bedford: needed second equal sign 
			if (me->timeHere < clock - me->timeIn) //if resident has been on road long enough
			{
				drivers.push(source->pop(clock));
				me->timeIn = clock;
				me->timeHere = me->speed * length;
			}
			else done = true;
		}
		} ;
	}