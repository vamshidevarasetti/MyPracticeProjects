#include <iostream>
using namespace std;

int main(){
    int a = 70;
    int *p = &a;

    char *pc = reinterpret_cast<char*>(p);
    cout << *pc <<endl;

    int *pp = reinterpret_cast<int*> (a);
    cout << pp <<endl;

    int lp = reinterpret_cast<long>(pp);
    cout << lp <<endl;

    return 0;
}