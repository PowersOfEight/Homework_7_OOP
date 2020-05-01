#include "Item.h"

Item::Item()
{
	this->_Previous = NULL;//These set to NULL until they are added to list
	this->_Next = NULL;	   //These set to NULL until they are added to list

	this->_Price = 0.00;//Initialized to prevent warnings :-P
	this->_Name = "";	//Initialized to prevent warnings :-P
	this->_Desc = "";	//Initialized to prevent warnings :-P
}

Item::~Item()
{
	this->_Previous = NULL;
	this->_Next = NULL;
}

std::string Item::GetName()
{
	return this->_Name;
}

void Item::SetName(std::string ItemName)
{
	this->_Name = ItemName;
}

double Item::GetPrice()
{
	return this->_Price;
}

void Item::SetPrice(double price)
{
	this->_Price = price;
}

std::string Item::GetDesc()
{
	return this->_Desc;
}

void Item::SetDesc(std::string Desc)
{
	this->_Desc = Desc;
}

Item* Item::GetNext()
{
	return this->_Next;
}

void Item::SetNext(Item* NextItem)
{
	this->_Next = NextItem;
}

Item* Item::GetPrevious()
{
	return this->_Previous;
}

void Item::SetPrevious(Item* previous)
{
	this->_Previous = previous;
}
