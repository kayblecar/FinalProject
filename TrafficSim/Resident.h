#ifndef _RESIDENT_H_
#define _RESIDENT_H_

#include<iostream>
#include<string>
#include <map>
using namespace std;

//FIXME: change dest. to string?

struct Resident
{
	string name;
	string destination;
	int speed;
	int travelTime = -1; //total travel time for current visit. =-1 if not currently in town
	int timeIn; //time resident entered current location
	int timeHere; //calculated (minimum) time for resident to be in current location
	int visits;
	multimap <string, int> pastDestinations;//building names, time it took to go there

};

#endif	



