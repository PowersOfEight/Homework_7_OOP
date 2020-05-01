#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item
{
	

	std::string _Name;
	double _Price;
	std::string _Desc;

	//List Pointers
	Item* _Next;
	Item* _Previous;
	//Position bool
	bool ThisIsFirst;
	bool ThisIsLast;

public:
	Item();
	~Item();

	std::string GetName();
	void SetName(std::string);
	
	double GetPrice();
	void SetPrice(double price);

	std::string GetDesc();
	void SetDesc(std::string);

	Item* GetNext();
	void SetNext(Item*);

	Item* GetPrevious();
	void SetPrevious(Item*);
};
#endif // !ITEM_H

