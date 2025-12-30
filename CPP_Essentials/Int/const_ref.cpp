#include <iostream>
using namespace std;

void print(const int& x) {
    //x++;                // ❌ Illegal: modifying a const reference
    cout << x << endl;
}

int main() {
    int a = 5;
    print(a);
    return 0;
}
