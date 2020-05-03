#include <iomanip>
#include <iostream>
#include "Item.h"
#include "Inventory.h"
#include "UserI0.h"
#include "Sort.h"
#include "FileIO.h"

int main()
{


    FileIO* FileBot = new FileIO;
    UserIO* Console = new UserIO;
    Inventory* inventory = FileBot->CreateInvFromFile();
    Console->MainMenu(inventory, FileBot);

    delete Console;
    delete FileBot;
    delete inventory;

    std::cin.get();
    return 0;
}