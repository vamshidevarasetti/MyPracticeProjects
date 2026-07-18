#include<iostream>
using namespace std;
class A{ 

public: 

virtual void show() = 0; 

}; 

 
 

class B : public A{ 

}; 

 
 

class C:public B{ 

void show() override{cout <<"derived show"<<endl;} 

}; 

int main()
{
    return 0;
}