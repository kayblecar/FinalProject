#include "Simulation.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Simulation::Simulation()
{

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

	//possible improvement: read road capacities from file instead of input
	int jack, tul, amb, tra, jam, bir;
	do {
		cout << "Capacity for Travis: ";
		cin >> tra;
		if (tra > 0)
			break;
	} while (true);
	do {
		cout << "Capacity for Jackson: ";
		cin >> jack;
		if (jack > 0)
			break;
	} while (true);
	do
	{
		cout << "Capacity for Tulip: ";
		cin >> tul;
		if (tul > 0)
			break;
	} while (true);
	do
	{
		cout << "Capacity for Amber: ";
		cin >> amb;
		if (amb > 0)
			break;
	} while (true);
	do
	{
		cout << "Capacity for James: ";
		cin >> jam;
		if (jam > 0)
			break;
	} while (true);
	do
	{
		cout << "Capacity for Birch: ";
		cin >> bir;
		if (bir > 0)
			break;
	} while (true);

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

	do {
		cout << "Visitors/Hour: ";
		cin >> visitorsPHour;
		if (visitorsPHour <= 60 && visitorsPHour > 0)
			break;
	} while (true);

	clock = 0;
	totalTravelTime = 0;
	totalVisits = 0;
	inTown = 0;
	townFull = 0;

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
			townFull++;

		//update from building backwards
		school->update(clock, totalTravelTime, totalVisits, haveVisited);
		bank->update(clock, totalTravelTime, totalVisits, haveVisited);

		Tulip->update(clock);
		Amber->update(clock);
		James->update(clock);
		Birch->update(clock);
		Jackson->update(clock);
		Travis->update(clock);
	}
	//Finishing information
	cout << "Average travel time: " << totalTravelTime / totalVisits << endl;
	cout << "Please note: Residents did not enter town for " << townFull << " minutes because they were all already there!" << endl;
	string choice;
	bool done = false;
	do {
		cout << "Would you like to view residents? (yes or no)" << endl;
		cin >> choice;
		if (choice == "yes" || choice == "Yes" || choice == "Y" || choice == "y") {
			for (map<string, Resident*>::iterator it = haveVisited.begin(); it != haveVisited.end(); ++it) {
				cout << it->first << endl;

			}
			do {
				cout << "Enter name or 0: ";
				string n;
				cin >> n;
				if (n == "0")//exit
					done = true;
				else if (haveVisited.count(n) != 0) {
					Resident *me = haveVisited.find(n)->second;
					for (map<string, int>::iterator it = me->pastDestinations.begin(); it != me->pastDestinations.end();++it) {
						cout << "Went to " << it->first << " it took " << it->second << " minutes" << endl;
					}
				}
			} while (!done);

		}
		else if (choice == "no" || choice == "No" || choice == "N" || choice == "n") {
			cout << "Goodbye, Have a fantabulous day! :)" << endl;
			done = true;
		}
	} while (!done);



}
