#include "hash.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//****************************************************************
// This is the consrtuctor of the hash table, it sets the strings
// to 'empty' and the int and double to 0
//**************************************************************
template<class ItemType>
Hash<ItemType>::Hash()
{
    for (int i = 0; i < tableSize; i++)
    {
        for(int j = 0; j < bucketSize; j++)
        {
            hashTable[i][j] = new ItemType;
            hashTable[i][j]->setID("empty");
            hashTable[i][j]->setName(0);
            hashTable[i][j]->setModel("empty");
            hashTable[i][j]->setMemory(0);
			hashTable[i][j]->setApps(0);
			hashTable[i][j]->setSongs(0);
        }
    }
}

//**************************************************************
// This function uses the hash function to generate an index,
// and places the item where the it belongs in the hash table
// If the buckets are full the item is printed to a file
//**************************************************************
template<class ItemType>
void Hash<ItemType>::addItem(string id,string name, string model, double memory, int apps, int songs)
{
    int index = hashGenerator(id);
    int w = 0;
    
    while (hashTable[index][w]->getKey() != "empty" && w < bucketSize)
        w++;
    
    if (w < bucketSize)
    {
        hashTable[index][w]->setID(id);
        hashTable[i][j]->setName(name);
        hashTable[i][j]->setModel(model);
        hashTable[i][j]->setMemory(memory);
	    hashTable[i][j]->setApps(apps);
		hashTable[i][j]->setSongs(songs);
        
        if (w == 2)
            numOfFullBuckets++;
        if(w==1 || w==2)
            count++;
        if(w == 0)
            numOfelementinRows++;
        if(w > 0)
            numOfEmpty = numOfEmpty - 1;   
    }
    else
    {
        cout << "Error: Item rejected" << endl ;
        outfile << "----Rejected Item----" << endl;
        outfile << "ID    : " << id << endl;
        outfile << "name  : " << name << endl;
        outfile << "model : " << model << endl;
        outfile << "memory: " << memory << endl;
		outfile << "apps  : " << apps << endl;
		outfile << "songs : " << songs << endl << endl;
    }
}

//**************************************************************
// This function prints every item in the table
//**************************************************************
template<class ItemType>
void Hash<ItemType>::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        for(int j =0; j < bucketSize; j++)
        {
            if (hashTable[i][j]->getKey() != "empty")
            {
                cout << "ID    :" << hashTable[i][j]->getID() << endl;
                cout << "name  : " << hashTable[i][j]->getName() << endl;
                cout << "model : " << hashTable[i][j]->getModel() << endl;
                cout << "memory: " << hashTable[i][j]->getMemory() << endl;
				cout << "apps  : " << hashTable[i][j]->getApps() << endl;
				cout << "songs : " << hashTable[i][j]->getSongs() << endl << endl;
            }
        }
    }
}

//**************************************************************
// this function prints the table and shows which are synonyms
//**************************************************************
template<class ItemType>
void Hash<ItemType>::printHashT()
{
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i][0]->getID()=="empty" )
        {
            cout << "Index: " << i << endl;
            cout << "     -This index is empty" << endl << endl ;
        }
        else
        {
            cout << "Index: " << i << endl;
            cout << "      ID     : " << hashTable[i][0]->getID() << endl;
            cout << "      name   : " << hashTable[i][0]->getName() << endl;
            cout << "      model  : " << hashTable[i][0]->getModel() << endl;
            cout << "      memory : " << hashTable[i][0]->getMemory() << endl;
			cout << "      apps   : " << hashTable[i][0]->getApps() << endl;
			cout << "      songs  : " << hashtable[i][0]->getSongs() << endl << endl;
        }
        for(int j =1; j < bucketSize; j++)
        {
            if (hashTable[i][j]->getID() != "empty" )
            {
            cout << "      ID     : " << hashTable[i][j]->getID() << endl;
            cout << "      name   : " << hashTable[i][j]->getName() << endl;
            cout << "      model  : " << hashTable[i][j]->getModel() << endl;
            cout << "      memory : " << hashTable[i][j]->getMemory() << endl;
			cout << "      apps   : " << hashTable[i][j]->getApps() << endl;
			cout << "      songs  : " << hashtable[i][j]->getSongs() << endl << endl;
            }
        }
    }
}

//****************************************************************
// This function inputs a user input, to search if it is in table
//****************************************************************
template<class ItemType>
bool Hash<ItemType>::findKey(string key)
{
    int index = hashGenerator(key);
    int w =0;
    bool foundit = false;
    
    if (key == "Q" || key == "q")
    {
        cout << "Now exiting search" << endl << endl;
        return true;
    }
            // check if element is in index 0
    if (hashTable[index][0]->getID() == key)
    {
        cout << "Item found: " << endl;
        cout << "      ID     : " << hashTable[index][0]->getID() << endl;
        cout << "      name   : " << hashTable[index][0]->getName() << endl;
        cout << "      model  : " << hashTable[index][0]->getModel() << endl;
        cout << "      memory : " << hashTable[index][0]->getMemory() << endl;
	    cout << "      apps   : " << hashTable[index][0]->getApps() << endl;
		cout << "      songs  : " << hashtable[index][0]->getSongs() << endl << endl;
        foundit = true;
        return true;
    }
    if (foundit == false)
        w++;

	// look to the buckets to see in there is a match
    while ( w < (bucketSize-1) && hashTable[index][w]->getKey() != key )
    {
        if (w < 2)
            w++;
    }
    
	// print if match is found
    if(hashTable[index][w]->getID() == key )
    {
        cout << "Item found: " << endl;
        cout << "      ID     : " << hashTable[index][w]->getID() << endl;
        cout << "      name   : " << hashTable[index][w]->getName() << endl;
        cout << "      model  : " << hashTable[index][w]->getModel() << endl;
        cout << "      memory : " << hashTable[index][w]->getMemory() << endl;
	    cout << "      apps   : " << hashTable[index][w]->getApps() << endl;
		cout << "      songs  : " << hashtable[index][w]->getSongs() << endl << endl;
        foundit = true;
        return true;
    }
    
    if (foundit == false)
        cout << "Error: Item not found" << endl << endl;

    return false;
}


//**************************************************************
// This function takes the first 6 letters of the string and
// adds them up to create an index
//**************************************************************
template<class ItemType>
int Hash<ItemType>::hashGenerator(string key)
{
    int hash = 0;
    int index = 0;
    
    // 6 because key only consists of 6 characters in the toys name
    
    for (int i = 0; i<6; i++)
        hash = hash + (int)key[i];
    
    index = hash % tableSize;
    return index;
}
