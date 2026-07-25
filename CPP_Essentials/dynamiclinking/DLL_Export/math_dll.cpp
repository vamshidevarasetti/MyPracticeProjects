#include <iostream>

#define DLL_EXPORT extern "C" __declspec(dllexport)

DLL_EXPORT int my_add(int a, int b)
{
    return a + b;
}

DLL_EXPORT int my_subtract(int a, int b)
{
    return a - b;
}