#include <iostream>


class Pet//we have accessors which lets us see and mutators which lets us change
{   private:
            std::string type;
            std::string name;
            int age;

    public:
        //contructors
        Pet()
        {
            type="unknown";
            name="unknown";
            age=0;

        }

         //mutators
         void setType(std::string t){this -> type = t;}
         void setName(std::string n){name=n;}
         void setAge(int x){age=x;}
         //accessors
         std::string getType() {return type;}
         std::string getName() {return name;}
         int getAge() {return age;}

         Pet(std::string t,std::string n,int x)
         {
             type=t;
             name=n;
             age=x;
         }




};

int main()
{
    Pet mypet;
    Pet yourpet;

    Pet theirpet("bird","Tweety",15);

    mypet.setType("Dog");
    mypet.setName("strider");
    mypet.setAge(5);

   std::cout<<"My "<<mypet.getType()<<" "<<mypet.getName()<<" is " <<mypet.getAge();

    yourpet.setType("cat");
    yourpet.setName("jake");
    yourpet.setAge(3);

    std::cout<<"\n My "<<yourpet.getType()<<" "<<yourpet.getName()<<" is " <<yourpet.getAge();

    std::cout<<"\n My "<<theirpet.getType()<<" "<<theirpet.getName()<<" is " <<theirpet.getAge();

 return 0;
}
