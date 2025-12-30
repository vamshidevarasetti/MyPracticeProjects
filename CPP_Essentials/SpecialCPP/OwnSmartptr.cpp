#include <iostream>

using namespace std;

class Test{
    public:
    void Display(){
        cout<<"this is a test class"<<endl;
    }
};

class Smartpointer{
    Test *ptr;

    public:
        Smartpointer(Test* p = nullptr): ptr(p) {};

        ~Smartpointer()
        {
            delete ptr;
        }
        
        Test& operator *(){
            return *ptr;
        }

        Test* operator ->(){
            return ptr;
        }

};

int main(){
    Smartpointer ptr(new Test());
    ptr->Display();
    return 0;
}