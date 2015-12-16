#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <iostream>
#include "Building.h"
#include "Resident.h"
#include "Road.h"
#include <vector>
using namespace std;

class Simulation {
private:
	Building* school;
	Building* bank;
	vector<Resident*>residents; //FIXME: map w/ resident index + pt to some record class
	ResidentialRoad* toJackson;
	ResidentialRoad* toTravis;
	EntryRoad* Jackson;
	DestRoad* Tulip;
	DestRoad* Amber;
	EntryRoad* Travis;
	DestRoad* James;
	DestRoad* Birch;
	int visitorsPHour;
	int clock;
	int totalVisits;
	int totalTravelTime;
public:
	Simulation();
	void updateTotals(int visits, int time);
	void run();
};

#endif