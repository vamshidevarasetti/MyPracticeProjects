#include <iostream>
using namespace std;

int* getPointer() {
    //static int a = 10;
    //return &a;  // ❌ Returning address of a local variable
    int *a = new int(10);
    return a;
    
}
int main(){
    int* p = getPointer();
    cout<<*p<<endl;
    return 0;
}
