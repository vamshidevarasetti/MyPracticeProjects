
#include <iostream>

extern "C" int my_add_cpp(int a, int b)
{
    return a+b;
}

extern "C" int my_subtract_cpp(int a, int b)
{
    return a-b;
}