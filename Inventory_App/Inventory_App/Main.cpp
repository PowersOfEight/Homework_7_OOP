#include <iomanip>
#include <iostream>
#include "Item.h"
#include "Inventory.h"



void doThingsAndStuff()
{
    Item* newItem = new Item;
    std::cout << "Item current name: " << newItem->GetName() << std::endl;
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
}





int main()
{
    //doThingsAndStuff();
    Item* myItem = new Item;
    myItem->SetName("Alpha");
    myItem->SetPrice(20.00);
    myItem->SetDesc("The current first");

    Item* myItem2 = new Item;
    myItem2->SetName("Omega");
    myItem2->SetPrice(9.99);
    myItem2->SetDesc("The current last");

    Item* myItem3 = new Item;
    myItem3->SetName("After Omega");
    myItem3->SetPrice(17.76);
    myItem3->SetDesc("This one will be added to back");


    Inventory* myInventory = new Inventory;
    myInventory->AddItemToBack(myItem);

    std::cout << "First Item name: " << myInventory->GetFirst()->GetName() << std::endl;
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetFirst()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetFirst()->GetDesc() << std::endl;
    std::cout << "Items in inventory before AddItemToBack(): " << myInventory->GetCount() << std::endl;

    std::cout << "Last Item name: " << myInventory->GetLast()->GetName() << std::endl;
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetLast()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetLast()->GetDesc() << std::endl;

    myInventory->AddItemToFront(myItem2);
    myInventory->AddItemToBack(myItem3);
    std::cout << std::endl << std::endl;
    
    std::cout << "First Item name: " << myInventory->GetFirst()->GetName() << std::endl;
    if (myInventory->GetFirst()->IsThisFirst())
    {
        std::cout << "Is this first is true for " << myInventory->GetFirst()->GetName() << std::endl;
    }

    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetFirst()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetFirst()->GetDesc() << std::endl;

    std::cout << "Second Item name: " << myInventory->GetFirst()->GetNext()->GetName() << std::endl;
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetFirst()->GetNext()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetFirst()->GetNext()->GetDesc() << std::endl;


    std::cout << "Last Item name: " << myInventory->GetLast()->GetName() << std::endl;
    if (myInventory->GetLast()->IsThisLast())
    {
        std::cout << "Is This Last set to true for " << myInventory->GetLast()->GetName() << std::endl;
    }
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetLast()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetLast()->GetDesc() << std::endl;

    std::cout << "Items in inventory after AddItemToBack(): " << myInventory->GetCount() << std::endl;

    myInventory->RemoveItem(myInventory->GetLast());
    myInventory->RemoveItem(myInventory->GetLast());

    std::cout << std::endl << std::endl;

    std::cout << "First Item name: " << myInventory->GetFirst()->GetName() << std::endl;
    if (myInventory->GetFirst()->IsThisFirst())
    {
        std::cout << "Is this first is true for " << myInventory->GetFirst()->GetName() << std::endl;
    }
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetFirst()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetFirst()->GetDesc() << std::endl;
    



    std::cout << "Last Item name: " << myInventory->GetLast()->GetName() << std::endl;
    if (myInventory->GetLast()->IsThisLast())
    {
        std::cout << "Is This Last set to true for " << myInventory->GetLast()->GetName() << std::endl;
    }
    std::cout << "Item price: " << std::fixed << std::setprecision(2) << myInventory->GetLast()->GetPrice() << std::endl;
    std::cout << "Item description: " << myInventory->GetLast()->GetDesc() << std::endl;
    std::cout << "Current items in inventory count is " << myInventory->GetCount() << std::endl;


    delete myItem;
    delete myItem2;
    delete myItem3;
    delete myInventory;

    std::cin.get();
    return 0;
}