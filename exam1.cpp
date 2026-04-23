#include <iostream>
#include <string>
#include <vector>
class Habitat
{
    private:
        std::string habitatName;
        std::string climate;
        int temperature;

    public:

        //constructor
        Habitat(std::string habitatName,std::string climate,int temperature)
        :habitatName(habitatName),climate(climate),temperature(temperature)
        {
        }
        //accusseros
        std::string getHabitatName(){return habitatName;}
        std::string getClimate(){return climate;}
        int getTemperature(){return temperature;}


        std::string getString()
        {
            return habitatName + " - " + climate + " - " + std::to_string(temperature) + "F";
        }
};

//==================== zoo animal class

class ZooAnimal
{
    private:
        std::string name;
        std::string species;
        int age;
        Habitat allHabitat;
        std::string category;
        bool fur;
        bool fly;
        bool coldBlooded;
        std::string favFood;
        double wingSpan;
        std::string skin;

    public:

        ZooAnimal(std::string name,std::string species,int age,Habitat allHabitat,std::string category)
        :name(name),species(species),age(age),allHabitat(allHabitat),category(category)
        {
            fur = false;
            fly = false;
            coldBlooded = false;
            favFood = "unknown ";
            wingSpan = 0;
            skin = "unknown ";

        }
        ZooAnimal()
        :allHabitat("unknown", "unknown", 0)
        {
            name = "unknown";
            species = "unknown";
            age = 0;
            category = "unknown";
            fur = false;
            fly = false;
            coldBlooded = false;
            favFood = "unknown";
            wingSpan = 0;
            skin = "unknown";
        }

        //Accessors

        std::string getName(){return name;}
        std::string getSpecies(){return species;}
        std::string getCategory(){return category;}

        std::string feed()
        {
            if(category == "Mammal"){return "The Zookeeper feeds" + name + "the mammal diet of" + favFood;}
            if(category == "Bird"){return "The Zookeeper feeds" + favFood + "seeds and fruit.";}
            if(category == "Reptile"){return "The Zookeeper feeds" + name + "in the reptile habitat.";}
            return "The Zookeeper feeds " + name + " its daily meal.";
        }
        void display()
        {
            std::cout<<"\n=== "<<species <<"===";
            std::cout<<"\nName:"<<name;
            std::cout<<"\nAge:"<<age;
            std::cout<<"\n"<<allHabitat.getString();

            if(category == "Mammal")
            {
                std::cout<<"Has fur:"<<fur;
                std::cout<<"Has fur:"<<favFood;
            }

            if(category == "Bird")
            {
                std::cout<<"Can fly:"<<fly;
                std::cout<<"Wingspan:"<<wingSpan<<" feet";
            }

            if(category == "Reptile")
            {
                std::cout<<"Cold Blooded:"<<coldBlooded;
                std::cout<<"Skin type:"<<skin;
            }

        }

        //overload operator

        void operator =(std::string category)
        {
            if(category == "Mammal")
            {
                std::cout<<"Does the animal have fur (1 for true, 0 for false): ";
                std::cin>>fur;

                std::cin.clear();
                std::cin.ignore(100,'\n');

                std::cout<<"Enter their favorite food:";
                std::getline(std::cin,favFood);
            }

            if(category == "Bird")
            {
                std::cout<<"Can the animal fly (1 for true, 0 for false): ";
                std::cin>>fly;

                std::cout<<"Enter wingspan:";
                std::cin>>wingSpan;
            }

            if(category == "Reptile")
            {
                std::cout<<"Is the animal Cold blooded (1 for true, 0 for false): ";
                std::cin>>coldBlooded;

                std::cout<<"Enter skin type: ";
                std::cin>>skin;
            }

        }

        friend std::ostream& operator<<(std::ostream& os,  ZooAnimal& m);

};
std::ostream& operator<<(std::ostream& os,  ZooAnimal& m)
{

    m.display();

	os <<"\n"<<" Category: "<<m.category<< "\n"<< "Feeding Action: "<<m.feed();

	return os;
}
//========== protoype
int countAnimals(std::vector<ZooAnimal> allZooAnimal,int catergoyCount);
void enterAnimalData(std::vector<ZooAnimal> &allZooAnimal);
//main funciton
int main()
{
    Habitat savannah("Savannah Zone", "Warm and grassy", 85);
    Habitat rainforest("Rainforest Dome", "Humid and tropical", 78);
    Habitat aviary("Aviary", "Flying enclosure", 72);
    Habitat desert("Desert Habitat", "Hot and dry", 95);

    std::vector<ZooAnimal> allZooAnimal;

    allZooAnimal.push_back(ZooAnimal("Leo", "Lion", 5, savannah, "Mammal"));
    allZooAnimal.push_back(ZooAnimal("Ella", "Elephant", 12, savannah, "Mammal"));
    allZooAnimal.push_back(ZooAnimal("Rio", "Macaw", 3, aviary, "Bird"));
    allZooAnimal.push_back(ZooAnimal("Ozzy", "Owl", 4, rainforest, "Bird"));
    allZooAnimal.push_back(ZooAnimal("Sly", "Snake", 6, desert, "Reptile"));
    allZooAnimal.push_back(ZooAnimal("Tank", "Turtle", 40, rainforest, "Reptile"));

    enterAnimalData(allZooAnimal);

    int catergoyCount;
    std::cout<<"Enter a category to count (1-Mammal, 2-Bird, 3-Reptile): ";
    std::cin>>catergoyCount;

    while(catergoyCount < 1 || catergoyCount > 3)
    {
        std::cout<<"Invalid input";
        std::cout<<"Enter a category to count (1-Mammal, 2-Bird, 3-Reptile): ";
        std::cin>>catergoyCount;
    }

    for(int x = 0; x<allZooAnimal.size();x++)
    {
        allZooAnimal[x].display();
    }

    int total = countAnimals(allZooAnimal,catergoyCount);

    std::string selectedCategory = "";
    switch (catergoyCount)
    {
        case 1: selectedCategory = "mammals";  break;
        case 2: selectedCategory = "birds";    break;
        case 3: selectedCategory = "reptiles"; break;
    }
    std::cout << "\nNumber of " << selectedCategory << ": " << total << "\n";



    return 0;
}
//==================animal count
int countAnimals(std::vector<ZooAnimal> allZooAnimal,int catergoyCount)
{
    std::string selectedCategory = "";
    switch (catergoyCount)
    {
        case 1: selectedCategory = "Mammal";  break;
        case 2: selectedCategory = "Bird";    break;
        case 3: selectedCategory = "Reptile"; break;
    }

    // For loop counts how many animals match the selected category
    int count = 0;
    for (int i = 0; i < allZooAnimal.size(); i++)
    {
        if (allZooAnimal[i].getCategory() == selectedCategory)
            count++;
    }

    return count;


}

//===============enter animal data
void enterAnimalData(std::vector<ZooAnimal> &allZooAnimal)
{
    for(ZooAnimal& animal  : allZooAnimal)
    {
        std::cout<<"\nName:"<<animal .getName();
        std::cout<<"\nSpecies:"<<animal .getSpecies();
        std::cout<<"\nCategory:"<<animal .getCategory()<<"\n";

        animal  = animal.getCategory();
    }

}
