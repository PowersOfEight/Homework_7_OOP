#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
class Inventory
{
	Item* _First;
	Item* _Last;
	int _Count;


public:
	Inventory();
	~Inventory();
	
	Item* GetFirst();
	Item* GetLast();
	int GetCount();
	void AddCount();
	
	void SetFirstItem(Item*);
	void SetLastItem(Item*);

	void AddFirstItem(Item*);
	
	void AddItemToFront(Item*);
	void AddItemToBack(Item*);
	void RemoveItem(Item*);
};
#endif // !INVENTORY_H
