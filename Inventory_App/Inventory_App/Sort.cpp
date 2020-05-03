#include "Sort.h"

SortBot::SortBot()
{
	this->_High = NULL;
	this->_Low = NULL;
}

SortBot::~SortBot()
{
	this->_High = NULL;
	this->_Low = NULL;	
}

Item* SortBot::GetHigh()
{
	return this->_High;
}

Item* SortBot::GetLow()
{
	return this->_Low;
}

void SortBot::SetHigh(Item* item)
{
	this->_High = item;
}

void SortBot::SetLow(Item* item)
{
	this->_Low = item;
}

void SortBot::SwitchItem(Inventory* inventory, Item* left, Item* right)
{
	if (left == right)
	{
		std::cout << "[ERROR] - Both items in the Sort::SwitchItem(Item* left, Item* right) are the same" << std::endl;
		return;
	}
	if (left == inventory->GetFirst())//Our test to see if it's the first in the list
	{
		//if the left item is first in the list, we can cheat by removing the right, then adding it to the front
		inventory->RemoveItem(right);
		inventory->AddItemToFront(right);
		return;
	}
	if (right == inventory->GetLast())
	{
		//likewise, if the right item is the last in the inventory, we can remove the item and add it to the back
		inventory->RemoveItem(left);
		inventory->AddItemToBack(left);
		return;
	}
	//the only other case is to exchange this remove the item on the left, and place it in between 
	inventory->RemoveItem(left);
	left->SetNext(right->GetNext());
	left->GetNext()->SetPrevious(left);
	left->SetPrevious(right);
	right->SetNext(left);
	
	
	inventory->AddCount();// to offset the remove item

}

void SortBot::BubbleSort(Inventory* inventory)
{	
	if (inventory->GetCount() < 2)
	{
		std::cout << "Not enough entries to sort.  Please try again." << std::endl;
		return;
	}
	Item* currentPointer = NULL;
	Item* nextPointer = NULL;
	int changesThisTurn = 0;
	int goRound = 0;
	bool advanced = false;
	do
	{
		goRound = 0;
		changesThisTurn = 0;
		currentPointer = inventory->GetFirst();
		while (currentPointer->GetNext() != NULL)
		{
			if ((goRound != 0) && (!advanced))
			{
				currentPointer = currentPointer->GetNext();
			}
			if (currentPointer->GetNext() != NULL)
			{
				nextPointer = currentPointer->GetNext();
			}
			advanced = false;
			if (currentPointer->GetPrice() > nextPointer->GetPrice())
			{
				this->SwitchItem(inventory, currentPointer, nextPointer);
				advanced = true;
				changesThisTurn++;
			}
			goRound++;
		} 
	} while (changesThisTurn != 0);


}
