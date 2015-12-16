#include "Simulation.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Simulation::Simulation()
{
	cout << "Starting" << endl;

	school = new Building("school", 5, 10);
	bank = new Building("bank", 10, 20);


	//read residents from file
	string word ("");
	ifstream resList("residents_273ville.txt");
	while (!resList.eof())
	{

		resList >> word;
		residents.push_back(new Resident(word));

	};

	//FIXME?: read road capacities from file instead of input
	int jack, tul, amb, tra, jam, bir;
	cout << "Capacity for Travis: ";
	cin >> tra;
	cout << "Capacity for Jackson: ";
	cin >> jack;
	cout << "Capacity for Tulip: ";
	cin >> tul;
	cout << "Capacity for Amber: ";
	cin >> amb;
	cout << "Capacity for James: ";
	cin >> jam;
	cout << "Capacity for Birch: ";
	cin >> bir;

	toJackson = new ResidentialRoad();
	toTravis = new ResidentialRoad();
	Travis = new EntryRoad(3, tra, toTravis);
	Jackson = new EntryRoad(3, jack, toJackson);
	Tulip = new DestRoad(3, tul, Jackson, school->getName());
	Amber = new DestRoad(6, amb, Jackson, bank->getName());
	James = new DestRoad(4, jam, Travis, bank->getName());
	Birch = new DestRoad(5, bir, Travis, school->getName());

	school->setSources(Tulip, Birch);
	bank->setSources(Amber, James);

	cout << "Visitors/Hour: ";
	cin >> visitorsPHour;

	clock = 0;
	totalTravelTime = 0;
	totalVisits = 0;
	inTown = 0;

}

void Simulation::run()
{
	Resident* me;

	for (clock = 1; clock < 10080; clock++)
	{
		if (inTown < residents.size())//check that we don't have everyone in town
		{
			//add new resident per statistics
			int chance = rand() % 60;
			if (chance < visitorsPHour) {
				do {
					me = residents[rand() % residents.size()];
					inTown++;
				} while (me->travelTime != -1);

				me->speed = 25 + rand() % 11;
				me->travelTime = 0;
				chance = rand() % 100 + 1;
				if (chance <= 30)
					me->destination = bank->getName();
				else
					me->destination = school->getName();

				//add to one of the residential roads
				chance = rand() % 2;
				if (chance == 0)
					toTravis->enter(clock, me);
				else
					toJackson->enter(clock, me);
			}
		}
		else
			cout << "No one came to town in minute " << clock << " because Everyone was in town." << endl;

		//update from building backwards
		school->update(clock, totalTravelTime, totalVisits);
		bank->update(clock, totalTravelTime, totalVisits);

		Tulip->update(clock);
		Amber->update(clock);
		James->update(clock);
		Birch->update(clock);
		Jackson->update(clock);
		Travis->update(clock);
	}

	cout << "Average travel time: " << totalTravelTime / totalVisits << endl;

}
