
#ifndef _STRUCTMANAGER_H
#define	_STRUCTMANAGER_H

#include "BinarySearchTree.h"
#include "hash.h"
#include "CellPhone.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double DEFAULT_LOAD_FACTOR = 0.7;                 //Default load factor to determine hash table initial size.

class StructManager
{
private:
	Hash<CellPhone>*                 hash_Table;	   //Hash Table used for searching
	BinarySearchTree<CellPhone> *      main_BST;	   //BST for sorting by unique primary key
	BinarySearchTree<CellPhone> * secondary_BST;	   //BST for sorting by secondary key
	void             (*printItem) (CellPhone &);	   // Function Pointer to hold visit function to print tree.
	//int arraySize;
	//int itemCount;

public:
	StructManager(int tableSize, void (* display)(CellPhone &item));
	~StructManager();
	
	//int determineHashSize(int fileCount);
	//int nextPrime(int number);
	void displayMenu();
	void menuManager();
	char getLetter();
	int  getNum();
	void searchSubMenu();
	void listSubMenu();
	//void InsertManager();
	//void SearchManager();
	//void DeleteManager();
	//void printList();
	void printTree();
	//void printIndented();
	//void askForKey(string& key); //Asks for the primary search key
	void buildList(CellPhone *phone);//Inserts the data from file to table and tree.
	//void displayEfficiency();
	//bool writeToFile(string fileName);
};



#endif