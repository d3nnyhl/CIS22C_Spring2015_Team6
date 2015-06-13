// Binary Search Tree ADT
// Created by Frank M. Carrano and Tim Henry.
// Modified by:	Denny Hung Liang
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"


template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{   
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
   
	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode<ItemType> * _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success);
   
	// delete target node from tree, called by internal remove node
	BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);
   
	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType & successor);
   
	// search for target node
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType & target) const;

	//search for leftmost node
	BinaryNode<ItemType>* findSmallest(BinaryNode<ItemType>* treePtr) const;
	//search for rightmost node
	BinaryNode<ItemType>* findLargest(BinaryNode<ItemType>* treePtr) const;

	// print within range
	void _printRange(void visit(ItemType&), BinaryNode<ItemType>* nodePtr, ItemType &lowLimit, ItemType &highLimit, bool &isSuccess) const;
   
public:  
	// insert a node at the correct location
    bool insert(const ItemType & newEntry);
	// remove a node if found
	bool remove(const ItemType & anEntry);
	// find a target node
	bool getEntry(const ItemType & target, ItemType & returnedItem) const;
	// print within range
	bool printRange(void visit(ItemType&), ItemType & lowLimit, ItemType & highLimit) const;
	// get largest item
	bool getLargest(ItemType & returnedItem) const;
	// get smallest item
	bool getSmallest(ItemType & returnedItem) const;
 
};


///////////////////////// public function definitions ///////////////////////////

/*
	Public Insert
*/
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	rootPtr = _insert(rootPtr, newNodePtr); 
	count++;
	return true;
}  

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
	bool isSuccessful = false;
	rootPtr = _remove(rootPtr, target, isSuccessful);
	if (isSuccessful)
		count--;
	return isSuccessful; 
}  

//returns true if entry is found; returns item by reference.
//returns false if not found
template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
	BinaryNode<ItemType>* isFound = findNode(rootPtr, anEntry);
	if (isFound){
		returnedItem = isFound->getItem();
		return true;
	}
	return false;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::printRange(void visit(ItemType&), ItemType & lowLimit, ItemType & highLimit) const
{
	bool isSuccessful = false;
	_printRange(visit, rootPtr, lowLimit, highLimit, isSuccessful);
	return isSuccessful;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::getLargest(ItemType & returnedItem) const
{
	BinaryNode<ItemType>* largest = findLargest(rootPtr);
	if (largest){
		returnedItem = largest->getItem();
		return true;
	}
	return false;
}
// get smallest item
template<class ItemType>
bool BinarySearchTree<ItemType>::getSmallest(ItemType & returnedItem) const
{
	BinaryNode<ItemType>* smallest = findSmallest(rootPtr);
	if (smallest){
		returnedItem = smallest->getItem();
		return true;
	}
	return false;
}

//////////////////////////// private functions ////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
	if (nodePtr == 0)
		return newNodePtr;
	else if (nodePtr->getItem() > newNodePtr->getItem())
	{
		nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
	}
	else
	{
		nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
	}
	return nodePtr;
}  

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType target,
                                                          bool & success)
{
	if (nodePtr == 0)                   
	{
		success = false;
		return 0;
	}
	if (nodePtr->getItem() > target)		 
		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
	else if (nodePtr->getItem() < target)	 
		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
	else		
	{
		nodePtr = deleteNode(nodePtr);
		success = true;
	}      
	return nodePtr;   
}  

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())				
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)  
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0) 
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;      
	}
	else                                  
	{
		ItemType newNodeValue;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}  
}  

template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		successor = nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else 
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}       
}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType & target) const 
{
	if (nodePtr == 0)
		return 0;
	else if (nodePtr->getItem() == target)
		return nodePtr;
	else if (nodePtr->getItem() > target)
		return findNode(nodePtr->getLeftPtr(), target);
	else
		return findNode(nodePtr->getRightPtr(), target);
}  

template<class ItemType>
void BinarySearchTree<ItemType>::_printRange(void visit(ItemType &), BinaryNode<ItemType>* nodePtr,
											ItemType &lowLimit, ItemType &highLimit, bool &isSuccess) const
{	
	if (nodePtr == 0)
		return;
	if (nodePtr->getItem() > lowLimit)
		_printRange(visit, nodePtr->getLeftPtr(), lowLimit, highLimit, isSuccess);

	if (nodePtr->getItem() >= lowLimit && nodePtr->getItem() <= highLimit){
		visit(nodePtr->getItem());
		isSuccess = true;
	}	
	if (nodePtr->getItem() < highLimit)
		_printRange(visit, nodePtr->getRightPtr(), lowLimit, highLimit, isSuccess);
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findLargest(BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr->getRightPtr() == 0)
		return nodePtr;
	return findLargest(nodePtr->getRightPtr());
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findSmallest(BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr->getLeftPtr() == 0)
		return nodePtr;
	return findSmallest(nodePtr->getLeftPtr());
}

#endif
