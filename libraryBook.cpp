#include <iostream>

//Library book class

class LibraryBook
{
    private:
        std::string  title,author;
        int pageCount,copiesAvailabe,checkOutLimit;


    public:
        //constructers
        LibraryBook()
        {
            title = author = " ";
            pageCount = copiesAvailabe = checkOutLimit=0;
        }

        LibraryBook(std::string t,std::string a,int p, int c, int cl)
        {
            title = t;
            author = a;
            pageCount = p;
            copiesAvailabe = c;
            checkOutLimit = cl;
        }
        //mutaters

        void setTitle(std::string ti){title = ti;}
        void setAuthor(std::string auth){author = auth;}
        void setPageCount(int pageC){pageCount = pageC;}
        void setCopiesAvailabe(int copiesA){copiesAvailabe = copiesA;}
        void setCheckOutLimit(int COL){checkOutLimit = COL;}

};


// Proto Type

void addBook(LibraryBook books[]);


// Main function
int main()
{
    //constructer
    LibraryBook libraryBook1("The board", "Mutasem Alsari", 300,150,10);

    //user Menu
    int userSelection;
    const int Max=15;
    LibraryBook books[Max];

    while(userSelection > 6 || userSelection < 1)
    {
        std::cout<<"1. Add a book to the library";
        std::cout<<"\n2. Display all book in the library";
        std::cout<<"\n3. Search for a book by title";
        std::cout<<"\n4. Display only those books that need more copies requested";
        std::cout<<"\n5. Check out a book";
        std::cout<<"\n6. Exit:";
        std::cin>>userSelection;

        switch(userSelection)
        {
            case 1:
                addBook(books);
                break;
            case 2:
                //displayBook();
                break;
            case 3:
                //searchBook();
                break;
            case 4:
                //copiesReq();
                break;
            case 5:
                //checkOut();
                break;
            case 6:
                break;
            default:
                std::cout<<"Wrong input!!";
                continue;

        }
    }


    return 0;
}

//function for adding a book
void addBook(LibraryBook books[])
{
    int x = 0;
    std::string title,author;
    int pageCount,copiesAvailabe,checkOutLimit;

    std::cout<<"Enter the book title: ";
    std::cin>>title;
    books[x].setTitle(title);

    std::cout<<"Enter the author name: ";
    std::cin>>author;
    books[x].setAuthor(author);

    std::cout<<"Enter the page count: ";
    std::cin>>pageCount;
    books[x].setPageCount(pageCount);

    std::cout<<"Enter the copies availabe: ";
    std::cin>>copiesAvailabe;
    books[x].setCopiesAvailabe(copiesAvailabe);

    std::cout<<"Enter the book title: ";
    std::cin>>checkOutLimit;
    books[x].setCheckOutLimit(checkOutLimit);

    x++;

}

