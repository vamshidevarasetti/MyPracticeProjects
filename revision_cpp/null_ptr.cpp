#include <iostream>
#include <cstddef>
using namespace std;

void test(int)
{
    cout << "Integer\n";
}

void test(int*)
{
    cout << "Pointer\n";
}

int main()
{
    test(nullptr);

    int* p = nullptr;

    cout << "Pointer value: " << !p << endl;

    if (!p)
        cout << "Null\n";
}