#include <iostream>
#include <queue>
#include "Resident.h"



class Road
{
protected:
	std::queue<Resident*> drivers;
	int capacity;
private:
	int length;

public:
	Road(int l, int c);
	~Road();
	Resident* front();
	Resident* pop(int clock);
	virtual void update(int clock);
};

class ResidentialRoad :public Road
{
public:
	ResidentialRoad();
	~ResidentialRoad();
	void update(int clock);

};

class EntryRoad : public Road
{
private:
	ResidentialRoad* sourceRoad;

public:
	EntryRoad(int l, int c, ResidentialRoad* src);
	~EntryRoad();
	void update(int clock);

};

class DestRoad :public Road
{
private:
	EntryRoad* source;
public:
	DestRoad(int l, int c, EntryRoad* src);
	~DestRoad();
	void update(int clock);
};
