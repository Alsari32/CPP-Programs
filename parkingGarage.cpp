#include <iostream>
#include <cmath>
int main()
{
    double parkingTime;
    char userSelection;
    double garageFee= 2.50;

    while(true)
    {
        std::cout<<"Enter the time you have parked: ";
        std::cin>>parkingTime;
        
        if(std::cin.fail())
        {
    
        	std::cout << "Your answer must be numeric\n";
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            continue;
		}
		if (parkingTime > 24 ||parkingTime < 0 )
        {
            std::cout << "Error: cannot park more than 24 hours or less then 0\n";
            continue;
        }
		
		if (parkingTime <= 3)
        {
            garageFee = 2.50;
        }
        else
        {
            double extraHours = ceil(parkingTime - 3); // round up partial hours
            garageFee = 2.50 + extraHours * 1.00;
        }
        if (garageFee > 20.00)
        {
            garageFee = 20.00;
        }
	
	
		std::cout<<"Your parking fee is:"<<garageFee;
		
		
		std::cout<<"\nWould you like to continue (Y/N)";
        std::cin>>userSelection;
        
        if(userSelection == 'N' || userSelection == 'n')
        {
        	break;
		}
        	
        


    }

    return 0;
}
