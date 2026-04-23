#include <iostream>
#include <iomanip>
#include <vector>
//====================== Student class  ======================
class Student
{
    private:
        std::string firstName;
        std::string lastName;
        int grade;
        double totalFee;

    public:
        //================ non defualt constructor ========
        Student(std::string firstName,std::string lastName, int grade)
        :firstName(firstName),lastName(lastName),grade(grade)
        {
            totalFee = 0;
        }
        //======================= overload operators =======================

        Student& operator+=(double fee){totalFee+=fee;return *this;}

        friend std::ostream& operator<<(std::ostream& os, const Student& m);

        bool operator ==(std::string lastName){return this ->lastName == lastName;}
        bool operator ==(int grade){return this -> grade == grade;}

};
std::ostream& operator<<(std::ostream& os, const Student& m) {

	os << std::fixed << std::setprecision(2);
    os << "\nGrade     : " << m.grade
       << "\nName      : " << std::left << std::setw(20) << (m.firstName + " " + m.lastName)
       << "\nTotal Fees: $" << std::right << std::setw(8) << m.totalFee << "\n";
    return os;
}

//============================= Athlete Class =======================
class Athlete
{
    private:
        std::string firstName;
        std::string lastName;
        std::string sport;
        static double athleteFee;//static means the athleticFee is shared across all Athlete objects — there is only one copy of it in memory regardless of how many athletes are created.

    public:
        //============ non defualt constructor

        Athlete(std::string firstName,std::string lastName,std::string sport)
        :firstName(firstName),lastName(lastName),sport(sport)
        {
        }
        //=================== overload operators
        friend std::ostream& operator<<(std::ostream& os, const Athlete& m);

        bool operator==(std::string sport){return this -> sport == sport;}

        //Accessor

        double getAthleteFee(){return athleteFee;}



};
double Athlete::athleteFee=125.50;
std::ostream& operator<<(std::ostream& os, const Athlete& m)
{
    os << std::fixed << std::setprecision(2);
    os << "\nSport: " << m.sport<<"\nName: "<< std::left << std::setw(20) << (m.firstName + " " + m.lastName);
    return os;
}
//====================== prototype
void displayStudentsBySport(std::vector<Athlete> &allAthlete);
void displayStudentsByGrade(std::vector<Student> &allStudent);
void displayAthletes(std::vector<Athlete> &allAthlete);
void displayOneStudent(std::vector<Student> &allStudent);
void displayStudents(std::vector<Student> &allStudent);
void addStudent(std::vector<Student> &allStudent,std::vector<Athlete> &allAthlete);
int displayMenu();

//================= main function ==================
int main()
{
    std::vector<Student> allStudent;
    std::vector<Athlete> allAthlete;
    int answer=0;



    while(answer != 7)
    {
        answer = displayMenu();
        switch(answer)
        {
            case 1:
                addStudent(allStudent,allAthlete);
                break;
            case 2:
                displayStudents(allStudent);
                break;
            case 3:
                displayOneStudent(allStudent);
                break;
            case 4:
                displayAthletes(allAthlete);
                break;
            case 5:
                displayStudentsByGrade(allStudent);
                break;
            case 6:
                displayStudentsBySport(allAthlete);
                break;


        }
    }

    return 0;
}
//============================= display student by sport
void displayStudentsBySport(std::vector<Athlete> &allAthlete)
{
    if(allAthlete.empty())
    {
        std::cout<<"\n No student enrolled\n";
        return;
    }
    std::cin.clear();
    std::cin.ignore(100,'\n');

    std::string sport;

    std::cout<<"Enter the sport you would like to see displayed: ";
    std::getline(std::cin,sport);

    bool found = false;

    for(int x = 0; x<allAthlete.size(); x++)
    {
        if(allAthlete[x] == sport)
        {
            std::cout<<allAthlete[x];
            found = true;
        }
        if(!found)
            std::cout<<"Sport not found";

    }

}

//=============================Display students by grade
void displayStudentsByGrade(std::vector<Student> &allStudent)
{
    if(allStudent.empty())
    {
        std::cout<<"\n No student enrolled\n";
        return;
    }
    int grade;


    std::cout<<"Enter the grade you would like to see displayed: ";
    std::cin>>grade;

    bool found = false;

    for(int x = 0; x<allStudent.size();x++)
    {
        if(allStudent[x] == grade)
        {
            std::cout<<allStudent[x];
            found = true;
        }
        if(!found)
            std::cout<<"grade not found";


    }

}


//===========================display all athletes
void displayAthletes(std::vector<Athlete> &allAthlete)
{
    if(allAthlete.empty())
    {
        std::cout<<"\nNo athletes are enrolled.";
        return;
    }

    for(int x = 0; x<allAthlete.size();x++)
    {
        std::cout<<allAthlete[x];

    }
}

//===========================display info and total fee by last name
void displayOneStudent(std::vector<Student> &allStudent)
{
    if(allStudent.empty())
    {
        std::cout<<"\n No student enrolled\n";
        return;
    }
    std::string lastName;

    std::cout<<"\nEnter last name to search: ";
    std::cin>>lastName;

    bool found = false;

    for(int x = 0; x<allStudent.size();x++)
    {
        if(allStudent[x] == lastName)
        {
            std::cout<<allStudent[x];
            found = true;
        }
    }
    if(!found)
        std::cout<<"\n Student not found";


}

//===========================display students ================
void displayStudents(std::vector<Student> &allStudent)
{
    if(allStudent.empty())
    {
        std::cout<<"\nNo student enrolled\n";
        return;
    }

    for(Student x:allStudent)
    {
        std::cout<<x;
    }

}

//========================== add student function ====================
void addStudent(std::vector<Student> &allStudent,std::vector<Athlete> &allAthlete)
{
    std::string firstName,lastName,sport;
    int grade;
    char choice;

    std::cout<<"\nEnter student first name:";
    std::cin>>firstName;

    std::cout<<"\nEnter student last name:";
    std::cin>>lastName;

    std::cout<<"\nEnter student grade:";
    std::cin>>grade;

    while(std::cin.fail() ||grade < 9 || grade > 12)
    {
        std::cin.clear();
        std::cin.ignore(100,'\n');

        std::cout<<"\nInvalid input try again";
        std::cout<<"\nEnter student grade:";
        std::cin>>grade;
    }


    Student newStudent(firstName, lastName, grade);

    std::cout<<"\nDo you play a sport(y/n)";
    std::cin>>choice;

    while (choice == 'y' || choice == 'Y') {
        std::cin.ignore();
        std::cout << "Enter sport name: ";
        std::getline(std::cin, sport);


        allAthlete.push_back(Athlete(firstName, lastName, sport));

        newStudent += allAthlete.back().getAthleteFee();

        std::cout << "Does this student play another sport? (y/n): ";
        std::cin >> choice;

    }
    allStudent.push_back(newStudent);

}
//========================= display menu function =================
int displayMenu()
{
    int answer;

    std::cout<<"\nPlease choose from the menu";
    std::cout<<"\n1: Add student";
    std::cout<<"\n2: Print a list of enrolled students";
    std::cout<<"\n3: Print a list of students by last name";
    std::cout<<"\n4: Print a list of students who play sports";
    std::cout<<"\n5: Print a list of students by grade";
    std::cout<<"\n6: Print a list of students by sport";
    std::cout<<"\n7: Exit program ";


    while(true)
    {
        std::cin>>answer;

        if(answer <=7 && answer >= 1)
        {
            return answer;
        }
        std::cout<<"\ninvalid input try again:\n";
        std::cin.clear();
    }

}
