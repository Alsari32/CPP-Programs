#include <iostream>
#include<string>

//Waseem Alawamleh
//Mutasem alsari
class Car{
	private:

		int year;
	    std::string make;
	    std::string model;
	    int speed;
	    double gallons;


	 public:
	//constructor
	    Car (int y, std::string ma, std::string m){

	     	 speed=0;
	      	 gallons=10;
	     	 year=y;
	         make=ma;
	         model=m;
		 }
    	//Accessors
    	int getyear(){return year;}
    	std::string getmake(){return make;}
        std::string getmodel(){return model;}
    	int getspeed(){return speed;}
    	double getgallons(){return gallons;}
    	int getSpeed(){return speed;}


		 //Mutator

        void accelerate() {
		 	speed += 5;
			gallons -= 0.5;
			if (gallons < 0) gallons = 0;

		}
		void brake()
		{
		    speed -= 5;
			gallons -= 0.2;
			if (gallons < 0) gallons = 0;
			if (speed < 0) speed = 0;

		}

		void fillUP() {
			  gallons += 5;
			  if (gallons > 22) gallons = 22;

		}
     	void startCar() {
         bool isOn = true;
        }

	   void shutOff()
	    {
			bool isOn = false;
		}



};

int main() {
	Car car1(2024, "Toyota", "Camry");

	car1.accelerate();
	car1.brake();
	car1.fillUP();
	car1.startCar();
	car1.shutOff();




	return 0;
}



