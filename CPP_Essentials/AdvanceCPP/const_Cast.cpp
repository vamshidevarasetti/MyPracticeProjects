#include <iostream>
using namespace std;
class A{
    int x;
    public:
        void f(int i) const{
            const_cast<A*>(this)->x = i;
            //this->x =i;
      }
      void printx(){
        cout<<"x = "<<x<<endl;
      } 
};

int main()
{
    A a;
    a.printx();
    a.f(10);
    a.printx();

    return 0;
}