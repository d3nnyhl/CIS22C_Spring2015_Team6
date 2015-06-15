
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
	Hash<CellPhone, string> *        hash_Table;	   //Hash Table used for searching
	BinarySearchTree<CellPhone> *      main_BST;	   //BST for sorting by unique primary key
	BinarySearchTree<CellPhone> * secondary_BST;	   //BST for sorting by secondary key
	void             (*printItem) (CellPhone &);	   // Function Pointer to hold visit function to print tree.
	int (*hashGenerator)(const string& key, const int &arraySize); //Function Pointer to hold hash generator
	//int arraySize;
	//int itemCount;

public:
	StructManager(int tableSize, void(*display)(CellPhone &item), int(*hashFunction)(const string& key, const int &arraySize));
	~StructManager();
	
	
	//Determine hash table size
	int determineHashSize(int);
	int nextPrime(int);
	bool isPrime(int);

	// Builds initial hash table and BSTs
	void buildList(CellPhone *phone);

	// Menu operations
	void displayMenu();
	void menuManager();
	char getLetter();
	int  getNum();
	void searchSubMenu();
	void listSubMenu();

	//int hashGenerator(const string& key, const int &arraySize);
	void InsertManager();
	//void SearchManager();
	//void DeleteManager();
	//void printList();
	//void printTree();
	//void printIndented();
	//void askForKey(string& key); //Asks for the primary search key
	
	//void displayEfficiency();
	//bool writeToFile(string fileName);
};



#endif