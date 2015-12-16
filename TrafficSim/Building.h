#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "Simulation.h"
using namespace std;

class Building
{
private:
	string name;
	vector <Resident*> visitor;
	int minVisit;
	int maxVisit;
	DestRoad* sources[2];

public:
	Building(int min, int max, DestRoad *src1, DestRoad *src2)
	{
		minVisit = min;
		maxVisit = max;
		sources[0] = src1;
		sources[1] = src2;
	}
	int getWait();
	string getname() { return name; }
	//FIXME: update totals, set travel tim -1
	void update(int clock, Simulation *sim);
};

#endif