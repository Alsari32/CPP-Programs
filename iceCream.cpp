#include <iostream>
#include <cmath>

int main()
{
	std::string flavors[5]={"vanilla","butter pecan","superman","chocolate fudge","strabarry"};
	int scopes[5]={0,0,0,0,0};
	int total=0;
	
	for(int x=0;x<5;x++)
	{
		std::cout<<"Enter the number of scopes for the "<<flavors[x]<<":";
		std::cin>>scopes[x];
		total +=scopes[x]; 
	}
	
	//Display
	std::cout<<"Total scopes for the month: "<<total<<'\n';
	for(int i=0;i<5;i++)
	{
		std::cout<<flavors[i]<<":"<<scopes[i]<<'\n';
	}
	int maxScoops = scopes[0];
    for (int i = 1; i < 5; i++) {
        if (scopes[i] > maxScoops) {
            maxScoops = scopes[i];
        }
    }
    std::cout<<"The best selling ice cream is: ";
    
    for(int x=0;x<5;x++)
    {
    	if(scopes[x] == maxScoops)
    	{
    		std::cout << flavors[i] << " ";
		}
	}
    
	
	
	
	return 0;
}
