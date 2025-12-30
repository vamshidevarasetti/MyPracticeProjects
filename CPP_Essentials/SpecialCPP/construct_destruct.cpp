#include<iostream>
class Base  
{  
    private: 
        virtual void method() { std::cout << "from base -> method" << std::endl; } 
    public: 
        virtual ~Base() { std::cout << "from ~Base" << std::endl; method(); } 
        void baseMethod()  
        {  
            std::cout << "from base -> baseMethod" << std::endl;  
            method(); 
            } 
}; 
 
class A : public Base 
{ 
    void method() { std::cout << "From A -> method" << std::endl; } 
    public : 
        ~A(){ std::cout << "from ~A" << std::endl; method(); } 
        void baseMethod(){  
            std::cout << "from A -> baseMethod" << std::endl;  
            method();  
            }  
}; 

int main(void) 
{  
    Base* base = new A; 
    base->baseMethod(); 
    delete base; 
    return 0;  
} 