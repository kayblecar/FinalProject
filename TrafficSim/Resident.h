#include<iostream>
#include<string>
#include "Building.h"
#include <vector>
using namespace std;


struct Resident
{
	string name;
	Building destination;
	int speed;
	int travelTime = -1; //total travel time for current visit. =-1 if not currently in town
	int timeIn; //time resident entered current location
	int timeHere; //calculated (minimum) time for resident to be in current location
	int visits;
	vector<Building>pastDestinations;

};

		



