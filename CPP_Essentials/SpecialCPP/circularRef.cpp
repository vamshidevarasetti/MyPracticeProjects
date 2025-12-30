#include <bits/stdc++.h>
using namespace std;

class B; // forward declaration

class A {
    public:
    shared_ptr<B> ptrB;
    ~A() { cout << "A destroyed\n"; }
};

class B {
    public:
    weak_ptr<A> ptrA;  // weak_ptr prevents circular reference
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->ptrB = b;
    b->ptrA = a; // weak_ptr avoids ownership cycle

    cout << "End of main\n";
}


/*#include <bits/stdc++.h>
using namespace std;

struct B;

struct A{
    shared_ptr<B> Bptr;
    ~A(){cout<<"A destroyed";}
};

struct B{
    weak_ptr<A> Aptr;
    ~B(){cout<<"B destroyed";}
};

int main(){

    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->Bptr = b;
    b->Aptr = a;

    return 0;
} */