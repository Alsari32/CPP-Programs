//vectors

#include <iostream>
#include <vector>

int main()
{
    int temp[5];

    std::vector<int> temps;
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity();

//    temps[0]=55;here it was empty

    temps.push_back(55);//like an array but its doesnt have a size just memory and push back is to add something
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";

    temps.push_back(66);
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";


    temps.push_back(77);
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";

    temps.push_back(88);
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";


    temps.push_back(99);
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";


    temps[0]=22;//we can do this now because we have data in that index
    for(int x = 0; x< temps.size(); x++)
    {
        std::cout<<temps[x]<<" ";
    }

    temps.pop_back();
    std::cout<<std::endl;
    for(int x = 0; x< temps.size(); x++)
    {
        std::cout<<temps[x]<<" ";
    }
    std::cout<<"\nSize:"<<temps.size()<<" Capacity:"<<temps.capacity()<<"\n";

    std::cout<<"\nRange based for loop / enhanced for loop\n";

    for(int oneTemp : temps)
        std::cout<<oneTemp<<" ";

    std::cout<<std::endl;

    for(int& oneTemp : temps)//we use refrenace to change the actual value for oneTemp
    {
        oneTemp*= 10;
        std::cout<<oneTemp<<" ";
    }
    std::cout<<std::endl;
    for(int oneTemp : temps)
        std::cout<<oneTemp<<" ";

    return 0;
}
