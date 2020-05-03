#include "FileIO.h"

FileIO::FileIO()
{
	this->_FileName = "Inventory.txt";
}

FileIO::~FileIO()
{
	this->CloseAll();
}

void FileIO::CloseAll()
{
	if (this->_FileInput.is_open())
	{
		this->_FileInput.close();
	}
	if (this->_FileOutput.is_open())
	{
		this->_FileOutput.close();
	}
}

void FileIO::OpenOutputFile()
{
	this->CloseAll();
	this->_FileOutput.open(this->_FileName, std::ios::app);
}

void FileIO::OpenInputFile()
{
	this->CloseAll();
	this->_FileInput.open(this->_FileName , std::ios::in);
}

int FileIO::countFileLines()
{
	int numberOfLines = -1;
	std::string line;
	CloseAll();
	OpenInputFile();
	if (this->_FileInput.good())
	{
		do
		{
			getline(this->_FileInput, line);
			numberOfLines++;
		} while (!this->_FileInput.eof());
	}
	this->_FileInput.close();
	if (numberOfLines < 0)
	{
		numberOfLines = 0;
	}
	return numberOfLines;
}

void FileIO::TruncateFile()
{
	this->CloseAll();
	this->_FileOutput.open(this->_FileName, std::ios::trunc);
	this->_FileOutput.close();
}

Inventory* FileIO::CreateInvFromFile()
{
	Inventory* inventory = new Inventory;
	int numberOfLines = countFileLines();
	Item* item = NULL;
	std::string nameLine;
	std::string trashLine;
	std::string descLine;
	double priceLine = 0.00;
	CloseAll();
	OpenInputFile();
	while (numberOfLines > 0)
	{
		item = new Item;
		getline(this->_FileInput, nameLine);
		item->SetName(nameLine);
		this->_FileInput >> priceLine;
		item->SetPrice(priceLine);
		getline(this->_FileInput, trashLine);
		getline(this->_FileInput, descLine);
		item->SetDesc(descLine);
		inventory->AddItemToBack(item);
		numberOfLines = numberOfLines - 3;
	}
	this->_FileInput.close();
	return inventory;
}

void FileIO::WriteInventoryToFile(Inventory* inventory)
{
	TruncateFile();
	OpenOutputFile();
	if (inventory->GetFirst() == NULL)
	{
		return;
	}
	Item* currentPointer = inventory->GetFirst();
	do
	{
		this->_FileOutput << currentPointer->GetName() << std::endl;
		this->_FileOutput << currentPointer->GetPrice() << std::endl;
		this->_FileOutput << currentPointer->GetDesc() << std::endl;
		currentPointer = currentPointer->GetNext();
	}while (currentPointer != NULL);
	this->_FileOutput.close();
	std::cout << "Inventory saved to file!" << std::endl;
}

void FileIO::AddItemToFile(Item* item)
{
	CloseAll();
	OpenOutputFile();
	this->_FileOutput << item->GetName() << std::endl;
	this->_FileOutput << item->GetPrice() << std::endl;
	this->_FileOutput << item->GetDesc() << std::endl;
	this->_FileOutput.close();
}

