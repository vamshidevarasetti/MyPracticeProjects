#include <iostream>
using namespace std;


int main()
{
    const int a =10;
    const int* p1 = &a;

    int *p2 = const_cast<int*> (p1);
    *p2 = 20;

    cout<<a<<endl;
    cout<<*p2<<endl;

    cout<<&a<<endl;
    cout<<p2<<endl;

    return 0;

}