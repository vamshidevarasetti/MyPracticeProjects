#include <iostream>
#include <functional>
using namespace std;

class Multiplier
{
    int factor;

public:

    Multiplier(int f): factor(f){}

    int operator()(int value)
    {
        return value * factor;
    }
};

int main()
{
    function <int(int)> doubleIt = Multiplier(2);
    //Multiplier doubleIt(2);

    cout << doubleIt(10);
}