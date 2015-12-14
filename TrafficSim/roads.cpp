#include "Road.h"



Road::Road()
{
}

Road::~Road()
{
}

Resident* Road::front()
{
	return drivers.front();
}

ResidentialRoad::ResidentialRoad()
{

}

ResidentialRoad ::~ResidentialRoad()
{
}

void ResidentialRoad::update(int clock)
{

}

Resident* ResidentialRoad::pop(int clock)
{
	Resident* me = drivers.front();
	drivers.pop();
	int t = clock - me->timeIn; //total time in residential road
	me->travelTime += t; //update wait time
	return me;

}

void ResidentialRoad::reserve()
{
	//increase capacity of road as necessary
}

void ResidentialRoad::update(int clock)
{

}

EntryRoad::EntryRoad()
{

}

EntryRoad :: ~EntryRoad()
{

}

Resident * EntryRoad::pop(int clock)
{

}

void EntryRoad::update(int clock)
{
	Resident* me = sourceRoad->front();
	if (me->timeHere < clock - me->timeIn)
	{
		//pop
	}
}

DestRoad::DestRoad()
{

}

DestRoad:: ~DestRoad()
{

}

Resident * DestRoad::pop(int clock)
{

}

void DestRoad::update(int clock)
{

}