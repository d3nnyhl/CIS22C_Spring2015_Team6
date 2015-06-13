//
//  main.cpp
//  team_project
//
//  Created by Sam Singh on 6/9/15.
//  Copyright (c) 2015 Sam Singh. All rights reserved.
//

#include <iostream>
#include "StructManager.h"

using namespace std;

void welcome();
int fileCount(ifstream &inFile);
void readFile(StructManager* structManager, ifstream &inFile);
void displayPhone(CellPhone & anItem);
void farewell();


const unsigned int HASH_TABLE_SIZE = 100;	  // For testing purposes; must write function to determine hash table size.
const string fileName = "cellphones.txt";

int main()
{
	welcome();
	ifstream inFile;		     // ifstream object to input.
	inFile.open(fileName);	     //	open input file.

	if (!inFile)
	{
		cout << "Error opening the input file.\n";
	}
	else
	{
		StructManager *driver = new StructManager(fileCount(inFile), displayPhone);
		readFile(driver, inFile);
		driver->menuManager();
	}
	inFile.close();
	farewell();

	system("pause");
	return 0;
}

//**************************************************************
//	Prints welcome message.
//**************************************************************

void welcome()
{
	cout << "Welcome!\n";
	cout << "This is Team 6's project for the Spring 2015 CIS 22C class.\n";
	cout << "This program maintains a list of cell phones available in the market\n";
	cout << "utilizing a Hash Table for searching and a Binary Search Tree for sorting\n";
	cout << "by primary search key (FCC ID) or secondary search key (manufacturer).\n";
	cout << "Collisions are resolved buckets.\n\n";
	cout << "INPUT FILE NAME IS: cellphones.txt\n\n";
	cout << "Developed by: Sam Singh, Eric Du, Gideon Ubaldo and Denny Hung.\n\n";
}

//**************************************************************
//	Gets amount of items in the input file.
//**************************************************************

int fileCount(ifstream &inFile) {
	string lineCount;
	int count = 0;
	while (getline(inFile, lineCount)) {
		count++;
	}
	inFile.close();
	inFile.open(fileName);
	return count;
}
//**************************************************************
//	Function that reads input from file.
//**************************************************************

void readFile(StructManager *structManager, ifstream &inFile)
{
	// local variables to store input from file.
	string id = "";
	string name = "";
	string model = "";
	double memory = 0;
	int apps = 0;
	int songs = 0;

	while (getline(inFile, id, ';'))
	{
		getline(inFile, name, ';');
		getline(inFile, model, ';');
		inFile >> memory >> apps >> songs;
		inFile.get();
			
		CellPhone *newCellPhone = new CellPhone(id, name, model, memory, apps, songs);

		structManager->buildList(newCellPhone);

		delete newCellPhone;
	}
}

//**************************************************************
//	Displays an item. //Under construction
//**************************************************************
void displayPhone(CellPhone & anItem)
{
	cout << fixed << setprecision(1);
	cout  << anItem.getID() << " " << anItem.getName() << " " << anItem.getModel()  << " ";
	cout << anItem.getMemory() << " " << anItem.getApps()  << " " << anItem.getSongs() << " " << endl;
}

//**************************************************************
//	Prints farewell message.
//**************************************************************
void farewell()
{
	cout << "Thanks for using our product! Now ending program...\n";
}
