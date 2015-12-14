#include <iostream>
#include <queue>
#include "Resident.h"



class Road
{
protected:
	std::queue<Resident*> drivers;
private:
	int length;
	int capacity;
	virtual Resident* pop(int clock);
public:
	Road();
	~Road();
	Resident* front();
	virtual void update(int clock);
};

class ResidentialRoad :public Road
{
private:
	Resident* pop(int clock);
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
	Resident* pop(int clock);

public:
	EntryRoad();
	~EntryRoad();
	void update(int clock);

};

class DestRoad :public Road
{
private:
	EntryRoad* source;
	Resident* pop(int clock);
public:
	DestRoad();
	~DestRoad();
	void update(int clock);
};
