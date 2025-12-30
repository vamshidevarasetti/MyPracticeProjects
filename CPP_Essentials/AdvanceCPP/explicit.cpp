#include <iostream>
using namespace std;

class Meter {
public:
    int value;
    int count;
    // Constructor
    Meter(int m, int c) { 
        value = m;
        count =c;
    }
    // Function to print the value
    void print() {
        cout << "Value: " << value << " meters" << endl;
        cout << "count: " << count << " counts" << endl;
    }
};

int main() {
    Meter obj(10,20);  // 10 is automatically converted to Meter object
    obj.print();     // prints the value stored in the object
    return 0;
}
