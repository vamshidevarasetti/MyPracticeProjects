#include <iostream>
#include "math_dll.h"

using namespace std;

int main()
{
    int a = 20;
    int b = 10;

    cout << "Addition = " << my_add(a, b) << endl;
    cout << "Subtraction = " << my_subtract(a, b) << endl;

    return 0;
}