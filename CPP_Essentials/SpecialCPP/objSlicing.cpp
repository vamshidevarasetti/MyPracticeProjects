#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() const {
        cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    void show() const override {
        cout << "Derived class\n";
    }
    void extra() const {
        cout << "Extra functionality\n";
    }
};

int main() {
    Derived d;
    Base b = d;  // ⚠️ Object slicing happens here

    b.show();    // Output: "Base class" — not "Derived class"
    // b.extra(); // ❌ Error: Base doesn't have 'extra'

    return 0;
}
