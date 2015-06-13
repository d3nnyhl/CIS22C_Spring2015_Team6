#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <fstream>

using namespace std;

template<class ItemType>
class Hash
{
private:
    static const int tableSize = 31;                //rows
    static const int bucketSize = 3;                //columns
    ItemType *hashTable[tableSize][bucketSize];
    int count;
    int numOfFullBuckets;
    int numOfEmpty;
    int numOfelementinRows;
public:
	//constructor
    Hash();
    
	//hash generator
	int hashGenerator(string _id);
    
	void addItem(string _id,string _name ,string _model ,double _memory ,int _apps ,int _songs,ofstream &outfile);
    void printTable();
    void printHashT();
    bool findKey(string _id);
    
    //getters
	int getCount(){return count;}
    int getNumBuckets(){return numOfFullBuckets;}
    int getNumEmptyBuckets(){return numOfEmpty;}
    int gettableSize(){return tableSize;}
    int getBucketSize(){return bucketSize;}
    int getNumOfElementsInRows(){return numOfelementinRows;}
};
//****************************************************************
// This is the consrtuctor of the hash table, it sets the strings
// to 'empty' and the int and double to 0
//**************************************************************
template<class ItemType>
Hash<ItemType>::Hash()
{
    count = 0;
	numOfFullBuckets = 0;
	numOfEmpty = (tableSize * (bucketSize-1));
	numOfelementinRows = 0;
	for (int i = 0; i < tableSize; i++)
    {
        for(int j = 0; j < bucketSize; j++)
        {
            hashTable[i][j] = new ItemType;
            hashTable[i][j]->setID("empty");
            hashTable[i][j]->setName("empty");
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
void Hash<ItemType>::addItem(string _id,string _name, string _model, double _memory, int _apps, int _songs,ofstream &outfile)
{
    int index = hashGenerator(_id);
    int w = 0;
    
    while (hashTable[index][w]->getID() != "empty" && w < bucketSize){
        w++;
	}
    
    if (w < bucketSize)
    {
        hashTable[index][w]->setID(_id);
        hashTable[index][w]->setName(_name);
        hashTable[index][w]->setModel(_model);
        hashTable[index][w]->setMemory(_memory);
	    hashTable[index][w]->setApps(_apps);
		hashTable[index][w]->setSongs(_songs);
        
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
        outfile << "ID    : " << _id << endl;
        outfile << "name  : " << _name << endl;
        outfile << "model : " << _model << endl;
        outfile << "memory: " << _memory << endl;
		outfile << "apps  : " << _apps << endl;
		outfile << "songs : " << _songs << endl << endl;
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
            if (hashTable[i][j]->getID() != "empty")
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
			cout << "      songs  : " << hashTable[i][0]->getSongs() << endl << endl;
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
			cout << "      songs  : " << hashTable[i][j]->getSongs() << endl << endl;
            }
        }
    }
}

//****************************************************************
// This function inputs a user input, to search if it is in table
//****************************************************************
template<class ItemType>
bool Hash<ItemType>::findKey(string _id)
{
    int index = hashGenerator(_id);
    int w =0;
    bool foundit = false;
    
    if (_id == "Q" || _id == "q")
    {
        cout << "Now exiting search" << endl << endl;
        return true;
    }
            // check if element is in index 0
	if(hashTable[index][0]->getID() == _id)
    {
        cout << "Item found: " << endl;
        cout << "      ID     : " << hashTable[index][0]->getID() << endl;
        cout << "      name   : " << hashTable[index][0]->getName() << endl;
        cout << "      model  : " << hashTable[index][0]->getModel() << endl;
        cout << "      memory : " << hashTable[index][0]->getMemory() << endl;
	    cout << "      apps   : " << hashTable[index][0]->getApps() << endl;
		cout << "      songs  : " << hashTable[index][0]->getSongs() << endl << endl;
        foundit = true;
        return true;
    }
    if (foundit == false){
        w++;
	}
	// look to the buckets to see in there is a match
    while ( w < (bucketSize-1) && hashTable[index][w]->getID() != _id )
    {
        if (w < 2)
            w++;
    }
  
	// print if match is found
	if(hashTable[index][w]->getID() == _id)
    {
        cout << "Item found: " << endl;
        cout << "      ID     : " << hashTable[index][w]->getID() << endl;
        cout << "      name   : " << hashTable[index][w]->getName() << endl;
        cout << "      model  : " << hashTable[index][w]->getModel() << endl;
        cout << "      memory : " << hashTable[index][w]->getMemory() << endl;
	    cout << "      apps   : " << hashTable[index][w]->getApps() << endl;
		cout << "      songs  : " << hashTable[index][w]->getSongs() << endl << endl;
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
int Hash<ItemType>::hashGenerator(string _id)
{
    int hash = 0;
    int index = 0;
    
    // 6 because key only consists of 6 characters in the toys name
    
    for (int i = 0; i < 6; i++){
        hash = hash + (int)_id[i];
	}

    index = hash % tableSize;
    return index;
}

#endif 