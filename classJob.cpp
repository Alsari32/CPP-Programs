#include <iostream>

class Job
{
    friend int operator+(int num, Job aJob); // declaration only, no body

    private:
        int jobNum;
        int hours;
        float rate;

    public:
        Job(int jn, int h, float r)
        {
            jobNum = jn;
            hours  = h;
            rate   = r;
        }

        float getRate() { return rate; }

        int operator+(int num)
        {
            return hours + num;
        }

        float operator+(float num)
        {
            return rate + num;
        }

        void operator=(int num)
        {
            jobNum=num;
        }
        void operator=(Job j)
        {
            this->hours=j.hours;
            this->rate=j.rate;
        }
        bool operator>(Job j)
        {
            return (hours * rate) > (j.hours * j.rate);

        }


};

int operator+(int num, Job aJob) { return num + aJob.hours; } // definition here

int main()
{
    Job jobA(111, 10, 10.50);
    Job jobB(222, 20, 20.50);
    Job jobC(0,0,0);

    std::cout << jobA + 5          << " ";  // 15
    std::cout << jobA.operator+(5) << " ";  // 15
    std::cout << jobA + 5.25F      << " ";  // 15.75
    std::cout << jobA.getRate()    << "\n"; // 10.50
    std::cout << jobB + 5          << " ";  // 25
    std::cout << jobB + 10 + jobA;          // 45

    jobC=333;
    jobC = jobA;

    if(jobA > jobB)
        std::cout<<"\nJob A cost more!";
    else
        std::cout<<"\nJob B cost more!";

    return 0;
}
