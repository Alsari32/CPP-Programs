#include <iostream>
#include <string>

class Author
{
  private:
    std::string firstName,lastName;
    char middleInital;
  
  public:
    
  Author(std::string f,std::string l, char mi)
  {
      firstName = f;
      lastName = l;
      middleInital = mi;
  }
  void display() 
  {
      std::cout<<"last Name, First Name,Middle initial.(e.g."<<firstName<<","<<lastName<<" "<<middleInital<<".)";
  }
};


class Publisher
{
  private:
    std::string name,city;

     
  public:
    
   Publisher(std::string n, std::string c)
   {
       name = n;
       city = c;
   }
   
   void display()
   {
       std::cout<<"Publisher Name, City.(e.g."<<name<<","<<city<<".)";
   }
}; 


class Book
{
  private:
    Author author;
    Publisher publisher;
    std::string name,isbn;
    int year,edition;
    
  public:
    
    Book(Author a,std::string n,int ed, Publisher p,int y,std::string i)
        :author(a), publisher(p)
    {
        name = n;
        edition = ed;
        year = y;
        isbn = i;
    }
    
    void display()
    {
       author.display();
       std::cout << name << ", " << edition << "rd ed. ";
       publisher.display();
       std::cout << year << ". ISBN: " << isbn << ".";
        
    }
        
    
};


int main()
{
    Author author1("Jones","jacob",'D');
    
    
    Publisher publisher1("Pearson","New York");
    
    
    Book book1(author1,"A Simple Guide to Building BookShelves",3,publisher1,2019,"123-45,678910");
    book1.display();
    
    return 0;
}