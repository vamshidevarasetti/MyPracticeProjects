#include <iostream>
#include <memory>
using namespace std;

class B;

class A{
    public:
    shared_ptr<B> bptr;
    A(){cout << "A constructed"<<endl;}
    ~A(){cout << "A destroyed"<<endl;}
};

class B{
    public:
    weak_ptr<A> aptr;
    B(){cout << "B constructed"<<endl;}
    ~B(){cout << "B destroyed"<<endl;}
};

int main(){
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->bptr = b;
    b->aptr = a;

    cout<<a.use_count()<<endl;
    cout<<b.use_count()<<endl;

    return 0;

}