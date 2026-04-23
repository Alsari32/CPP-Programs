#include <iostream>

int main()
{
    int Qty;
    int *QtyPtr;

    Qty=10;
    QtyPtr=&Qty;

    std::cout<<*QtyPtr;
    *QtyPtr = 22;
    std::cout<<*QtyPtr;

    float amt=1.99,price=2.99;
    float *const amtPtr=&amt;

    std::cout<<"\n"<<*amtPtr;
    *amtPtr=5.99;
    std::cout<<"\n"<<*amtPtr;

    //amtPtr=&price;
    std::cout<<"\n"<<*amtPtr;


    return 0;
}
