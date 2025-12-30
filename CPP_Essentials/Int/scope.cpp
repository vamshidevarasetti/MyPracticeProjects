#include <iostream>
using namespace std;

int x = 10;  // Global variable

void print() {
    int x = x + 5;  // Local variable 'x' initialized using itself
    cout << x << endl;
}

int main() {
    print();
    return 0;
}