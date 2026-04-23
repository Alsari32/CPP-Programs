#include <iostream>
#include <string>


class RetailItem
{
    private:
        std::string Description;
        int unitsOnHand;
        double price;
        int reorderQuantity;
    //contructors
    public:

       RetailItem()
       {
        Description = " ";
        unitsOnHand = 0;
        price = 0;
        reorderQuantity = 0;
       }

       RetailItem(std::string d,int u,double p,int r)
       {
        Description = d;
        unitsOnHand = u;
        price = p;
        reorderQuantity = r;
       }

        //mutaters
       void setDescription(std::string Description){this ->Description = Description;}
       void setunitsOnHand(int unitsOnHand){this ->unitsOnHand = unitsOnHand;}
       void setprice(double price){this ->price = price;}
       void setreorderQuantity(int reorderQuantity){this -> reorderQuantity=reorderQuantity ;}


       //accessers
       std::string getDescription(){return Description;}
       int getunitsOnHand(){return unitsOnHand;}
       double getprice(){return price;}
       int getreorderQuantity(){return reorderQuantity;}
};




void updateInventory(RetailItem Inventory[], int Count);
void displayReorder(RetailItem Inventory[], int Count);
void checkItem(RetailItem Inventory[], int Count);
void displayItem(RetailItem Inventory[], int Count);
void addItem(RetailItem Inventory[], int &Count, int Max);
/////////////////////////////////////////////
int main()
{

    const int Max=20;
    RetailItem Inventory[Max];
    int Count = 0;
    int choice=0;

    while(choice != 6)
    {
        std::cout<<"        --MENU--";
        std::cout<<"\n1) Add an item to inventory";
        std::cout<<"\n2) Display all items in inventory";
        std::cout<<"\n3) Check to see if an item is in inventory";
        std::cout<<"\n4) Display only those items that need to be re-ordered";
        std::cout<<"\n5) Update an item in inventory";
        std::cout<<"\n6) Exit\n";
        std::cin>>choice;
        std::cin.ignore();
        switch(choice)
        {
            case 1:
                addItem(Inventory,Count ,Max);
                break;
            case 2:
                displayItem(Inventory,Count);
                break;
            case 3:
                checkItem(Inventory,Count);
                break;
            case 4:
                displayReorder(Inventory,Count);
                break;
            case 5:
                updateInventory(Inventory,Count);
                break;
            case 6:
                break;
            default:
            std::cout << "Invalid choice\n";
        }

    }






	return 0;
}
//////////////////////////////////////////////////
//Add item
void addItem(RetailItem Inventory[], int &Count, int Max)
{
    if (Count >= Max)
    {
        std::cout << "Inventory full!\n";
        return;
    }

    std::string desc;
    int units,reorder;
    double price;

    std::cout<<"Enter Item description:  ";
    getline(std::cin, desc);

    std::cout<<"Enter Units on hand:";
    std::cin>>units;

    std::cout<<"Enter price:";
    std::cin>>price;

    std::cout<<"Enter reorder Quantity:";
    std::cin>>reorder;

    Inventory[Count] = RetailItem(desc, units, price, reorder);
    Count++;

    std::cout << "Item added!\n";



}
///////////////////////////////////////////////
//Display item
void displayItem(RetailItem Inventory[], int Count)
{
    std::cout<<"The item is:"<<Inventory[Count-1].getDescription()<<"\nThe units on hand:"<<Inventory[Count-1].getunitsOnHand()
    <<"\nThe price:"<<Inventory[Count-1].getprice()<<"\nThe reorder order quantity:"<<Inventory[Count-1].getreorderQuantity()<<"\n";

}

///////////////////////////////////////////////
//check item
void checkItem(RetailItem Inventory[], int Count)
{
    std::string desc;

    std::cout<<"Enter Item description:  ";
    getline(std::cin, desc);

    for (int i = 0; i < Count; i++)
    {
        if (Inventory[i].getDescription() == desc)
        {
            std::cout << "Item found!\n";
            break;
        }
    }

}

///////////////////////////////////////////////
//Display Reorders
void displayReorder(RetailItem Inventory[], int Count)
{
    for (int i = 0; i < Count; i++)
    {
        if(Inventory[i].getreorderQuantity() == Inventory[i].getunitsOnHand())
        {
            std::cout<<"Reorder this item:"<<Inventory[i].getDescription()<<"\n";
        }
    }


}

///////////////////////////////////////////////
//update Inventory
void updateInventory(RetailItem Inventory[], int Count)
{
    std::string desc;

    std::cout<<"Enter Item description:  ";
    getline(std::cin, desc);


    for (int i = 0; i < Count; i++)
    {
        if (Inventory[i].getDescription() == desc)
        {
            int units,reorder;
            double price;

            std::cout<<"Enter new units:";
            std::cin>>units;

            std::cout<<"Enter new reorder quantity: ";
            std::cin>>reorder;

            std::cout<<"Enter new price: ";
            std::cin>>price;


            Inventory[i].setunitsOnHand(units);
            Inventory[i].setprice(price);
            Inventory[i].setreorderQuantity(reorder);
            std::cout << "Item updated!\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

