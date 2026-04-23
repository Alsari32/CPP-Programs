#include <iostream>


class Food
{
 private:
    std::string name;
    int calories,protein,carbs,fat;

 public:

     //contructors
     Food()
     {
         name = "Unknown";
         calories=protein=carbs=fat=0;

     }

     Food(std::string n)
     {
         name = n;
         calories=0;
         protein=0;
         carbs=0;
         fat=0;

     }

     Food(std::string n,int c,int p,int ca,int f)
     {
         name = n;
         calories = c;
         protein = p;
         carbs = ca;
         fat = f;

     }

     //mutat
     void setName(std::string n){name = n;}
     void setProtein(int p){protein = p;}
     void setCalories(int c){calories = c;}
     void setCarbs(int ca){carbs = ca;}
     void setFat(int f){fat = f;}

     //acc
    std::string getName() {return name;}
    int getCalories() {return calories;}
    int getProtein() {return protein;}
    int getCarbs(){return carbs;}
    int getFat(){return fat;}

};
void displayOneMeal(Food allMeal[3]);
int main()
{
    //contructors
    Food food1;
    Food food2("Apple");
    Food food3("chicken",300,30,20,15);

    //mutaturs
    food3.setName("meat");
    food3.setProtein(20);
    food3.setCalories(100);
    food3.setCarbs(30);
    food3.setFat(10);

    //acc
    std::cout<<"Food name: "<<food3.getName()<<".Calories "<<food3.getCalories()<<".protien " <<food3.getProtein()<<".carbs"<<food3.getCarbs()<<".Fat"<<food3.getFat();

    Food meal1;
    Food meal2("pizza");
    Food meal3("bbq chicken",540,34,54,23);

    Food allMeals[3];

    allMeals[0] = meal1;
    allMeals[1] = meal2;
    allMeals[2] = meal3;

    displayAllMeal(allMeals);



    return 0;
}

void displayAllMeal(Food allMeals[3])
{
    for(int x = 0; x<3; x++)
    {
        std::cout<<oneMeal[x].display();

    }
}
