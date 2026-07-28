#include <iostream>
using namespace std;

void test() noexcept
{
    throw runtime_error("Error");
}

int main()
{
    test();
}