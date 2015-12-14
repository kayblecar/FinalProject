#include <iostream>
#include <queue>
#include "Resident.h"



class Road
{
private:
	std::queue<Resident*> drivers;
	int length;
	int capacity;
	virtual Resident * pop();
public:
	Road();
	~Road();
	virtual void update(int clock);
};

class ResidentialRoad :public Road
{
private:
	Resident * pop();
	void reserve();
public:
	ResidentialRoad();
	~ResidentialRoad();
	void update(int clock);

};

class EntryRoad : public Road
{
private:
	ResidentialRoad* sourceRoad;
	Resident * pop();

public:
	EntryRoad();
	~EntryRoad();
	void update(int clock);

};

class DestRoad :public Road
{
private:
	EntryRoad* source;
	Resident * pop();
public:
	DestRoad();
	~DestRoad();
	void update();
};
