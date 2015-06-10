#ifndef CELLPHONE_H
#define CELLPHONE_H

#include <iostream>
using namespace std;

class CellPhone
{
private:
	string id;
	string name;
	string model;
	double memory;
	int apps;
	int songs;

public:
	//Constructors
	CellPhone();
	CellPhone(string id, string name, string model, double memory, int apps, int songs);

	//Accesors

	string getID(){ return id; }
	string getName(){ return name; }
	string getModel() { return model; }
	double getMemory() { return memory; }
	int getApps() { return apps; }
	int getSongs() { return songs; }

	//Mutators

	void setID(string id) { this->id = id; }
	void setName(string name){ this->name = name; }
	void setModel(string model){ this->model = model; }
	void setMemory(double memory){ this->memory = memory; }
	void setApps(int apps){ this->apps = apps; }
	void setSongs(int songs){ this->songs = songs; }

	//Overloaded operators

	//Overloaded operators
	bool CellPhone::operator> (const CellPhone &right){ return (id.compare(right.id) > 0); }
	bool CellPhone::operator==(const CellPhone &right){ return (id.compare(right.id) == 0); }
	bool CellPhone::operator< (const CellPhone &right){ return (id.compare(right.id) < 0); }
	bool CellPhone::operator<=(const CellPhone &right){ return (id.compare(right.id) <= 0); }
	bool CellPhone::operator>=(const CellPhone &right){ return (id.compare(right.id) >= 0); }

	//Destrcutor
	~CellPhone(){};

};

#endif
