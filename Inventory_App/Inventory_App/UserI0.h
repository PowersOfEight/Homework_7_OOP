#pragma once
#ifndef USERIO_H
#define USERIO_H
#include "Inventory.h"
#include "Sort.h"
#include <iomanip>
#include "FileIO.h"
class UserIO
{

	enum _MenuState
	{
		Main,
		Add,
		Sort,
		Print,
		Exit
	};
	_MenuState _Selection;
	Item* _SelectedItem;

public:
	UserIO();
	~UserIO();
	
	void PrintInventory(Inventory*);
	void AddItem(Inventory*, FileIO*);
	void SortItems(Inventory*, FileIO*);
	void MainMenu(Inventory*, FileIO*);
};
#endif // !USERIO_H

