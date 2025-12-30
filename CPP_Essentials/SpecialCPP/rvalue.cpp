#include <iostream>

using namespace std;

void f(int& f) {cout<<"lvalue "<<endl;}
void f(const int& f) {cout<<"const lvalue "<<endl;}
//void f(int&& f) {cout<<"const rvalue "<<endl;}

int main(){

    int i =10;
    f(i);
    f(10);
    f(move(i));
    f(static_cast<int&&>(i));

    return 0;
}