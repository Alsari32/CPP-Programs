#include <iostream>
#include <vector>
class Animal
{
    private:
        int age;

    public:

        virtual void says()=0;//abstract
        void setAge(int a){age = a;}
        int getAge(){return age;}

};

//=============== dog class
class Dog:public Animal //inherinte from animal
{
    public:
        void says()
        {
            std::cout<<"\nWoof woof";
        }

};

class Cat:public Animal //inherinte from animal
{
    public:
        void says()
        {
            std::cout<<"\nMeooo";
        }

};


//===protype
void saySomething(Animal *a);
//====main function
int main()
{
    std::vector<Animal *> allAnimals;

    //Animal oneAnimal;
    Dog myDog;
    Cat yourCat;

    //oneAnimal.says();
    myDog.says();
    yourCat.says();

    //saySomething(&oneAnimal);
    saySomething(&myDog);
    saySomething(&yourCat);


    return 0;

}
//dynamic binding

void saySomething(Animal *a)
{
    a->says();
    a->setAge(5);
    std::cout<<"\nAge is "<< a->getAge();
}
