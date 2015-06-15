#ifndef HASH_H
#define HASH_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

const int BUCKET_SIZE = 3;

template <class ItemType, class KeyType>
class Hash
{
private:
	//vector<vector<ItemType>> list;	                    // Vector of vectors to represent buckets.
	vector<ItemType> *list;
	int tableSize;
	int itemCount;										// Number of items in the hash table.
	int collision;
	vector<ItemType> overflow_Area;
public:
	//HashTable(int size) { list.resize(size); }
	Hash(int size) { tableSize = size;  list = new vector<ItemType>[size]; collision = 0; }
	int getCount() { return itemCount; }
	void printTable(void print(ItemType &anItem));
	void printHashT(void print(ItemType &anItem));
	bool hash_insert(int getHash(const KeyType &id, const int &size), ItemType *item);
	bool hash_search(int getHash(const KeyType &id, const int &size), const ItemType &returnItem);		// Needs parameter with item to be searched.
	//	bool hash_delete(const ItemType &item);
};

template<class ItemType, class KeyType>
bool Hash<ItemType, KeyType>::hash_insert(int getHash(const KeyType &id, const int &size), ItemType* item)
{
	int index = getHash(item->getID(), tableSize);
	if (list[index].empty())
		list[index].push_back(*(item));
	else if (list[index].size() < BUCKET_SIZE)
	{
		list[index].push_back(*(item));
		collision++;
	}
	else if (list[index].size() == BUCKET_SIZE)
	{
		overflow_Area.push_back(*(item));
		collision++;
	}

	return true;
}

template<class ItemType, class KeyType>
bool Hash<ItemType, KeyType>::hash_search(int getHash(const KeyType &id, const int &size), const ItemType &returnItem)
{
	//not implemented.
	/*int index = getHash(item->getID(), tableSize);
	if (list[index].empty())
		return false;
	for (int num = 0; num < list[index].size(); num++)
	{
		if ()
	}
		*/
	return true;
}

//**************************************************************
// This function prints every item in the table
//**************************************************************
template<class ItemType, class KeyType>
void Hash<ItemType, KeyType>::printTable(void print(ItemType &anItem))
{
	for (int i = 0; i < tableSize; i++)
	{
		if (!list[i].empty())
		{
			for (int j = 0; j < list[i].size(); j++)
			{
				print(list[i][j]);
			}
		}
	}

	//print overflow area next
}

//**************************************************************
// this function prints the table and shows which are synonyms
//**************************************************************
template<class ItemType, class KeyType>
void Hash<ItemType, KeyType>::printHashT(void print(ItemType &anItem))
{
	for (int i = 0; i < tableSize; i++)
	{
		if (list[i].empty())
		{
			cout << "Index: " << i << endl;
			cout << "     -This index is empty" << endl << endl;
		}
		else
		{
			cout << "Index: " << i << endl;
			print(list[i][0]);
		}
		for (int j = 1; j < list[i].size(); j++)
		{
			cout << setw(8);
			print(list[i][j]);
		}
	}

	//print overflow area next

	cout << "Number of collisions: " << collision << endl;
}



//template<class ItemType, class KeyType>
//bool Hash<ItemType, KeyType>::hash_delete(int getHash(const KeyType &id, const int &size), ItemType* item, const ItemType & returnItem)
//{
//	int index = getHash(item->getID(), tableSize);
//
//}

#endif 