#include "UserI0.h"

UserIO::UserIO()
{
	this->_Selection = _MenuState::Main;
	this->_SelectedItem = NULL;
}

UserIO::~UserIO()
{
	this->_SelectedItem = NULL;
}

void UserIO::PrintInventory(Inventory* inventory)
{
	if (inventory->GetCount() <= 0)
	{
		std::cout << "----------------[EMPTY]----------------" << std::endl;
		return;
	}
	Item* currentItem = inventory->GetFirst();
	for (int i = 0; i < inventory->GetCount(); i++)
	{
		std::cout << "----------------[Item " << i+1 << "]----------------" << std::endl;
		std::cout << "Name: " << currentItem->GetName() << std::endl;
		std::cout << "Price: " << currentItem->GetPrice() << std::endl;
		std::cout << "Description: " << currentItem->GetDesc() << std::endl;
		std::cout << currentItem->GetName() << " current *Next: " << currentItem->GetNext() << std::endl;
		std::cout << currentItem->GetName() << " current *Previous: " << currentItem->GetPrevious() << std::endl;
		std::cout << currentItem->GetName() << " address: " << currentItem << std::endl;
		if (currentItem->GetNext() != NULL)
		{
			currentItem = currentItem->GetNext();
		}
	}


}

void UserIO::AddItem(Inventory* thisInventory)
{
	Item* newItem = new Item;
	double x = 0.00;
	std::string line;
	std::string descLine;
	std::cout << "Enter item: ";
	getline(std::cin, line);
	newItem->SetName(line);
	std::cout << "Enter price for " << newItem->GetName() << ":  ";
	while (!(std::cin >> x))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl << "[ERROR] - Please enter a NUMBER for price" << std::endl;
		std::cout << "Enter price for " << newItem->GetName() << ":  ";
	}
	newItem->SetPrice(x);
	std::cout << "Enter description for " << newItem->GetName() << ":  ";
	std::cin.ignore();
	getline(std::cin, descLine);
	newItem->SetDesc(descLine);
	thisInventory->AddItemToBack(newItem);

}

void UserIO::SortItems(Inventory* inventory)
{
	SortBot* sortBot = new SortBot;
	sortBot->BubbleSort(inventory);
	delete sortBot;
}


void UserIO::MainMenu(Inventory* thisInventory) 
{
	
	std::string userSelection = "";

	while (this->_Selection == _MenuState::Main)
	{
		std::cout << "Type [add] to add new item to inventory" << std::endl;
		std::cout << "Type [print] to print a list of items in inventory" << std::endl;
		std::cout << "Type [sort] to sort inventory" << std::endl;
		std::cout << "Type [exit] to exit application" << std::endl;

		getline(std::cin, userSelection);

		if ((userSelection == "add") || (userSelection == "Add"))
		{
			this->_Selection = _MenuState::Add;
		}
		if ((userSelection == "print") || (userSelection == "Print"))
		{
			this->_Selection = _MenuState::Print;
		}
		if ((userSelection == "sort") || (userSelection == "Sort"))
		{
			this->_Selection = _MenuState::Sort;
		}
		if ((userSelection == "exit") || (userSelection == "Exit"))
		{
			this->_Selection = _MenuState::Exit;
		}
		switch (this->_Selection)
		{
		case _MenuState::Add:
			this->AddItem(thisInventory);
			break;
		case _MenuState::Print:
			this->PrintInventory(thisInventory);
			break;
		case _MenuState::Sort:
			this->SortItems(thisInventory);
			break;
		case _MenuState::Exit:
			std::cout << "Goodbye" << std::endl;
			break;
		}
		if (this->_Selection != _MenuState::Exit)
		{
			this->_Selection = _MenuState::Main;
		}
	}
}

