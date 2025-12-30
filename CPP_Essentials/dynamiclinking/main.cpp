#include <iostream>
using namespace std; 
extern "C" int my_add(int, int);
extern "C" int subtract(int, int);

int main()
{
    cout << my_add(1,1)<<endl;
    //printf("1+1 = %d\n", my_add(1,1));
    //printf("1-1 = %d\n", subtract(1,1));

    return 0;
}