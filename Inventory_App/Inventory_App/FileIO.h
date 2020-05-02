#pragma once
#ifndef FILEIO_H
#define FILEIO_H
#include "Inventory.h"
#include <fstream>

class FileIO
{
	std::string _FileName;
	std::ifstream _FileInput;
	std::ofstream _FileOutput;

public:

	FileIO();
	~FileIO();

	void CloseAll();
	void OpenOutputFile();
	void OpenInputFile();

	int countFileLines();

	void TruncateFile();

	Inventory* CreateInvFromFile();
	//still need to write inventory to file, and need to integrate this with the menu


};











#endif // !FILEIO_H
