#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <string>
#include <vector>
#include "Road.h"
#include "Resident.h"
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
	Building(string n, int min, int max, DestRoad *src1, DestRoad *src2)
	{
		name = n;
		minVisit = min;
		maxVisit = max;
		sources[0] = src1;
		sources[1] = src2;
	}
	int getWait();
	string getName() { return name; }
	//FIXME: update totals
	void update(int clock, Simulation *sim);
};

#endif