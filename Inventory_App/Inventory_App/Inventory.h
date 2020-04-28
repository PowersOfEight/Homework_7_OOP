#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
class Inventory
{
	Item* _First;
	Item* _Last;


public:
	Inventory();
	~Inventory();

	void GetFirst(Item);

};


#endif // !INVENTORY_H
