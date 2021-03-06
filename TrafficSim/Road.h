#ifndef _ROAD_H_
#define _ROAD_H_

#include <queue>
#include "Resident.h"
#include <string>
using namespace std;


class Road
{
protected:
	queue <Resident*> drivers;//Possible improvement: use priority queue to simulate multiple-lane road
	int capacity;
	int length;

public:
	Road(int l, int c);
	~Road();
	Resident* front();
	Resident* pop(int clock);
	bool isOccupied() {
		if (drivers.empty())
			return false;
		else
			return true;
	}
	virtual void update(int clock);
};

class ResidentialRoad :public Road
{
public:
	ResidentialRoad();
	~ResidentialRoad();
	void update(int clock);
	void enter(int clock, Resident * me);

};

class EntryRoad : public Road
{
private:
	ResidentialRoad* sourceRoad;

public:
	EntryRoad(int l, int c, ResidentialRoad* src);
	~EntryRoad();
	void update(int clock);

};
class DestRoad :public Road
{
private:
	EntryRoad* source;
	string dest;//Bedford:changed dest to string
public:
	DestRoad(int l, int c, EntryRoad* src, string d);//Bedford:changed d to string 
	~DestRoad();
	void update(int clock);
};
#endif