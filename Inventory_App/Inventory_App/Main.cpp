#include <iomanip>
#include <iostream>
#include "Item.h"

int main()
{
    Item* newItem = new Item;
    std::cout << "Item current name: " << newItem->GetName()<< std::endl;
    std::cout << "Item current price: " << std::fixed << std::setprecision(2) << newItem->GetPrice() << std::endl;
    std::cout << "Item current description: " << newItem->GetDesc() << std::endl;

    newItem->SetName("Norman");
    newItem->SetPrice(8.75);
    newItem->SetDesc("He's pretty normal.  What's your excuse?");

    std::cout << "Item current name: " << newItem->GetName() << std::endl;
    std::cout << "Item current price: " << std::fixed << std::setprecision(2) << newItem->GetPrice() << std::endl;
    std::cout << "Item current description: " << newItem->GetDesc() << std::endl;

    std::cout << " ---------------{" << newItem->GetName() << "}---------------" << std::endl;
    std::cout << newItem->GetName() << " Price: " << newItem->GetPrice() << std::endl;
    std::cout << newItem->GetName() << " Description: " << newItem->GetDesc() << std::endl;



    delete newItem;

    std::cin.get();
    return 0;

}