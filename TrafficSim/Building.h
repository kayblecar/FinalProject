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
	Building(string n, int min, int max)
	{
		name = n;
		minVisit = min;
		maxVisit = max;
	}
	void setSources(DestRoad *src1, DestRoad *src2)
	{
		sources[0] = src1;
		sources[1] = src2;
	}
	int getWait();
	string getName() { return name; }
	void update(int clock, int & time, int & visits);
};

#endif