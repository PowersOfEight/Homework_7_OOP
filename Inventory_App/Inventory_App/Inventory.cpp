#include "Inventory.h"

Inventory::Inventory()
{
	_First = NULL;
	_Last = NULL;
	_Count = 0;
}

Inventory::~Inventory()
{
	_First = NULL;
	_Last = NULL;
}

Item* Inventory::GetFirst()
{
	return _First;
}

Item* Inventory::GetLast()
{
	return _Last;
}

int Inventory::GetCount()
{
	return this->_Count;
}

void Inventory::AddCount()
{
	_Count++;
}

void Inventory::SetFirstItem(Item* thisItem)
{
	this->_First = thisItem;
	thisItem->SetPrevious(NULL);
}

void Inventory::SetLastItem(Item* thisItem)
{
	this->_Last = thisItem;
	thisItem->SetNext(NULL);
}

void Inventory::AddFirstItem(Item* thisItem)//to run if no item had been added
{
	if ((this->_First != NULL) || (this->_Last != NULL) || (this->_Count != 0))
	{
		std::cout << "[ERROR] - AddFirstItem(Item*) run while Inventory previously instantiated.  Line 44 Inventory.cpp" << std::endl;
		return;
	}
	this->SetFirstItem(thisItem);
	this->SetLastItem(thisItem);
	this->_Count++;
}

void Inventory::AddItemToFront(Item* thisItem)
{
	if ((this->_First == NULL) && (this->_Last == NULL) && (this->_Count == 0))
	{
		this->AddFirstItem(thisItem);
		return;
	}

	if (this->_First != NULL)//If first is not NULL, we must remove our pointer from that entry
	{
		this->_First->SetPrevious(thisItem);
		thisItem->SetNext(this->_First);
		//this->_First->SetToFirst(false);
	}

	this->SetFirstItem(thisItem);
	//this->_First = thisItem;
	//thisItem->SetToFirst(true);
	this->_Count++;
}

void Inventory::AddItemToBack(Item* thisItem)
{
	if ((this->_First == NULL) && (this->_Last == NULL) && (this->_Count == 0))
	{
		this->AddFirstItem(thisItem);
		return;
	}

	if (this->_Last != NULL)//If last is not NULL, we must remove our pointer from that entry and change it's status
	{
		this->_Last->SetNext(thisItem);
		thisItem->SetPrevious(this->_Last);
	}
	this->SetLastItem(thisItem);
	this->_Count++;
}

void Inventory::RemoveItem(Item* thisItem)
{
	
	if (thisItem == NULL)
	{
		std::cout << "[ERROR] - RemoveItem(NULL) - Inventory.cpp line 101" << std::endl;
		return;
	}
	if (thisItem->GetPrevious() == NULL)
	{
		if (thisItem->GetNext() != NULL)
		{
			this->SetFirstItem(thisItem->GetNext());
			thisItem->SetNext(NULL);
			thisItem->SetPrevious(NULL);
		}
		//thisItem->SetToFirst(false);
	}
	if (thisItem->GetNext() == NULL)
	{
		if (thisItem->GetPrevious() != NULL)
		{
			this->SetLastItem(thisItem->GetPrevious());
			thisItem->SetPrevious(NULL);
			thisItem->SetNext(NULL);
		}
		//thisItem->SetToLast(false);
	}
	if ((thisItem->GetPrevious() != NULL) && (thisItem->GetNext() != NULL))//check on this, did this run?
	{
		thisItem->GetPrevious()->SetNext(thisItem->GetNext());
		thisItem->GetNext()->SetPrevious(thisItem->GetPrevious());
		thisItem->SetPrevious(NULL);
		thisItem->SetNext(NULL);
	}

	this->_Count--;

}

