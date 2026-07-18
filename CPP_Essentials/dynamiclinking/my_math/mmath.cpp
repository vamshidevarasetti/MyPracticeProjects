#include <iostream>

extern "C" int my_add(int a, int b)
{
    return a+b;
}

extern "C" int subtract(int a, int b)
{
    return a-b;
}