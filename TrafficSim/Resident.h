#ifndef _RESIDENT_H_
#define _RESIDENT_H_

#include<iostream>
#include<string>
#include <map>
using namespace std;


struct Resident
{
	string name;
	string destination = "";
	int speed = 0;
	int travelTime = -1; //total travel time for current visit. =-1 if not currently in town
	int timeIn = 0; //time resident entered current location
	int timeHere = 0; //calculated (minimum) time for resident to be in current location
	int visits = 0;
	multimap <string, int> pastDestinations;//building names, time it took to go there
	Resident(string n) { name = n; }
};

#endif	



