#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor\n"; }
    ~MyClass() { cout << "Destructor\n"; }
};

int main() {
    MyClass* ptr = new MyClass();
    shared_ptr<MyClass> sp1(ptr);
    //shared_ptr<MyClass> sp2(ptr);
    return 0;
}
