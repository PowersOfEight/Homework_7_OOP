#pragma once
#ifndef SORT_H
#define SORT_H
#include "Inventory.h"

class SortBot
{
	Item* _High;
	Item* _Low;

public:
	SortBot();
	~SortBot();

	Item* GetHigh();
	Item* GetLow();

	void SetHigh(Item*);
	void SetLow(Item*);

	void SwitchItem(Inventory*, Item*, Item*);
	void BubbleSort(Inventory*);
};
#endif // !SORT_H
