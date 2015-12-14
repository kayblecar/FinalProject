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
	int travelTime;
	int timeIn;
	int timeHere;
	int visits;
	vector<Building>pastDestinations;

};

		



