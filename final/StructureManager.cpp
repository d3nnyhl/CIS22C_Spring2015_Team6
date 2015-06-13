#include "StructManager.h"

StructManager::StructManager(int itemCount, void (*display)(CellPhone & item))
{
	//hash_Table = new Hash<CellPhone>();
	main_BST= new BinarySearchTree<CellPhone>();
	printItem = display;
	//arraySize = tableSize;
}

//**************************************************************
//  This function builds the hash table and the BSTs.
//
//**************************************************************

void StructManager::buildList(CellPhone* phone)
{
	main_BST->insert(*phone);
}

//**************************************************************
//  This function displays the main menu
//
//**************************************************************

void StructManager::displayMenu()
{

	cout << "Cellphone Database Menu" << endl;
	cout << "-------------------------" << endl;
	cout << " A : Add new Data" << endl;
	cout << " D : Delete Data" << endl;
	cout << " S : Search Data" << endl;
	cout << " L : List Data" << endl;
	cout << " W : Write to file" << endl;
	cout << " T : Statistics" << endl;
	cout << " Q : Quit" << endl;
	cout << "-------------------------" << endl;

}

//**************************************************************
// This function manages the Main Menu
//
//**************************************************************

void StructManager::menuManager()
{
	displayMenu();

	char choice;
	bool repeatMenu = true;


	while (repeatMenu == true)
	{
		switch (choice = getLetter())
		{
		case 'A':
			cout << "Add data here" << endl << endl;
			break;

		case 'D':
			cout << "Delete data" << endl << endl;
			break;

		case 'S':
			//cout << " Search submenu " << endl << endl;
			searchSubMenu();
			break;

		case 'L':
			//cout << "show list submenu" << endl << endl;
			listSubMenu();
			break;

		case 'W':
			cout << "Write to file" << endl << endl;
			break;

		case 'M':
			displayMenu();
			cout << endl;
			break;

		case 'T':
			cout << "statistics" << endl << endl;
			break;

		case 'Q':
			cout << "quit" << endl << endl;
			repeatMenu = false;
			break;

		default:
			cout << endl;
			cout << "--- error: invalid input ---" << endl;
			cout << "Push M to see the menu" << endl;
			cout << endl;
			break;
		}
	}
}

//**************************************************************
// This function retrieves a letter to use for the submenu's
//
//**************************************************************
int StructManager::getNum()
{
	string entry;
	int num = 3;
	bool isNum = false;

	while (isNum == false)
	{

		cout << "Please enter a [number]!" << endl;
		cin >> entry;
		cin.ignore();


		if (isdigit(entry[0]))
		{
			num = entry[0] - 48;
			isNum = true;
		}
		else
		{
			cout << "-- error: invalid entry --" << endl << endl;
		}
	}

	return num;
}

//**************************************************************
// This function retrieves a letter for main menu
//
//**************************************************************
char StructManager::getLetter()
{
	string choice;
	char letter;

	cout << "Please enter a [character]!" << endl;

	cin >> choice;
	cin.ignore();

	letter = toupper(choice[0]);
	cout << endl;

	return letter;

}
//**************************************************************
// this function manages the search sub menu
//
//**************************************************************
void StructManager::searchSubMenu()
{
	int choice;
	bool repeatMenu = true;

	cout << "   Search Submenu" << endl;
	cout << "   ---------------------------" << endl;
	cout << "   1 : Search by Primary Key" << endl;
	cout << "   2 : Search by Secondary Key" << endl;
	cout << "   3 : To see Sub-menu again" << endl;
	cout << "   0 : Quit" << endl << endl;


	while (repeatMenu == true)
	{

		switch (choice = getNum())
		{
		case 1:
			cout << "Search by Primary Key" << endl << endl;
			// if found repeatMenu = false
			// if not found repeatMenu = true
			break;

		case 2:
			cout << "Search by Secondary Key" << endl << endl;
			// if found repeatMenu = false
			// if not found repeatMenu = true
			break;

		case 3:
			cout << "   Search Submenu" << endl;
			cout << "   ---------------------------" << endl;
			cout << "   1 : Search by Primary Key" << endl;
			cout << "   2 : Search by Secondary Key" << endl;
			cout << "   3 : To see sub-menu again" << endl;
			cout << "   0 : Quit" << endl << endl;
			break;

		case 0:
			cout << "Now quitting search" << endl << endl;
			repeatMenu = false;
			break;

		default:
			cout << "-- error: invalid input--" << endl;
			cout << " enter 3 to see submenu again" << endl;
			break;
		}
	}

}
//**************************************************************
// This function manages the list sub menu
//
//**************************************************************
void StructManager::listSubMenu()
{
	int choice;
	bool repeatMenu = true;

	cout << "   List Submenu" << endl;
	cout << "   ---------------------------" << endl;
	cout << "   1 : List Unsorted" << endl;
	cout << "   2 : List Sorted by Primary key" << endl;
	cout << "   3 : List Sorted by Secondary key" << endl;
	cout << "   4 : special print: indented list" << endl;
	cout << "   5 : Print submenu again" << endl;
	cout << "   0 : quit" << endl << endl;

	while (repeatMenu == true)
	{

		switch (choice = getNum())
		{
		case 1:
			cout << "list unsorted" << endl << endl;
			break;

		case 2:
			cout << "Cell Phones sorted by Primary Key" << endl << endl;
			cout << "FCC ID - Make - Model - Memory - Apps - Songs\n";
			main_BST->inOrder(printItem);
			break;

		case 3:
			cout << "sorted secondary key" << endl << endl;
			break;

		case 4:
			cout << "indented list" << endl << endl;
			break;

		case 5:

			cout << "   List Submenu" << endl;
			cout << "   ---------------------------" << endl;
			cout << "   1 : List Unsorted" << endl;
			cout << "   2 : List Sorted by Primary key" << endl;
			cout << "   3 : List Sorted by Seconday key" << endl;
			cout << "   4 : special print: indented list" << endl;
			cout << "   5 : Print submenu again" << endl;
			cout << "   0 : quit" << endl << endl;
			break;


		case 0:
			cout << "now quiting list" << endl << endl;
			repeatMenu = false;
			break;

		default:
			cout << "-- error: invalid input--" << endl;
			cout << " enter 5 to see submenu again" << endl << endl;
			break;
		}
	}

}

///*
//Determine the hash table size.
//Takes the initial amount of items in the file and divides it by
//the default load factor. Then, finds the next prime number and returns it.
//*/
//int StructManager::determineHashSize(int fileCount)
//{
//	return nextPrime(fileCount / DEFAULT_LOAD_FACTOR));
//
//}

StructManager::~StructManager()
{
	delete main_BST;
}