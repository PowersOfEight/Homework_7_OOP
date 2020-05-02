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
	do
	{
		getline(this->_FileInput, line);
		numberOfLines++;
	} while (!this->_FileInput.eof());
	this->_FileInput.close();
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
	Item* item;
	std::string line;
	double priceLine = 0.00;
	CloseAll();
	OpenInputFile();
	while (numberOfLines > 0)
	{
		item = new Item;
		getline(this->_FileInput, line);
		item->SetName(line);
		this->_FileInput >> priceLine;
		item->SetPrice(priceLine);
		getline(this->_FileInput, line);
		getline(this->_FileInput, line);
		item->SetDesc(line);
		inventory->AddItemToBack(item);
		numberOfLines = numberOfLines - 3;
	}
	this->_FileInput.close();
	delete item;
	return inventory;
}

