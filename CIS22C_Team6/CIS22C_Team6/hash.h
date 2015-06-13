#ifndef HASH_H
#define HASH_H

#include "CellPhone.h"
#include <string>
#include <fstream>

using namespace std;

template<class ItemType>
class Hash
{
private:
    const static int tableSize = 31;				//rows
    const static int bucketSize = 3;                //columns
    ItemType obj;
    ItemType *hashTable [tableSize][bucketSize];
    int count = 0;
    int numOfFullBuckets = 0;
    int numOfEmpty = (tableSize * (bucketSize-1));
    int numOfelementinRows = 0;
public:
	//constructor
	Hash();
    
	//hash generator
	int hashGenerator(string);
    
	void addItem(string,string,string,double,int,int);
    void printTable();
    void printHashT();
    bool findKey(string);
    
    //getters
	int getCount(){return count;}
    int getNumBuckets(){return numOfFullBuckets;}
    int getNumEmptyBuckets(){return numOfEmpty;}
    int gettableSize(){return tableSize;}
    int getBucketSize(){return bucketSize;}
    int getNumOfElementsInRows(){return numOfelementinRows;}
};
#endif 