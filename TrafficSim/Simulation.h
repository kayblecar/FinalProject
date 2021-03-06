#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <iostream>
#include "Building.h"
#include "Resident.h"
#include "Road.h"
#include <map>
#include <vector>
using namespace std;

class Simulation {
private:
	Building* school;
	Building* bank;
	vector<Resident*>residents; 
	map<string, Resident*> haveVisited;
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
	int inTown;
	int townFull;
public:
	Simulation();
	void run();
};

#endif